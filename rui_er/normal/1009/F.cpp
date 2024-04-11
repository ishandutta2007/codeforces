//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef int* pint;
typedef long long ll;
const int N = 1e6+5;

int n, fa[N], dis[N], maxdis[N], son[N], buc[N<<1], ans[N];
pint dp[N], now = buc;
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs1(int u, int f) {
	fa[u] = f;
	dis[u] = dis[f] + 1;
	for(int v : e[u]) {
		if(v == f) continue;
		dfs1(v, u);
		if(maxdis[v] > maxdis[son[u]]) son[u] = v;
	}
	maxdis[u] = maxdis[son[u]] + 1;
}
void dfs2(int u) {
	dp[u][0] = 1;
	if(!son[u]) return;
	dp[son[u]] = dp[u] + 1;
	dfs2(son[u]);
	ans[u] = ans[son[u]] + 1;
	for(int v : e[u]) {
		if(v == fa[u] || v == son[u]) continue;
		dp[v] = now;
		now += maxdis[v];
		dfs2(v);
		rep(i, 1, maxdis[v]) {
			dp[u][i] += dp[v][i-1];
			if(dp[u][i] > dp[u][ans[u]] || dp[u][i] == dp[u][ans[u]] && i < ans[u]) ans[u] = i;
		}
	}
	if(dp[u][ans[u]] == 1) ans[u] = 0;
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1, 0);
	dp[1] = now;
	now += maxdis[1];
	dfs2(1);
	rep(i, 1, n) printf("%d\n", ans[i]);
	return 0;
}