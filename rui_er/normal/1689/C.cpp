// Problem: CF1689C Infected Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1689C
// Memory Limit: 250 MB
// Time Limit: 3000 ms
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
const int N = 3e5+5;

int T, n, son[N][3], sz[N], dp[N];
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs1(int u, int f) {
	sz[u] = 1;
	for(int v : e[u]) {
		if(v == f) continue;
		son[u][++son[u][0]] = v;
		dfs1(v, u);
		sz[u] += sz[v];
	}
}
void dfs2(int u) {
	if(!son[u][0]) return;
	rep(i, 1, son[u][0]) dfs2(son[u][i]);
	if(son[u][0] == 1) dp[u] = sz[son[u][1]] - 1;
	else dp[u] = max(sz[son[u][1]] - 1 + dp[son[u][2]], 
					 sz[son[u][2]] - 1 + dp[son[u][1]]);
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n-1) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1, 0);
		dfs2(1);
		printf("%d\n", dp[1]);
		rep(i, 1, n) {
			son[i][0] = son[i][1] = son[i][2] = sz[i] = dp[i] = 0;
			e[i].clear();
		}
	}
	return 0;
}