// mo ni sai 20220726 T4

// Problem: CF1111E Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1111E
// Memory Limit: 250 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, K = 305, mod = 1e9+7;

int n, q, a[N], ord[N], dp[N][K], fa[N][20], dis[N], sz[N], dfn[N], tms;
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct BIT {
	int c[N];
	int lowbit(int x) {return x & (-x);}
	void add(int x, int k) {for(;x<=n;x+=lowbit(x)) c[x] += k;}
	int ask(int x) {int k = 0; for(;x;x-=lowbit(x)) k += c[x]; return k;}
}bit;
void dfs(int u, int f) {
	fa[u][0] = f;
	rep(i, 1, 19) fa[u][i] = fa[fa[u][i-1]][i-1];
	dis[u] = dis[f] + 1;
	sz[u] = 1;
	dfn[u] = ++tms;
	for(int v : e[u]) {
		if(v == f) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}
int LCA(int u, int v) {
	if(dis[u] < dis[v]) swap(u, v);
	per(i, 19, 0) if(dis[fa[u][i]] >= dis[v]) u = fa[u][i];
	if(u == v) return u;
	per(i, 19, 0) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

int main() {
	scanf("%d%d", &n, &q);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	while(q--) {
		int k, m, r;
		scanf("%d%d%d", &k, &m, &r);
		rep(i, 1, k) scanf("%d", &a[i]);
		rep(i, 1, k) {
			bit.add(dfn[a[i]], 1);
			bit.add(dfn[a[i]]+sz[a[i]], -1);
		}
		rep(i, 1, k) {
			int lca = LCA(a[i], r);
			ord[a[i]] = bit.ask(dfn[a[i]]) + bit.ask(dfn[r]) - bit.ask(dfn[lca]) - bit.ask(dfn[fa[lca][0]]) - 1;
		}
		sort(a+1, a+1+k, [](int x, int y) {
			return ord[x] < ord[y];
		});
		dp[0][0] = 1;
		rep(i, 1, k) {
			rep(j, 1, m) {
				dp[i][j] = (dp[i-1][j-1] + 1LL * (j - ord[a[i]]) % mod * dp[i-1][j] % mod) % mod;
			}
		}
		printf("%lld\n", accumulate(dp[k]+1, dp[k]+1+m, 0LL)%mod);
		rep(i, 1, k) {
			bit.add(dfn[a[i]], -1);
			bit.add(dfn[a[i]]+sz[a[i]], 1);
		}
	}
	return 0;
}