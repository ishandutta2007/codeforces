//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 ll T; for(scanf("%lld", &T);T;T--)
#define mulT1 ll T, rnds; for(scanf("%lld", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const ll N = 2e5+5, K = 2e5, mod = 1e9+7;

ll n, a[N], fac[N] = {1};

int main() {
	rep(i, 1, K) fac[i] = fac[i-1] * i % mod;
	mulT0 {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		ll qwq = a[1], qaq = 0, ans = fac[n-2];
		rep(i, 2, n) qwq &= a[i];
		rep(i, 1, n) if(a[i] == qwq) ++qaq;
		ans = ans * (qaq * (qaq - 1) % mod) % mod;
		printf("%lld\n", ans);
	}
    return 0;
}