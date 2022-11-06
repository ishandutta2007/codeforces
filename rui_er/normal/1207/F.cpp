//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 5e5+5, K = 400; 

ll n, m, a[N], ans[K][K];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &m);
	n = 500000;
	while(m--) {
		ll op, x, y;
		scanf("%lld%lld%lld", &op, &x, &y);
		if(op == 2) {
			if(x < K) printf("%lld\n", ans[x][y]);
			else {
				ll now = 0;
				for(ll i=y;i<=n;i+=x) now += a[i];
				printf("%lld\n", now);
			}
		}
		else {
			rep(p, 1, K-1) ans[p][x%p] -= a[x];
			a[x] += y;
			rep(p, 1, K-1) ans[p][x%p] += a[x];
		}
	}
	return 0;
}