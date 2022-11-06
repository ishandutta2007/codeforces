#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=2e5+5, mod = 998244353;

ll f[sz], finv[sz];

ll cmb(ll n, ll r)
{
    ll y = (finv[r] * finv[n-r]) % mod;
    return (f[n] * y) % mod;
}

int main()
{
    f[0]=f[1]=finv[0]=finv[1]=1;
    for(ll i=2; i<sz; i++) finv[i] = (mod - (mod/i) * finv[mod%i] % mod) % mod;
    for(ll i=2; i<sz; i++) {
        f[i] = (f[i-1] * i) % mod;
        finv[i] = (finv[i-1] * finv[i]) % mod;
    }

    ll n,m;
    cin >> n >> m;

    ll ans = cmb(m,n-1);

    ll cnt = 0;
    for(int i=1; i<=n-2; i++) {
        ll now = cmb(n-2, i) * i;
        now %= mod;
        cnt = (cnt + now) % mod;
    }

    ans = (ans * cnt) % mod;

    if(ans < 0) ans += mod;

    cout << ans;
}