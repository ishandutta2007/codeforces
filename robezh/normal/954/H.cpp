#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5005;
const int mod = (int)1e9 + 7;

int n, a[N];
ll fac[N], facinv[N];
int dp[N][2*N];
ll res[2*N];
ll inv2;

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

int get(int d, int k) {
    if(dp[d][k] != -1) return dp[d][k];
    if(k == 0) return dp[d][k] = 1;
    dp[d][k] = 0;
    if(k + d < n) dp[d][k] = (int)((a[d+1] - 1) * fac[k + d] % mod * facinv[d+1] % mod);
    if(d > 0) dp[d][k] = (dp[d][k] + get(d - 1, k - 1)) % mod;
    return dp[d][k];
}

int main() {
    cin >> n;
    for(int i = 1; i < n; i++) cin >> a[i];
    fac[0] = 1;
    for(int i = 1; i < n; i++) fac[i] = fac[i-1] * a[i] % mod;
    facinv[n-1] = fp(fac[n-1], mod - 2);
    for(int i = n - 2; i >= 0; i--) facinv[i] = facinv[i+1] * a[i+1] % mod;
    inv2 = fp(2, mod - 2);

    for(int i = 0; i < n; i++) {
        for(int k = 1; i + k < n; k++) {
            res[k] = (res[k] + fac[i + k]) % mod;
        }
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i < n; i++) {
        for(int k = 1; k <= 2 * n - 2; k++) {
            res[k] = (res[k] + fac[i] * get(i-1, k-1)) % mod;
        }
    }
    for(int i = 1; i <= 2 * n - 2; i++) {
        cout << res[i] * inv2 % mod << " ";
    }
}