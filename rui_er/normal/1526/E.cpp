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
const ll N = 5e5+5, mod = 998244353ll;

ll n, k, a[N], rk[N], fac[N], inv[N];
void initC(ll lim) {
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	rep(i, 2, lim) {
		fac[i] = fac[i-1] * i % mod;
		inv[i] = (mod - mod / i) * inv[mod%i] % mod;
	}
	rep(i, 2, lim) inv[i] = inv[i-1] * inv[i] % mod;
}
ll C(ll x, ll y) {return fac[x] * inv[y] % mod * inv[x-y] % mod;}

int main() {
	/*
	 * Input a[i], init rk[i] (Suffix Array)
	 * Consider that if (rk[i] < rk[j]) && (rk[i+1] > rk[j+1]) then s[i] < s[j]
	 * Otherwise, s[i] <= s[j]
	 * Let's count the number of i[1,n-1] that rk[a[i]+1] > rk[a[i+1]+1]
	 * Calculate the answer
	**/
	scanf("%lld%lld", &n, &k);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) rk[++a[i]] = i;
	ll now = k + n - 1, tot = 0;
	rep(i, 1, n-1) tot += rk[a[i]+1] > rk[a[i+1]+1];
	now -= tot;
	initC(now);
	ll ans = C(now, n);
	printf("%lld\n", ans);
	return 0;
}