#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
#include "iomanip"
using namespace std;
const int INF = 1e9 + 179;
#define all(x) x.begin(), x.end()
#define int long long
int mod = 1e9 + 7;
int pw(int a, int b) {
    int res = 1;
    while (b != 0) {
        if (b % 2)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int inv(int x) {
    return pw(x, mod - 2);
}
void solve() {
    int n, m, k;
    int inv2 = inv(2);
    cin >> n >> m >> k;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= m; ++i) {
        dp[i][i] = i;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= min(i-1, m); ++j) {
            dp[i][j] = inv2 * (dp[i-1][j] + dp[i-1][j-1]) % mod;
            //cout << dp[i][j] << ' ' << i << ' ' << j << endl;
        }
    }
    cout << dp[n][m] * k % mod << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) solve();
}