#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50, mod = (int)1e9 + 7;


int n,m;
ll pw[N], pwm[N];
ll fac[N], facinv[N];
ll inv[N];


ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll get_inv(ll x) {
    return fp(x, mod - 2);
}

ll invn;

ll f(ll n, ll k) {
    return k * pw[n - k] % mod * invn % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll get_split(int sum, int k) {
    return comb(sum - 1, k - 1);
}

ll permu(int n, int k) {
    return fac[n] * facinv[n - k] % mod;
}

int main() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> n >> m;
    invn = get_inv(n);



    pw[0] = 1, pwm[0] = 1;
    for(int i = 1; i < N; i++) {
        pw[i] = pw[i-1] * n % mod;
        pwm[i] = pwm[i-1] * m % mod;
    }

    ll res = 0;
    for(int i = 0; i <= min(m - 1, n - 2); i++) {
        int k = i + 1;
        res += permu(n - 2, i) * get_split(m, k) % mod * f(n, i + 2) % mod * pwm[n - i - 2] % mod;
        res %= mod;
    }
    cout << res << endl;


}