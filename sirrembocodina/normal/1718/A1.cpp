#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> dp(n + 1);
        map<int, int> w;
        w[0] = 0;
        dp[0] = 0;
        int x = 0;
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + 1;
            x ^= a[i];
            if (w.find(x) != w.end()) {
                int j = w[x];
                dp[i + 1] = min(dp[i + 1], dp[j] + i - j);
            }
            w[x] = i + 1;
        }
        cout << dp[n] << '\n';
    }
}