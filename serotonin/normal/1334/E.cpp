#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5, mod = 998244353;

typedef pair <ll,ll> pii;
#define x first
#define y second

map <ll,ll> mp;

vector <pii> pfc;

ll fac[sz], finv[sz], inv[sz];

void prec()
{
    inv[0] = inv[1] = 1;
    for(int i=2; i<69; i++)
        inv[i] = mod - mod / i * inv[mod % i] % mod;
    fac[0] = finv[0] = 1;
    for(int i=1; i<69; i++) {
        fac[i] = fac[i-1] * i % mod;
        finv[i] = finv[i-1] * inv[i] % mod;
    }
}

ll fnc(ll x)
{
    if(mp.find(x) != mp.end()) return mp[x];

    ll cut = 1, cnt = 0, N = x;
    for(auto p : pfc) {
        ll k = 0;
        while(x % p.x == 0) x /= p.x, k++;
        cnt += k;
        cut = cut * finv[k] % mod;
    }
    if(x > 1) cnt++;
    return mp[N] = fac[cnt] * cut % mod;
}

int main()
{
    prec();

    ll d;
    scanf("%lld", &d);

    for(ll i=2; i*i<=d; i++) {
        ll k = 0;
        while(d%i==0) d/=i, k++;
        if(k) pfc.push_back({i, k});
    }
    if(d>1) pfc.push_back({d, 1});

    int q;
    scanf("%d", &q);
    while(q--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        ll g = __gcd(a, b);
        ll ans = fnc(a / g) * fnc(b / g) % mod;
        printf("%lld\n", ans);
    }
}