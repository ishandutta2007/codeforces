//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;
const int L = 20;
int par[N][L];
int up[N][L];
int h[N];
int to[N];
int	s[N],t[N];
pair<int,int> edge[N];
vector<pair<int,int> > al[N];
int find(int v) {
	if(to[v] == v) return v;
	return to[v] = find(to[v]);
}
int unite(int u,int v) {
	u = find(u),v = find(v);
	to[u] = v;
	return (u != v);
}
void dfs(int v,int p = -1) {
	h[v] = (p + 1 ? h[p] + 1 : 0);
	par[v][0] = p;
	for(int i = 1; i < L;i++) {
		if(par[v][i-1] + 1) {
			par[v][i] = par[par[v][i-1]][i-1];
			up[v][i] = max(up[v][i-1],up[par[v][i-1]][i-1]);
		}
	}
	for(int i = 0; i < al[v].size();i++) {
		int u = al[v][i].first;
		if(u == p) continue;
		up[u][0] = al[v][i].second;
		dfs(u,v);
	}
	return;
}
pair<int,int> go_up(int v,int x) {
	int mx = 0;
	for(int b = 0; b < L;b++)
		if(x >> b & 1)
			mx = max(mx,up[v][b]),v = par[v][b];
	return {v,mx};
}
int lca(int u,int v) {
	if(h[u] < h[v]) swap(u,v);
	u = go_up(u,h[u] - h[v]).first;
	if(u == v) return v;
	for(int b = L - 1; ~b; --b)
		if(par[v][b] != par[u][b])
			v = par[v][b],u = par[u][b];
	return par[v][0];
}
int main() {
	ios_base::sync_with_stdio(0);
	int n,m; cin >> n >> m;
	for(int i = 0; i < n;i++) to[i] = i;
	for(int i = 0; i < m;i++) {
		int u,v,w; cin >> u >> v >> w; --u,--v;
		s[i] = u,t[i] = v;
		edge[i] = {w,i};
	}
	sort(edge,edge+m);
	ll ans = 0;
	int p = 0;
	for(int i = 0; i < m;i++) {
		ll w = edge[i].first,id = edge[i].second;
		int u = s[id],v = t[id];
		if(unite(u,v)) {
			ans += w,p++;
			al[u].push_back({v,w});
			al[v].push_back({u,w});
		}
	}
	dfs(0);
	int q; cin >> q;
	while(q--) {
		int u,v; cin >> u >> v; --u,--v;
		int pu = find(u),pv = find(v);
		if((p == n - 2 && pu == pv) || p < n - 2) {
			cout << -1 << '\n';
			continue;
		}
		if(p == n - 2) {
			cout << ans << '\n';
			continue;
		}
		int lc = lca(u,v);
		cout << ans - max(go_up(u,h[u] - h[lc]).second,go_up(v,h[v]-h[lc]).second) << '\n';
	}
	return 0;
}