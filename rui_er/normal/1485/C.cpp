//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;

ll T, a, b;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &a, &b);
		ll lim = sqrt(a), ans = 0;
		rep(i, 1, lim) {
			ll delta = (a - i) / i;
			chkmin(delta, b);
			delta -= i;
			chkmax(delta, 0LL);
			ans += delta;
		}
		printf("%lld\n", ans);
	}
	return 0;
}