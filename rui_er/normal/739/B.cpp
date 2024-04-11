//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll n, a[N], fa[N][20], dis[N], ans[N];
vector<tuple<ll, ll> > e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(ll u, ll f) {
	rep(i, 1, 19) fa[u][i] = fa[fa[u][i-1]][i-1];
	int p = u;
	per(i, 19, 0) if(fa[p][i] && dis[u] - dis[fa[p][i]] <= a[u]) p = fa[p][i];
	--ans[fa[p][0]];
	++ans[fa[u][0]];
	for(auto i : e[u]) {
		ll v = get<0>(i), w = get<1>(i);
		if(v == f) continue;
		dis[v] = dis[u] + w;
		dfs(v, u);
		ans[u] += ans[v];
	}
}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 2, n) {
		ll x;
		scanf("%lld%lld", &fa[i][0], &x);
		e[fa[i][0]].emplace_back(i, x);
	}
	dfs(1, 0);
	rep(i, 1, n) printf("%lld%c", ans[i], " \n"[i==n]);
	return 0;
}