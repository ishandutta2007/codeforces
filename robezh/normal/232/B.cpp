#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105;
const ll mod = (ll)1e9 + 7;

int n, k;
ll m;
ll fac[N], facinv[N];
ll ways[N][2];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll dp[N][N*N];

int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> n >> m >> k;
    for(int take = 0; take <= n; take++) {
        for(int i = 0; i < 2; i++) {
            ways[take][i] = fp(comb(n, take), m / n + i);
        }
    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        int pw = (m % n != 0) && (i <= m % n);

        for(int j = 0; j <= n * i; j++) {
            for(int take = 0; take <= min(n, j); take++) {
                dp[i][j] += dp[i-1][j - take] * ways[take][pw] % mod;
                if(dp[i][j] >= mod) dp[i][j] -= mod;
            }
        }
    }
    cout << dp[n][k] << endl;

}