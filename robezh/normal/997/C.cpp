#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 500, mod = 998244353;
typedef long long ll;

int n;
ll pw2[N],pw3[N], fac[N], facinv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf*hf%mod*x%mod : hf*hf%mod;
}

ll C(int n, int i){
    return fac[n]*facinv[i]%mod*facinv[n-i];
}

int main(){
    pw3[0] = pw2[0] = 1;
    for(int i = 1; i < N; i++) pw3[i] = 3 * pw3[i-1] % mod, pw2[i] = 2 * pw2[i-1] % mod;

    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod-2);
    for(int i = N-2; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    cin >> n;
    ll res = 0;
    for(int i = 1; i <= n; i++){
        res += 2 * C(n, i) * (i%2?1:-1) % mod * pw3[i]%mod * fp(3, (1LL*n*(n-i)));
        res %= mod;
    }
    for(int i = 0; i <= n-1; i++){
        res += C(n,i)*3%mod*(i%2?1:-1)%mod*(fp(1-pw3[i], n) - fp(-pw3[i], n)) % mod;
        res %= mod;
    }
    res = (res + mod) % mod;
    cout << res;

}