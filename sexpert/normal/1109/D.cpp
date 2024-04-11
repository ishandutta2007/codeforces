#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll fac[MAXN], ifac[MAXN];

ll mpow(ll b, ll e) {
    if(e == 0)
        return 1;
    if(e % 2)
        return (b * mpow(b, e - 1))%MOD;
    ll p = mpow(b, e/2);
    return (p * p)%MOD;
}

ll inv(ll b) {
    return mpow(b, MOD - 2);
}

ll binom(ll a, ll b) {
    if(b > a)
        return 0;
    ll aux = (fac[a] * ifac[a - b])%MOD;
    return (aux * ifac[b])%MOD;
}

ll n, m;

ll term(ll k) {
    if(k > m)
        return 0;
    ll aux = (binom(m - 1, m - k) * binom(n - 2, k - 1))%MOD;
    aux = (aux * fac[k - 1])%MOD;
    if(n - k > 1) {
        aux = (aux * (k + 1ll))%MOD;
        aux = (aux*mpow(n, n - k - 2ll))%MOD;
    }
    return (aux * mpow(m, n - k - 1ll))%MOD;
}

int main() {
    ifac[0] = fac[0] = 1;
    for(ll i = 1; i < MAXN; i++) {
        fac[i] = (i * fac[i - 1])%MOD;
        ifac[i] = inv(fac[i]);
    }
	int a, b;
	cin >> n >> m >> a >> b;
	ll ans = 0;
	for(ll k = 1; k <= n - 1; k++)
	    ans = (ans + term(k))%MOD;
	cout << ans << endl;
}