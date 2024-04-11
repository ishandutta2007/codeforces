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
const ll N = 1e5+5;

ll n, m, a[N], now, ans, s;

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]), s += a[i];
	sort(a+1, a+1+n);
	rep(i, 1, n-1) if(a[i] > now) ++now;
	ans = n - 1 + ((a[n] == now) ? 1 : (a[n] - now));
	printf("%lld\n", s-ans);
	return 0;
}