#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    string s;
    int n, m;
    bool ok;
    cin >> s >> m;
    for (int i = 0; i < m; i++)
        s += "@";
    n = s.length();
    for (int len = n - n % 2; len >= 0; len -= 2) {
        for (int i = 0; i <= n - len; i++) {
            ok = true;
            for (int j = i; j < i + len / 2; j++)
                if (s[j] != '@' && s[j + len / 2] != '@' && s[j] != s[j + len / 2])
                    ok = false;
            if (ok) {
                cout << len;
                return 0;
            }
        }
    }
}