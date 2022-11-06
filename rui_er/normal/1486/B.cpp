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
const ll N = 1e3+5;

ll n, x[N], y[N];

int main() {
	mulT0 {
		scanf("%lld", &n);
		rep(i, 1, n) scanf("%lld%lld", &x[i], &y[i]);
		sort(x+1, x+1+n); sort(y+1, y+1+n);
		ll lx, rx, ly, ry;
		if(n & 1) {
			lx = rx = x[(1+n)/2];
			ly = ry = y[(1+n)/2];
		}
		else {
			lx = x[n/2]; rx = x[n/2+1];
			ly = y[n/2]; ry = y[n/2+1];
		}
		printf("%lld\n", (ry-ly+1)*(rx-lx+1));
	}
	return 0;
}