#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 5e5+7, mod = 998244353;

ll fac[sz], finv[sz], inv[sz];

void prec()
{
    inv[0] = inv[1] = 1;
    for(int i=2; i<sz; i++)
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    fac[0] = finv[0] = 1;
    for(int i=1; i<sz; i++) {
        fac[i] = fac[i-1] * i % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}

ll cmb(int n, int r)
{
    if(n < r || n <= 0) return 0;
    ll d = finv[r] * finv[n-r] % mod;
    return fac[n] * d % mod;
}

int main()
{
    prec();
    ll n, k, ans = 0;
    cin >> n >> k;
    if(k == 1) {
        cout << n << endl;
        return 0;
    }
    for(ll i=1; i<=n; i++) {
        ll x = n / i - 1;
        ll z = cmb(x, k - 1);
        ans += z;
        ans %= mod;
    }
    if(ans < 0) ans += mod;
    cout << ans;
}