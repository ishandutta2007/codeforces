//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, inf = 0x3f3f3f3f3f3f3f3fll; 

ll T, n, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		ll s = 0, mx = -inf;
		rep(i, 1, n) {
			scanf("%lld", &a[i]);
			s += a[i];
			chkmax(mx, a[i]);
		}
		double ans = 0.0;
		ans = mx + (1.0 * s - mx) / (1.0 * n - 1);
		printf("%.8lf\n", ans);
	}
	return 0;
}