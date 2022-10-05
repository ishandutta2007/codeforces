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
vector<int> fac, invfac;
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
int cnk(int n, int k) {
   // cout << n << ' ' << k << ' ' << fac[n] * invfac[n-k] % mod * invfac[k] % mod << endl;
    return fac[n] * invfac[n-k] % mod * invfac[k] % mod;
}
void solve() {
    int n, m, k;
    int xc, yc;
    cin >> yc >> xc;//xc = n - m
    n = xc + yc;m = yc;k=1;
    int inv2 = inv(2);
    //cin >> n >> m >> k;
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
void solvest() {
    int n, m, k = 1;
    int inv2 = inv(2);
    cin >> n >> m >> k;
    if (n == m) {
        cout << n * k % mod << '\n';
        return;
    }
    int crx = n - m, cry = m;
    int res = 0;
    for (int i = m; i >= 1; --i) {
        int cn = cnk(crx + cry - i - 1, crx - 1);
        res += cn * pw(inv2, crx + cry - i) % mod * i % mod;
    }
    cout << res % mod * k % mod << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int pp = 1e6 + 5;
    fac.assign(pp, 1);
    invfac.assign(pp, 1);
    for (int i = 1; i < pp; ++i) {
        fac[i] = fac[i-1] * i % mod;
        invfac[i] = inv(fac[i]);
    }
    int n;
    //cout << (1 * inv(4) + 2 * inv(2) + 3 * inv(1)) % mod;
    cin >> n;
    while (n--) solvest();
}
/*
3
2 2 1
3 2 1
4 2 1
 */