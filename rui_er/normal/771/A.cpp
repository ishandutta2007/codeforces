//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 1.5e5+5;

ll n, m, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Dsu {
	ll fa[N], sz[N];
	void init(ll x) {
		rep(i, 1, x) {
			fa[i] = i;
			sz[i] = 1;
		}
	}
	ll find(ll x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	bool merge(ll x, ll y) {
		ll u = find(x), v = find(y);
		if(u == v) return 0;
		if(sz[u] < sz[v]) swap(u, v);
		fa[v] = u;
		sz[u] += sz[v];
		sz[v] = 0;
		return 1;
	}
}dsu;

int main() {
	scanf("%lld%lld", &n, &m);
	dsu.init(n);
	rep(i, 1, m) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		dsu.merge(u, v);
	}
	ll ans = 0;
	rep(i, 1, n) {
		if(i == dsu.find(i)) {
			ans += dsu.sz[i] * (dsu.sz[i] - 1) / 2;
		}
	}
	puts(ans==m?"YES":"NO");
	return 0;
}