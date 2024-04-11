// Problem: CF191C Fools and Roads
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF191C
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, fa[N][20], dis[N], diff[N], ans[N];
vector<tuple<int, int> > e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs1(int u, int f) {
	fa[u][0] = f;
	rep(i, 1, 19) fa[u][i] = fa[fa[u][i-1]][i-1];
	dis[u] = dis[f] + 1;
	for(auto i : e[u]) {
		int v = get<0>(i);
		if(v == f) continue;
		dfs1(v, u);
	}
}
int LCA(int u, int v) {
	if(dis[u] < dis[v]) swap(u, v);
	per(i, 19, 0) if(dis[fa[u][i]] >= dis[v]) u = fa[u][i];
	if(u == v) return u;
	per(i, 19, 0) if(fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
void dfs2(int u, int f) {
	for(auto i : e[u]) {
		int v = get<0>(i), id = get<1>(i);
		if(v == f) continue;
		dfs2(v, u);
		diff[u] += diff[v];
		ans[id] = diff[v];
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].emplace_back(v, i);
		e[v].emplace_back(u, i);
	}
	dfs1(1, 0);
	for(scanf("%d", &m);m;m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		++diff[u]; ++diff[v];
		diff[LCA(u, v)] -= 2;
	}
	dfs2(1, 0);
	rep(i, 1, n-1) printf("%d%c", ans[i], " \n"[i==n-1]);
	return 0;
}