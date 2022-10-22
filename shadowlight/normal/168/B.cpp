#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    //freopen("c.in", "r", stdin);
    //freopen("c.out", "w", stdout);
    bool fl = 0;
    string s, str = "$";
    while (getline(cin, s)) {
        int i;
        for (i = 0; i < s.size(); i++) {
            if (s[i] != ' ') break;
        }
        if (i != s.size() && s[i] == '#') {
            if (str == "$") cout << s << endl; else if (!fl) cout << s << endl; else cout << str << endl << s << endl;
            str.clear();
            fl = 0;
        } else {
            if (str == "$") {
                str.clear();
            }
            string new_s = "";
            new_s.clear();
            for (int j = 0; j < s.size(); j++) {
                if (s[j] != ' ') new_s += s[j];
            }
            fl = 1;
            str += new_s;
        }
    }
    if (!fl) return 0;
    cout << str << endl;
}