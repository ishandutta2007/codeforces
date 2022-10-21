#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7, N = 2005;

int n, m;
int dp[N][N], psum[N][N], esum[N][N];
ll fac[N], facinv[N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

void init_fac() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
}

int main() {
    cin >> n >> m;
    for(int j = 2; j <= m; j++) {
        dp[0][j] = 1;
        psum[0][j] = (psum[0][j-1] + dp[0][j]) % mod;
        esum[0][j] = (esum[0][j-1] + psum[0][j]) % mod;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 2; j <= m; j++) {
            dp[i][j] = esum[i-1][j] + 1;
            psum[i][j] = (psum[i][j-1] + dp[i][j]) % mod;
            esum[i][j] = (esum[i][j-1] + psum[i][j]) % mod;
        }
    }
    ll res = 0;
    for(int i = 0; i < n; i++) {
        for(int len = 2; len <= m; len++) {
//            res += 1LL * (m - len + 1) * dp[i][len] % mod * (2 * dp[n - 1 - i][len - 1] - dp[n-1-i][len-2]) % mod;
            res += 1LL * (m - len + 1) * dp[i][len] % mod * (dp[n - 1 - i][len] - (i < n - 1 ? dp[n-1-i-1][len] : 0)) % mod;
//            res += 1LL * (m - len + 1) * dp[i][len] % mod * (dp[n - 1 - i][len]) % mod;
            res %= mod;

        }
    }
    cout << (res % mod + mod) % mod << "\n";




}