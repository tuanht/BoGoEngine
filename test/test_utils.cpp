/*

  This file is a part of BoGoEngine project.

  Copyright (C) 2012 Dương "Yang" ヤン Nguyễn <cmpitg@gmail.com>

  BoGoEngine is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  BoGoEngine is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with BoGoEngine.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <gtest/gtest.h>
#include <iostream>
#include <engine.hpp>

using namespace std;
using namespace Glib;
using namespace BoGo;

#define _(s) (ustring ("") + s)
#define __(s) (ustring ("") + s).c_str ()

vector<ustring> makeustringVec3 (const gchar *e0,
                                 const gchar *e1,
                                 const gchar *e2) {
    vector<ustring> v(3);
    v[0] = _(e0);
    v[1] = _(e1);
    v[2] = _(e2);
    return v;
}

TEST (TestItself, TestHelpers) {
    vector<ustring> s1 = makeustringVec3("aoeu", "xin chào", "Thế Giới!");
    EXPECT_TRUE (s1 == s1);
}

TEST (WordHelpers, WordSeparator) {
    EXPECT_TRUE (makeustringVec3 ("ng", "oa", "n") ==
                 analyseWord ("ngoan"));
    EXPECT_TRUE (makeustringVec3 ("tr", "ườ", "ng") ==
                 analyseWord ("trường"));
    EXPECT_TRUE (makeustringVec3 ("", "Oạ", "cH") ==
                 analyseWord ("OạcH"));
    EXPECT_TRUE (makeustringVec3 ("Th", "ề", "") ==
                 analyseWord ("Thề"));
    EXPECT_TRUE (makeustringVec3 ("", "uI", "") ==
                 analyseWord ("uI"));
    EXPECT_TRUE (makeustringVec3 ("", "oa", "") ==
                 analyseWord ("oa"));
    EXPECT_TRUE (makeustringVec3 ("qU", "a", "N") ==
                 analyseWord ("qUaN"));
    EXPECT_TRUE (makeustringVec3 ("Gi", "Áo", "") ==
                 analyseWord ("GiÁo"));
}

TEST (CharacterHelpers, ConsonantsAndVowels) {
    EXPECT_TRUE (isVowel ("Â"));
    EXPECT_FALSE (isConsonant ("à"));
    EXPECT_TRUE (isVowel ("Ă"));
    EXPECT_TRUE (isConsonant ("C"));
    EXPECT_TRUE (isConsonant (" "));
    EXPECT_FALSE (isVowel ("Đ"));
    EXPECT_TRUE (isVowel ("Ế"));
}

TEST (CharacterHelpers, CharacterCases) {
    EXPECT_TRUE (isUpperCase ("Â"));
    EXPECT_TRUE (isUpperCase ("À"));
    EXPECT_TRUE (isUpperCase ("Ă"));
    EXPECT_TRUE (isUpperCase ("Â"));
    EXPECT_TRUE (isUpperCase ("B"));
    EXPECT_TRUE (isUpperCase ("C"));
    EXPECT_TRUE (isUpperCase ("D"));
    EXPECT_TRUE (isUpperCase ("Đ"));
    EXPECT_TRUE (isUpperCase ("E"));
    EXPECT_TRUE (isUpperCase ("Ế"));
    EXPECT_TRUE (isUpperCase ("G"));
    EXPECT_TRUE (isUpperCase ("H"));
    EXPECT_TRUE (isUpperCase ("I"));
    EXPECT_TRUE (isUpperCase ("K"));
    EXPECT_TRUE (isUpperCase ("L"));
    EXPECT_TRUE (isUpperCase ("M"));
    EXPECT_TRUE (isUpperCase ("N"));
    EXPECT_TRUE (isUpperCase ("O"));
    EXPECT_TRUE (isUpperCase ("Ô"));
    EXPECT_TRUE (isUpperCase ("Ơ"));
    EXPECT_TRUE (isUpperCase ("P"));
    EXPECT_TRUE (isUpperCase ("Q"));
    EXPECT_TRUE (isUpperCase ("R"));
    EXPECT_TRUE (isUpperCase ("S"));
    EXPECT_TRUE (isUpperCase ("T"));
    EXPECT_TRUE (isUpperCase ("U"));
    EXPECT_TRUE (isUpperCase ("Ư"));
    EXPECT_TRUE (isUpperCase ("V"));
    EXPECT_TRUE (isUpperCase ("X"));
    EXPECT_TRUE (isUpperCase ("Y"));

    EXPECT_FALSE (isUpperCase ("a"));
    EXPECT_FALSE (isUpperCase ("ă"));
    EXPECT_FALSE (isUpperCase ("ậ"));
    EXPECT_FALSE (isUpperCase ("b"));
    EXPECT_FALSE (isUpperCase ("c"));
    EXPECT_FALSE (isUpperCase ("d"));
    EXPECT_FALSE (isUpperCase ("đ"));
    EXPECT_FALSE (isUpperCase ("ẻ"));
    EXPECT_FALSE (isUpperCase ("ê"));
    EXPECT_FALSE (isUpperCase ("g"));
    EXPECT_FALSE (isUpperCase ("h"));
    EXPECT_FALSE (isUpperCase ("i"));
    EXPECT_FALSE (isUpperCase ("k"));
    EXPECT_FALSE (isUpperCase ("l"));
    EXPECT_FALSE (isUpperCase ("m"));
    EXPECT_FALSE (isUpperCase ("n"));
    EXPECT_FALSE (isUpperCase ("o"));
    EXPECT_FALSE (isUpperCase ("ỗ"));
    EXPECT_FALSE (isUpperCase ("ơ"));
    EXPECT_FALSE (isUpperCase ("p"));
    EXPECT_FALSE (isUpperCase ("q"));
    EXPECT_FALSE (isUpperCase ("r"));
    EXPECT_FALSE (isUpperCase ("s"));
    EXPECT_FALSE (isUpperCase ("t"));
    EXPECT_FALSE (isUpperCase ("u"));
    EXPECT_FALSE (isUpperCase ("ư"));
    EXPECT_FALSE (isUpperCase ("v"));
    EXPECT_FALSE (isUpperCase ("x"));
    EXPECT_FALSE (isUpperCase ("y"));
}

TEST (WordHelpers, Other) {
    EXPECT_FALSE (isWordBreak ((gchar) 8));
    EXPECT_TRUE (isWordBreak ("1"));
    EXPECT_TRUE (isWordBreak ((gchar) 13));
    EXPECT_FALSE (isWordBreak ("â"));
    EXPECT_FALSE (isWordBreak ("â"));
}

TEST (CharacterHelpers, AccentsAndTransform) {
    EXPECT_STREQ (__("ô"), removeAccentFromChar ("ố").c_str ());
    EXPECT_STREQ (__("ô"), removeAccentFromChar ("ổ").c_str ());
    EXPECT_STREQ (__("Ô"), removeAccentFromChar ("Ỗ").c_str ());
    EXPECT_STREQ (__("ô"), removeAccentFromChar ("ộ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ầ").c_str ());
    EXPECT_STREQ (__("Â"), removeAccentFromChar ("Ấ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ẩ").c_str ());
    EXPECT_STREQ (__("Â"), removeAccentFromChar ("Ẫ").c_str ());
    EXPECT_STREQ (__("â"), removeAccentFromChar ("ậ").c_str ());

    EXPECT_STREQ (__("a"), toPlainLetter ("â").c_str ());
    EXPECT_STREQ (__("a"), toPlainLetter ("ắ").c_str ());
    EXPECT_STREQ (__("N"), toPlainLetter ("N").c_str ());
    EXPECT_STREQ (__("O"), toPlainLetter ("Ộ").c_str ());
    EXPECT_STREQ (__("E"), toPlainLetter ("Ễ").c_str ());

    EXPECT_EQ (0, getAccentFromChar ("ồ"));
    EXPECT_EQ (1, getAccentFromChar ("Ứ"));
    EXPECT_EQ (2, getAccentFromChar ("Ể"));
    EXPECT_EQ (3, getAccentFromChar ("ẵ"));
    EXPECT_EQ (4, getAccentFromChar ("ị"));
    EXPECT_EQ (5, getAccentFromChar ("n"));

    EXPECT_STREQ (__("á"), addAccentToChar ("a", ACUTE).c_str ());
    EXPECT_STREQ (__("ặ"), addAccentToChar ("ă", DOT).c_str ());
    EXPECT_STREQ (__("Ổ"), addAccentToChar ("Ô", HOOK).c_str ());
    EXPECT_STREQ (__("n"), addAccentToChar ("n", DOT).c_str ());
    EXPECT_STREQ (__("Ễ"), addAccentToChar ("Ê", TILDE).c_str ());
}

TEST (CharacterHelpers, PlainCharacters) {
    EXPECT_TRUE (isLetter ("n"));
    EXPECT_TRUE (isLetter ("ọ"));
    EXPECT_TRUE (isLetter ("ổ"));
    EXPECT_TRUE (isLetter ("Ầ"));
    EXPECT_TRUE (isLetter ("Ẩ"));
    EXPECT_TRUE (isLetter ("á"));
    EXPECT_TRUE (isLetter ("Ả"));
    EXPECT_TRUE (isLetter ("T"));
    EXPECT_TRUE (isLetter ("b"));
    EXPECT_TRUE (isLetter ("a"));
    EXPECT_TRUE (isLetter ("g"));
    EXPECT_TRUE (isLetter ("o"));
    EXPECT_TRUE (isLetter ("t"));
    EXPECT_TRUE (isLetter ("s"));
    EXPECT_TRUE (isLetter ("e"));
    EXPECT_FALSE (isLetter ("7"));
    EXPECT_FALSE (isLetter ("5"));
    EXPECT_FALSE (isLetter ("2"));
    EXPECT_FALSE (isLetter ("1"));
    EXPECT_FALSE (isLetter ("6"));
    EXPECT_TRUE (isLetter ("S"));
    EXPECT_TRUE (isLetter ("A"));
    EXPECT_TRUE (isLetter ("T"));
    EXPECT_TRUE (isLetter ("O"));
    EXPECT_FALSE (isLetter ("\\"));
    EXPECT_FALSE (isLetter ((gchar) 13)); // Return
}

int main (int argc, char *argv[]) {
    testing::InitGoogleTest (&argc, argv);
    int dummyVal = RUN_ALL_TESTS ();

    return 0;
}
