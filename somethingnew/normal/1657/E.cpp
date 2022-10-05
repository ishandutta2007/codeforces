#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
int mod = 998244353;
int pw(int a, int b) {
    if (b == -1)
        return 0;
    int res = 1;
    while (b) {
        if (b % 2)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int inv(int a) {
    return pw(a, mod - 2);
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> fac(n + 12), invfac = fac;
    fac[0] = 1;
    invfac[0] = 1;
    for (int i = 1; i < fac.size(); ++i) {
        fac[i] = fac[i - 1] * i % mod;
        invfac[i] = inv(fac[i]);
    }
    n--;
    vector<vector<int>> dp(n+1, vector<int>(k + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            int tomult = 1;
            for (int l = i; l <= n; ++l) {
                dp[l][j + 1] += dp[i][j] * tomult % mod * invfac[l-i];
                dp[l][j + 1] %= mod;
                tomult *= pw(j+1, n-l-1);
                tomult %= mod;
            }
        }
    }
    cout << dp[n][k] * fac[n] % mod << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}