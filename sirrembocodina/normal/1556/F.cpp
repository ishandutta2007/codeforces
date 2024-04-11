#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int mod = 1e9 + 7;

int bin_pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = bin_pow(a, b / 2);
    res *= res;
    res %= mod;
    if (b % 2) {
        res *= a;
        res %= mod;
    }
    return res;
}

int inv(int a) {
    return bin_pow(a, mod - 2);
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) {
        cin >> x;
    }
    vector<vector<int>> g(n, vector<int>(n));
    //vector<vector<int>> inv_g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = a[i] * inv(a[i] + a[j]) % mod;
            //inv_g[i][j] = inv(g[i][j]);
        }
    }
    vector<vector<int>> lto(n, vector<int>(1 << n));
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            lto[i][mask] = 1;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    (lto[i][mask] *= g[j][i]) %= mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> dp(1 << (n - 1), 1);
        for (int mask = 1; mask < (1 << (n - 1)); mask++) {
            int submask = mask;
            while (true) {
                submask--;
                submask &= mask;
                int antimask = 0;
                for (int j = 0; j < n - 1; j++) {
                    if (!(submask & (1 << j)) && (mask & (1 << j))) {
                        antimask |= 1 << (j + (j >= i));
                    }
                }
                int cap = lto[i][antimask];
                for (int j = 0; j < n - 1; j++) {
                    if (submask & (1 << j)) {
                        (cap *= lto[j + (j >= i)][antimask]) %= mod;
                    }
                }
                dp[mask] += mod - dp[submask] * cap % mod;
                if (submask == 0) {
                    break;
                }
            }
            dp[mask] %= mod;
        }
        (ans += dp[(1 << (n - 1)) - 1]) %= mod;
    }
    cout << ans;
    return 0;
}