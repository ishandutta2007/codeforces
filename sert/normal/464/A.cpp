#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int n, p, ps;

string s, k;
char ch;
bool fnd;

int main()
{
    //freopen("a.in", "r", stdin);
    cin >> n >> p >> s;

    ///s = "#$" + s;

    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; s[i] + j < 'a' + p; j++) {
            ch = s[i] + j;
            if (ch >= 'a' + p) continue;
            if (i > 0) if (ch == s[i - 1]) continue;
            if (i > 1) if (ch == s[i - 2]) continue;

            s[i] = ch;
            for (int k = i + 1; k < n; k++) {
                fnd = false;
                for (char c = 'a'; c < 'a' + p; c++)
                    if (s[k - 1] != c && s[k - 2] != c) {
                        s[k] = c;
                        fnd = true;
                        break;
                    }
                if (!fnd) {
                    cout << "NO\n";
                    return 0;
                }
            }
            cout << s;
            return 0;
        }

    cout << "NO\n";

    return 0;
}