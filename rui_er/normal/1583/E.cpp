//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 6e5+5;

int n, m, q, f[N], dis[N], fa[N], path[N], buc[N], deg[N], tot;
vector<tuple<int, int> > e[N];
vector<int> ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void init(int x) {rep(i, 1, x) f[i] = i;}
int find(int u) {return u == f[u] ? u : f[u] = find(f[u]);}
bool merge(int u, int v) {
	int x = find(u), y = find(v);
	if(x == y) return 0;
	f[x] = y;
	return 1;
}
void dfs(int u, int f, int id) {
	fa[u] = f;
	dis[u] = dis[f] + 1;
	path[u] = id;
	for(auto i : e[u]) {
		int v = get<0>(i);
		int id = get<1>(i);
		if(v != f) dfs(v, u, id);
	}
}
int upd(int u, int k) {
	ans[k].push_back(u);
	buc[path[u]] ^= 1;
	return fa[u];
}
int jump(int u, int v, int k) {
	while(dis[u] > dis[v]) u = upd(u, k);
	return u;
}
void jump2(int u, int v, int k) {
	while(u != v) {
		u = upd(u, k);
		v = upd(v, 0);
	}
	ans[k].push_back(u);
}

int main() {
	scanf("%d%d", &n, &m);
	init(n);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(merge(u, v)) {
			++tot;
			e[u].push_back(make_tuple(v, tot));
			e[v].push_back(make_tuple(u, tot));
		}
	}
	dfs(1, 0, 0);
	scanf("%d", &q);
	rep(i, 1, q) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(dis[u] > dis[v]) u = jump(u, v, i);
		else if(dis[u] < dis[v]) v = jump(v, u, 0);
		jump2(u, v, i);
		reverse(ans[0].begin(), ans[0].end());
		for(auto j : ans[0]) ans[i].push_back(j);
		ans[0].clear();
	}
	int s = 0;
	rep(u, 1, n) {
		for(auto i : e[u]) {
			int v = get<0>(i);
			int id = get<1>(i);
			deg[u] ^= buc[id];
		}
		s += deg[u];
	}
	if(s) printf("NO\n%d\n", s/2);
	else {
		puts("YES");
		rep(i, 1, q) {
			int sz = ans[i].size();
			printf("%d\n", sz);
			for(auto j : ans[i]) printf("%d ", j);
			puts("");
		}
	}
	return 0;
}