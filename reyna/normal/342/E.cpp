//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Q = 333;
const int L = 18;
const int N = 1e5 + 9;
int Que[N],bg,ed,mark[N],dis[N],h[N],par[N][L];
vector<int> al[N];
void bfs() {
	while(bg != ed) {
		int v = Que[bg++];
		for(auto u : al[v]) {
			if(dis[v] + 1 < dis[u]) {
				dis[u] = dis[v] + 1;
				Que[ed++] = u;
			}
		}
	}
	bg = 0,ed = 0;
	return;
}
void dfs(int v,int p = -1) {
	h[v] = (~p ? h[p] + 1 : 0);
	par[v][0] = (~p ? p : v);
	for(int i = 1; i < L;i++)
		par[v][i] = par[par[v][i-1]][i-1];
	for(auto u : al[v])
		if(u - p) dfs(u,v);
	return;
}
int lca(int u,int v) {
	if(h[u] < h[v]) swap(u,v);
	for(int b = L - 1; ~b;--b)
		if((h[u] - h[v]) >> b & 1)
			u = par[u][b];
	if(u == v) return v;
	for(int b = L - 1; ~b; --b)
		if(par[u][b] != par[v][b])
			u = par[u][b],v = par[v][b];
	return par[v][0];
}
int get_dis(int u,int v) {
	return h[u] + h[v] - 2 * h[lca(u,v)];
}
int main() {
	ios_base::sync_with_stdio(0);
	int n,q; cin >> n >> q;
	for(int i = 0; i < n - 1;i++) {
		int u,v; cin >> u >> v; --u,--v;
		al[u].push_back(v);
		al[v].push_back(u);
		dis[i+1] = N * 10;
	}
	dfs(0);
	Que[ed++] = 0;
	bfs();
	while(q--) {
		int c,v; cin >> c >> v; --v;
		if(c == 1) {
			Que[ed++] = v;
			dis[v] = 0;
			if(ed - bg > Q) bfs();
		} else {
			int ans = dis[v];
			for(int i = bg; i < ed;i++) {
				int u = Que[i];
				ans = min(ans,get_dis(u,v));
			}
			cout << ans << '\n';
		}
	}
}