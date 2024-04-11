#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll fac[MAXN], ifac[MAXN], sum[MAXN], f[MAXN], g[MAXN];

ll mpow(ll b, ll e) {
    if(e == 0) return 1;
    if(e % 2) return (b * mpow(b, e - 1))%MOD;
    ll p = mpow(b, e/2);
    return (p * p)%MOD; 
}

ll inv(ll b) { return mpow(b, MOD - 2); }

int main() {
    fac[0] = 1;
    for(ll n = 1; n < MAXN; n++)
        fac[n] = (fac[n - 1]*n)%MOD;
    ifac[MAXN - 1] = inv(fac[MAXN - 1]);
    for(ll n = MAXN - 1; n >= 1; n--)
        ifac[n - 1] = (ifac[n] * n)%MOD;
    ll n, k;
    cin >> n >> k;
    for(ll m = k + 1; m <= n; m++) {
        f[m] = (fac[m - 1]*(sum[m - 1] - sum[k - 1]))%MOD;
        if(f[m] < 0)
            f[m] += MOD;
        g[m] = (f[m] + fac[m - 1]*(m - k - sum[m - k - 1]))%MOD;
        if(g[m] < 0)
            g[m] += MOD;
        sum[m] = (sum[m - 1] + g[m]*ifac[m])%MOD;
    }
    cout << f[n] << '\n';
}