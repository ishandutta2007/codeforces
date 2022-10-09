#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int mod = 1e9 + 7;

int32_t main() {
    __int128 t;
    ios_base::sync_with_stdio(0);
    int max_n = 2000;
    int half = 5e8 + 4;
    vector<vector<int>> dp(max_n + 1, vector<int>(max_n + 1));
    forn (i, max_n + 1) {
        dp[i][0] = 0;
        dp[i][i] = i;
    }
    for (int i = 2; i <= max_n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) * half % mod;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << dp[n][m] * k % mod << '\n';
    }
    return 0;
}