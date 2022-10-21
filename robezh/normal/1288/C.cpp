/**
 * Author:
 * Date:
 * License:
 * Source:
 * Description:
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;
const ll mod = (ll)1e9 + 7;

int n, m, num[N];
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

ll psum[N];


int main(){
    init_fac();

    cin >> m >> n;
    ll res = 0;
    for(int i = 1; i <= m; i++) {
        psum[i] = (psum[i-1] + (n == 1 ? 1 : comb(i - 1 + n - 1, n - 1))) % mod;
        if(n == 1) res += psum[i], res %= mod;
        else res += psum[i] * comb(m - i + n - 1, n - 1) % mod, res %= mod;

//        cout << i << ": " << res << endl;
    }
    cout << res << endl;

}