#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        forn (i, n) {
            if (s[i] == 'W') {
                ans++;
                if (i && s[i - 1] == 'W') {
                    ans++;
                }
            }
        }
        vector<int> g;
        int len = 0;
        int sum = 0;
        forn (i, n) {
            if (s[i] == 'L') {
                len++;
                sum++;
            } else {
                if (len) {
                    g.push_back(len);
                }
                len = 0;
            }
        }
        if (sum == n) {
            cout << max(0ll, k * 2 - 1) << endl;
            continue;
        }
        if (s[0] == 'L' && g.size()) {
            reverse(g.begin(), g.end());
            g.pop_back();
        }
        ans += min(k, sum) * 2;
        sort(g.begin(), g.end());
        forn (i, g.size()) {
            if (k >= g[i]) {
                k -= g[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
}