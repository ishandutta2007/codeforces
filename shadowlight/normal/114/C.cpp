#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    //freopen("c.in", "r", stdin);
    //freopen("c.out", "w", stdout);
    int f = 0, f1 = 0;
    string str, s = "";
    getline(cin, str);
    int qual1 = -1;
    int qual2 = -1;
    int now_qual1 = 1;
    int now_qual2 = -1;
    str += ' ';
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            qual1 = -1;
            qual2 = -1;
            if (s.size() >= 4 && s.substr(s.size() - 4, 4) == "lios") {
                qual1 = 1;
                qual2 = 1;
            } else if (s.size() >= 5 && s.substr(s.size() - 5, 5) == "liala") {
                qual1 = 1;
                qual2 = 2;
            } else if (s.size() >= 3 && s.substr(s.size() - 3, 3) == "etr") {
                qual1 = 2;
                qual2 = 1;
            } else if (s.size() >= 4 && s.substr(s.size() - 4, 4) == "etra") {
                qual1 = 2;
                qual2 = 2;
            } else if (s.size() >= 6 && s.substr(s.size() - 6, 6) == "initis") {
                qual1 = 3;
                qual2 = 1;
            } else if (s.size() >= 6 && s.substr(s.size() - 6, 6) == "inites") {
                qual1 = 3;
                qual2 = 2;
            } else {
                cout << "NO";
                return 0;
            }
            if (now_qual2 == -1) {
                now_qual2 = qual2;
            } else if (now_qual2 != qual2) {
                cout << "NO";
                return 0;
            }
            if (qual1 == 2 && now_qual1 == 1) {
                now_qual1 = 3;
                f1 = 1;
            } else if (qual1 != now_qual1 && f > 0) {
                cout << "NO";
                return 0;
            } else if (qual1 != now_qual1) {
                now_qual1 = 4;
            }
            f++;
            s = "";
        } else s += str[i];
    }
    if (!f1 && f != 1) {
        cout << "NO";
    } else
    cout << "YES";
}