#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105;
const ll mod = (ll)1e9 + 7;

int n;
ll f[N], s;
ll fac[N], facinv[N];
ll inv[N];

ll comb(ll n, ll k) {
    ll res = 1;
    for(ll i = n; i > n - k; i--) res = (res * (i % mod)) % mod;
    res = (res * facinv[k]) % mod;
    return res;

}

ll stb(ll sum, ll k) {
    if(sum < 0) return 0;
    return comb(sum + k - 1, k - 1);
}

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> f[i];
    ll res = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        int sig = 1;
        ll csum = s;
        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) {
                sig *= -1;
                csum -= f[i] + 1;
            }
        }
        res += sig * stb(csum, n) % mod;
        res %= mod;
    }
    cout << (res % mod + mod) % mod << endl;
}