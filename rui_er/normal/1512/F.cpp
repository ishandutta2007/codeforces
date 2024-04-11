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
const ll N = 2e5+5;

ll n, c, a[N], b[N], day[N], now[N], ans[N];

int main() {
	mulT0 {
		scanf("%lld%lld", &n, &c);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, n-1) scanf("%lld", &b[i]);
		day[1] = 1; now[1] = a[1]; ans[1] = (c + a[1] - 1) / a[1];
		ll Ans = ans[1];
		rep(i, 2, n) {
			day[i] = day[i-1] + 1 + (b[i-1] - now[i-1] + a[i-1] - 1) / a[i-1];
			now[i] = (b[i-1] - now[i-1] + a[i-1] - 1) / a[i-1] * a[i-1] + now[i-1] - b[i-1];
			ans[i] = day[i] + (c - now[i] + a[i] - 1) / a[i];
			Ans = min(Ans, ans[i]);
		}
//		rep(i, 1, n) printf("I=%lld DAY=%lld NOW=%lld ANS=%lld\n", i, day[i], now[i], ans[i]);
		printf("%lld\n", Ans);
	}
	return 0;
}