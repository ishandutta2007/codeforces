#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;
const ll mod = (ll)1e9 + 7;

int n, m;
ll dp[N], psum[N];
ll fac[N], facinv[N];
ll inv[N];
ll pwm[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}


int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> n >> m;
    pwm[0] = 1;
    for(int i = 1; i < N; i++) pwm[i] = pwm[i-1] * m % mod;

    dp[1] = m;
    psum[1] = m;
    ll cur = 1, cursum = m;
    for(int i = 2; i <= n; i++) {
        dp[i] = m * (cursum) % mod + pwm[i];
        dp[i] -= m * cur;
        dp[i] %= mod;

        cursum *= m;
        cursum %= mod;
        cursum += dp[i];
        cursum %= mod;

        cur *= m;
        cur %= mod;
        cur += dp[i] * inv[m];
        cur %= mod;
    }
    ll res = cursum;
    ll pw = 1;
    for(int i = 0; i < n; i++) pw *= m, pw %= mod;
    res += pw;
    cout << (res % mod + mod) % mod << endl;

}