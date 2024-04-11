#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 20050;
const ll mod = 998244353;

ll fac[M], facinv[M];
ll pw2[M], pw2inv[M];
ll inv[M];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

void init_fac_inv(){
    inv[1] = 1;
    for(int i = 2; i < M; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= M-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[M-1] = fp(fac[M-1], mod - 2);
    for(int i = M-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
    pw2[0] = 1;
    for(int i = 1; i < M; i++) pw2[i] = pw2[i-1] * 2 % mod;
    pw2inv[M-1] = fp(pw2[M-1], mod - 2);
    for(int i = M - 2; i >= 0; i--) pw2inv[i] = pw2inv[i+1] * 2 % mod;
}

ll get_classic(int p, int s) {
    if(p == 0) return s == 0 ? 1 : 0;
    return comb(s + p - 1, p - 1);
}

ll solve(int p, int s, int ub) {
    ll res = 0;
    for(int t = 0; t * ub <= s && t <= p; t++) {
        ll sign = (t & 1) ? -1 : 1;
        res += sign * comb(p, t) * get_classic(p, s - t * ub);
        res %= mod;
    }
    return res;
}

int main(){
    init_fac_inv();
    int p, s, r;

    cin >> p >> s >> r;
    ll win = 0, tot = comb(s - r + p - 1, p - 1);
    for(int score = r; score <= s; score++) {
        for(int t = 1; t * score <= s && t <= p; t++){
            int rem_p = p - t;
            int rem_s = s - t * score;
            int ub = score;
            ll cur = comb(p - 1, t - 1) * solve(rem_p, rem_s, ub) % mod;
            win = (win + cur * inv[t] % mod) % mod;
        }
    }
    ll res = win * fp(tot, mod - 2) % mod;
    cout << res << endl;
}