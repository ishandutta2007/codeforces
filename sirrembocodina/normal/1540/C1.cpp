#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int mod = 1e9 + 7;

int32_t main() {
    int n;
    cin >> n;
    vector<int> c(n);
    forn (i, n) {
        cin >> c[i];
    }
    vector<int> b(n - 1);
    forn (i, n - 1) {
        cin >> b[i];
    }
    vector<int> bsum(n);
    forn (i, n - 1) {
        bsum[i + 1] = bsum[i] + b[i];
    }
    int q;
    cin >> q;
    int x;
    cin >> x;
    vector<int> a(n);
    int cur_a = 0;
    forn (i, n) {
        cur_a += x + bsum[i];
        a[i] = cur_a;
    }
    vector<int> dp(10001, 0);
    dp[0] = 1;
    forn (i, n) {
        vector<int> new_dp(10001, 0);
        forn (sum, 10001) {
            if (!dp[sum]) {
                continue;
            }
            for (int cur = max(0ll, a[i] - sum); cur <= c[i]; cur++) {
                (new_dp[sum + cur] += dp[sum]) %= mod;
            }
        }
        dp = new_dp;
    }
    int ans = 0;
    forn (i, dp.size()) {
        (ans += dp[i]) %= mod;
    }
    cout << ans;
}