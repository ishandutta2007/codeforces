#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;
ll mod;

int n;
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


int main(){
    cin >> n >> mod;
    init_fac();

    ll res = 0;
    for(int len = 1; len <= n; len++) {
        res += 1LL * (n - len + 1) * (n - len + 1) % mod * fac[len] % mod * fac[n - len] % mod;
        res %= mod;
    }
    cout << res << '\n';
}