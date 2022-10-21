#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll mod = (int)1e9 + 7;

int n, num[N];
int m, g;
ll fac[N], facinv[N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    if(k < 0 || k > n) return 0;
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> n >> m >> g;
    ll res = 0;
    if(m >= 1) {
        for(int bef = g; bef < n + m - 1; bef += 2) {
            res += comb(n + m - bef - 1, n - bef);
            res %= mod;
        }
    }
    int zeros = n + m - 1 + ((n + m) % 2 != g), ones = n + m - zeros;
    if(zeros <= n && ones <= m) res = (res + 1) % mod;
    cout << res << endl;
}