#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll mod = (int)1e9 + 7;

ll T;
int t[N];
int n, num[N];
ll fac[N], facinv[N];
ll inv[N], inv2[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}


ll comb(ll n, ll k){
    if(k < 0 || n - k < 0) return 0;
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}


int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
    inv2[N-1] = fp(fp(2, N - 1), mod - 2);
    for(int i = N - 2; i >= 0; i--) inv2[i] = inv2[i+1] * 2 % mod;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> T;
    ll res = 0, sum = 0;
    ll r = n;
    ll val = 1;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        sum += t[i];
        ll nr = min(1LL * r, T - sum);
        int c = i + 1;
        val *= 2;
        val -= comb(c - 1, r), val %= mod;
        while(r >= 0 &&  r > nr) val -= comb(c, r--), val %= mod;
        res = (res + val * inv2[c]) % mod;
    }
    cout << (res % mod + mod) % mod << endl;

}