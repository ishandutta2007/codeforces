//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, mod = 998244353;

ll n, k, fac[N], inv[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void init(int lim) {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	rep(i, 2, lim) {
		fac[i] = fac[i-1] * i % mod;
		inv[i] = (mod - mod / i) * inv[mod%i] % mod;
	}
	rep(i, 2, lim) inv[i] = inv[i-1] * inv[i] % mod;
}
ll qpow(ll x, ll y) {
	ll ans = 1;
	for(;y;y>>=1,x=x*x%mod) if(y & 1) ans = ans * x % mod;
	return ans;
}
ll C(ll n, ll m) {
	return fac[n] * inv[m] % mod * inv[n-m] % mod;
}
ll S(ll n, ll m) {
	ll ans = 0;
	rep(i, 0, m) {
		ll mul = (i & 1) ? -1 : 1;
		ll now = C(m, i) * qpow(m-i, n) % mod;
		ans = (ans + mod + mul * now) % mod;
	}
	ans = ans * inv[m] % mod;
	return ans;
}

int main() {
	scanf("%lld%lld", &n, &k);
	if(k >= n) return puts("0")&0;
	init(n);
	ll ans = C(n, k) * S(n, n-k) % mod * fac[n-k] % mod;
	if(k) ans = ans * 2 % mod;
	printf("%lld\n", ans);
	return 0;
}