#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = "";
    bool fl = 0;
    for (int i = 0; i < n; i++) {
        if (!fl && s[i] == 'o') {
            fl = 1;
            continue;
        }
        if (fl) {
            fl = 0;
            bool fl1 = 0;
            while (i < n - 1 && s[i] == 'g' && s[i + 1] == 'o') {
                i += 2;
                fl1 = 1;
            }
            if (!fl1) {
                s1 += 'o';
            } else {
                s1 += "***";
            }
        }
        if (i < n) {
            if (s[i] == 'o') {
                fl = 1;
                continue;
            }
            s1 += s[i];
        }
    }
    if (fl) s1 += 'o';
    cout << s1;
}