// Problem: CF1029E Tree with Small Distances
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1029E
// Memory Limit: 250 MB
// Time Limit: 1000 ms
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
const int N = 2e5+5;

int n, dis[N], fa[N], ok[N], ans;
vector<int> e[N];
priority_queue<tuple<int, int> > q;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(int u, int f) {
	dis[u] = dis[f] + 1;
	fa[u] = f;
	for(int v : e[u]) {
		if(v == f) continue;
		dfs(v, u);
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	rep(u, 1, n) q.emplace(dis[u], u);
	rep(u, 1, n) if(dis[u] <= 3) ok[u] = 1;
	while(!q.empty()) {
		int u = get<1>(q.top()); q.pop();
		if(ok[u]) continue;
		ok[fa[u]] = 1;
		for(int v : e[fa[u]]) ok[v] = 1;
		++ans;
	}
	printf("%d\n", ans);
	return 0;
}