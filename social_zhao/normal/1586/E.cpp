#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int n, m, q, _x[N], _y[N], deg[N], vis[N], dep[N], fa[N];
vector<int> ori[N], adj[N];

void dfs(int u, int lst) {
	vis[u] = 1, dep[u] = dep[lst] + 1, fa[u] = lst;
	for(auto v: ori[u]) if(!vis[v]) dfs(v, u), adj[u].push_back(v);
}

int GetLCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] != dep[y]) x = fa[x];
	if(x == y) return x;
	while(x != y) x = fa[x], y = fa[y];
	return x;
}

void PrintUp(int x, int top) {
	if(x == top) return;
	cout << x << " ";
	PrintUp(fa[x], top);
}

void PrintDwn(int x, int top) {
	if(x == top) return;
	PrintDwn(fa[x], top);
	cout << x << " ";
}

int main() {
	n = get(), m = get();
	for(int i = 1, u, v; i <= m; i++) u = get(), v = get(), ori[u].push_back(v), ori[v].push_back(u);
	q = get();
	for(int i = 1; i <= q; i++) _x[i] = get(), _y[i] = get(), ++deg[_x[i]], ++deg[_y[i]];
	int cnt = 0;
	for(int i = 1; i <= n; i++) cnt += deg[i] & 1;
	if(cnt) {
		cout << "NO" << endl;
		cout << cnt / 2 << endl;
		return 0;
	}
	cout << "YES" << endl;
	dfs(1, 0);
	for(int i = 1; i <= q; i++) {
		int lca = GetLCA(_x[i], _y[i]);
		int dis = dep[_x[i]] + dep[_y[i]] - 2 * dep[lca];
		dis++;
		cout << dis << endl;
		PrintUp(_x[i], lca), cout << lca << " ", PrintDwn(_y[i], lca);
		cout << endl;
	}
	return 0;
}