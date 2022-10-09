#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int ans = 0;
        vector<string> a;
        forn (i, n) {
            if (s[i] != t[i]) {
                ans += 2;
                continue;
            }
            if (i == 0 || s[i - 1] != t[i - 1]) {
                a.push_back("");
            }
            a.back().push_back(s[i]);
            if (s[i] == '0') {
                ans++;
            }
        }
        for (string x: a) {
            vector<bool> used(x.size());
            forn (i, x.size()) {
                if (x[i] == '0') {
                    continue;
                }
                if (i > 0 && !used[i - 1] && x[i - 1] == '0') {
                    ans++;
                } else if (i + 1 < x.size() && x[i + 1] == '0') {
                    used[i + 1] = true;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}