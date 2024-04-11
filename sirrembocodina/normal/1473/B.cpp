#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size();
        int d = __gcd(n, m);
        bool bad = false;
        for (int i = 0; i < n; i++) {
            if (s[i] != s[i % d]) {
                bad = true;
            }
        }
        for (int i = 0; i < m; i++) {
            if (t[i] != t[i % d]) {
                bad = true;
            }
        }
        for (int i = 0; i < d; i++) {
            if (s[i] != t[i]) {
                bad = true;
            }
        }
        if (bad) {
            cout << -1 << endl;
            continue;
        }
        int l = n * m / d;
        for (int i = 0; i < l; i++) {
            cout << s[i % d];
        }
        cout << endl;
    }
}