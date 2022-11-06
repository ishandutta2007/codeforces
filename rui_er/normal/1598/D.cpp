//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll T, n, a[N], b[N], cntA[N], cntB[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld", &n);
		rep(i, 1, n) cntA[i] = cntB[i] = 0;
		rep(i, 1, n) {
			scanf("%lld%lld", &a[i], &b[i]);
			++cntA[a[i]]; ++cntB[b[i]];
		}
		ll df = 0, ans = n * (n - 1) / 2 * (n - 2) / 3;
		rep(i, 1, n) {
			ll now = (cntA[a[i]] - 1) * (cntB[b[i]] - 1);
			df += now;
		}
		printf("%lld\n", ans-df);
	}
	return 0;
}