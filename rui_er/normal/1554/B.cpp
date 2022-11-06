//luogu@rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll T, n, k, a[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &k);
		rep(i, 1, n) scanf("%lld", &a[i]);
		ll s = max(n-140, 1ll), ans = -inf;
		rep(i, s, n) rep(j, i+1, n) chkmax(ans, i*j-k*(a[i]|a[j]));
		printf("%lld\n", ans);
	}
	return 0;
}