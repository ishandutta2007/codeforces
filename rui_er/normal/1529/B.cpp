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
const ll N = 1e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, a[N];

int main() {
	mulT0 {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld", &a[i]);
		sort(a+1, a+1+n);
		ll mx = inf, ans = n;
		rep(i, 2, n) {
			mx = min(mx, a[i]-a[i-1]);
			if(mx < a[i]) {ans = i - 1; break;}
		}
		mx = inf;
		per(i, n, 2) {
			mx = min(mx, a[i]-a[i-1]);
			if(mx < a[n]) {ans = max(ans, n-i); break;}
		}
		printf("%lld\n", ans);
	} 
	return 0;
}