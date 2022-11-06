//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll n, a[N], sz[N], dis[N], dp[N], ans;
vector<ll> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs1(ll u, ll f) {
	dis[u] = dis[f] + 1;
	sz[u] = a[u];
	dp[1] += dis[u] * a[u];
	for(auto v : e[u]) {
		if(v == f) continue;
		dfs1(v, u);
		sz[u] += sz[v];
	}
}
void dfs2(ll u, ll f) {
	if(u > 1) {
		dp[u] = dp[f] + sz[1] - 2 * sz[u];
	}
	for(auto v : e[u]) {
		if(v == f) continue;
		dfs2(v, u);
	}
}

int main() {
	dis[0] = -1;
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n-1) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	rep(i, 1, n) chkmax(ans, dp[i]);
	printf("%lld\n", ans);
	return 0;
}