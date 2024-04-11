#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;
const ll mod = (int)1e9 + 7;

int n, num[N];
ll fac[N], facinv[N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(ll n, ll k){
    if(n < 0) return 0;
    if(k < 0 || k > n) return 0;
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}


int f, w, h;

int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> f >> w >> h;
    if(w == 0) return cout << 1 << endl, 0;
    ll res = 0, all = 0;
    for(int i = 1; i <= f + 1; i++) {
        res += comb(f + 1, i) * comb(w - 1LL * i * h - 1, i - 1) % mod;
        all += comb(f + 1, i) * comb(w - 1, i - 1) % mod;
    }
    res %= mod, all %= mod;
    cout << res * fp(all, mod - 2) % mod << endl;

}