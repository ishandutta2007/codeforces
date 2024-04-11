//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 1e6+5, mod = 998244353ll;

ll n, tab[N], p[N], tot, factor[N], facMul[N];
ll qpow(ll x, ll y) {
	ll ans = 1;
	for(;y;y>>=1,x=x*x%mod) if(y & 1) ans = ans * x % mod;
	return ans;
}
ll inv(ll x) {return qpow(x, mod-2);}

void sieve() {
	facMul[1] = tab[1] = 1;
	rep(i, 2, n) {
		if(!tab[i]) {
			p[++tot] = i;
			factor[i] = facMul[i] = 2;
		}
		rep(j, 1, tot) {
			ll now = i * p[j];
			if(now > n) break;
			tab[now] = 1;
			if(!(i % p[j])) {
				factor[now] = (factor[i] + 1) % mod;
				facMul[now] = facMul[i] * inv(factor[i]) % mod * factor[now] % mod;
				break;
			}
			factor[now] = 2;
			facMul[now] = 2 * facMul[i] % mod;
		}
	}
}

int main() {
	/*
	 * Case 1 : n % p == 0 <=> ans += cnt(factor(n))
	 * Case 2 : inside <=> ans += lst + factor(i)
	 * ans = Case(1) + Case(2)
	**/
	scanf("%lld", &n);
	sieve();
	ll ans = 0;
	rep(i, 1, n) ans = (((i != n) + 1) * ans % mod + facMul[i]) % mod;
	printf("%lld\n", ans);
	return 0;
}