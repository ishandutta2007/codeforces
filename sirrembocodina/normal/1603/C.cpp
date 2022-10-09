#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int mod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        forn (i, n) {
            cin >> a[i];
        }
        vector<pair<int, int>> lim(1);
        lim.back() = {1000000000, 1};
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            forn (j, lim.size()) {
                int x = lim[j].first, cnt = lim[j].second;
                int cur = (a[i] + x - 1) / x;
                ans += (cur - 1) * cnt * (i + 1);
                lim[j].first = a[i] / cur;
            }
            ans %= mod;
            if (i == 0) {
                break;
            }
            vector<pair<int, int>> new_lim;
            forn (j, lim.size()) {
                if (j == 0 || lim[j].first != lim[j - 1].first) {
                    new_lim.push_back(lim[j]);
                } else {
                    new_lim.back().second += lim[j].second;
                }
            }
            new_lim.push_back({1000000000, 1});
            lim = new_lim;
        }
        cout << ans << '\n';
    }
    return 0;
}