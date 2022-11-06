//By: Luogu@rui_er(122461)
//virtual participation
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 3e5+5;

ll T, n, m, k[N], c[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &m);
		rep(i, 1, n) scanf("%lld", &k[i]);
		rep(i, 1, m) scanf("%lld", &c[i]);
		ll ans = 0, now = 1;
		sort(k+1, k+1+n, greater<ll>());
		rep(i, 1, n) {
			if(c[k[i]] <= c[now]) ans += c[k[i]];
			else {ans += c[now++];}
		}
		printf("%lld\n", ans);
	}
	return 0;
}