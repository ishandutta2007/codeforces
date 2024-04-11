#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int MOD = 1e9 + 7;

const int M = 1e6;

vector<vector<int>> dp;

void precalc() {
    int m = M;
    dp.assign(10, vector<int>(m + 10, 0));
    // for (auto i : n) {
    //     dp[i - '0'][0]++;
    // }
    for (int i = 0; i < 10; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < 9; ++j) {
            dp[j][i] = dp[j + 1][i - 1];
        }
        dp[9][i] = dp[1][i - 1] + dp[0][i - 1];
        dp[9][i] %= MOD;
    }
}

void solve() {
    string n;
    int m;
    cin >> n >> m;
    int ans = 0;
    for (auto i : n) {
        ans += dp[i - '0'][m];
        ans %= MOD;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    precalc();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}