//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, mod = 1e9+7;

ll T, n, k, fac[N], inv[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void initC(ll lim) {
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	rep(i, 2, lim) {
		fac[i] = fac[i-1] * i % mod;
		inv[i] = (mod - mod / i) * inv[mod%i] % mod;
	}
	rep(i, 2, lim) inv[i] = inv[i-1] * inv[i] % mod;
}
ll C(ll x, ll y) {return fac[x] * inv[y] % mod * inv[x-y] % mod;}
ll qpow(ll x, ll y) {
	ll ans = 1;
	for(;y;y>>=1,x=x*x%mod) if(y & 1) ans = ans * x % mod;
	return ans;
}

int main() {
	initC(N-1);
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &k);
		ll qwq = 0, ans = 0;
		for(int i=0;i<n;i+=2) qwq = (qwq + C(n, i)) % mod;
		ans = qpow(qwq+(n&1), k);
		if(!(n&1)) rep(i, 1, k) {
			ll delta = qpow(qwq, i-1) * qpow(2, n*(k-i)) % mod;
			ans = (ans + delta) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}