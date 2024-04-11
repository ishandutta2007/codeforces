//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5; 

ll T, n, k, a[N], fa[N], dis[N], s[N];
vector<ll> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs1(ll u, ll f) {
	fa[u] = f;
	dis[u] = dis[f] + 1;
	s[u] = a[u];
	for(auto v : e[u]) {
		if(v != f) {
			dfs1(v, u);
			s[u] ^= s[v];
		}
	}
}
ll dfs2(ll u, ll f, ll now) {
	if(s[u] == s[1] && now && u != 1) return 1;
	now |= !s[u];
	for(auto v : e[u]) {
		if(v != f) {
			if(dfs2(v, u, now)) return 1;
		}
	}
	return 0;
}
ll dfs3(ll u, ll f) {
	ll ans = 0, tag = 0;
	if(s[u] == s[1] && u != 1) tag = 1;
	for(auto v : e[u]) {
		if(v != f) {
			ans += dfs3(v, u);
		}
	}
	return max(ans, tag);
}

int main() {
	for(scanf("%lld", &T);T;T--) {
		scanf("%lld%lld", &n, &k);
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, n-1) {
			ll u, v;
			scanf("%lld%lld", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1, 0);
		if(!s[1]) puts("YES");
		else {
			if(k > 2) puts(dfs2(1, 0, 0)||dfs3(1, 0)>=2?"YES":"NO");
			else puts("NO");
		}
		rep(i, 1, n) e[i].clear();
	}
	return 0;
}