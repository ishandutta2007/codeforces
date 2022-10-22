#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 20;

int n, m, P[MAXN], H[MAXN], t_0, par[MAXN][LOG]; 
vector<int> adj[MAXN];
vector<pll> adj2[MAXN];
vector<pair<int, pll>> edges, mst_edges;
set<int> un_vis;
ll ans;
bool w_0[MAXN][LOG];
set<pll> used;

int Find(int v) {
	if (v == P[v]) return v;
	return P[v] = Find(P[v]);
}

inline bool Union(int v, int u, int w) {
	int pu = u, pv = v;
	v = Find(v), u = Find(u);
	if (v == u) return false;
	P[v] = u;
	ans += w;
	used.insert({pv, pu});
	used.insert({pu, pv});

	if (w == 0) t_0++;
	mst_edges.push_back({w, {pu, pv}});
	return true;
}

void dfs(int v) {
	un_vis.erase(v);
	
	int lst = 0;
	while (true) {
		auto it = un_vis.upper_bound(lst);
		if (it == un_vis.end()) break;
		lst = *it;
		if (binary_search(all(adj[v]), lst)) continue; //

		Union(v, lst, 0);
		dfs(lst);
	}
}

void dfs2(int v, int p, int w) {
	par[v][0] = p;
	w_0[v][0] = (w == 0);

	for (pll e : adj2[v]) {
		int u = e.X, w = e.Y;
		if (u == p) continue;
		H[u] = H[v] + 1;
		dfs2(u, v, w);
	}
}

pair<int, bool> kth_par(int v, int k) {
	bool b = false;
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			b |= w_0[v][i], v = par[v][i];
	return {v, b};
}

bool LCA(int u, int v) {
	if (H[v] < H[u]) swap(v, u);
	pair<int, bool> p = kth_par(v, H[v] - H[u]);
	v = p.X;
	bool b = p.Y;
	if (v == u) return b;

	for (int i = LOG - 1; i >= 0; i--) {
		if (par[v][i] != par[u][i]) {
			b |= w_0[v][i];
			b |= w_0[u][i];
			v = par[v][i];
			u = par[u][i];
		}
	}
	
	b |= w_0[v][0];
	b |= w_0[u][0];
	return b;
			
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int x = 0;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		x ^= w;
		edges.push_back({w, {u, v}});
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		sort(all(adj[i]));
		un_vis.insert(i);
		P[i] = i;	
	}	

	while (!un_vis.empty()) dfs(*un_vis.begin());

	sort(all(edges));
	for (auto e : edges) Union(e.Y.X, e.Y.Y, e.X); 
	for (auto e : mst_edges) {
		adj2[e.Y.X].push_back({e.Y.Y, e.X});
		adj2[e.Y.Y].push_back({e.Y.X, e.X});
	}

	dfs2(1, 0, 1);
	for (int i = 1; i < LOG; i++) {
		for (int v = 1; v <= n; v++) {
			par[v][i] = par[par[v][i - 1]][i - 1];
			w_0[v][i] = w_0[v][i - 1] | w_0[par[v][i - 1]][i - 1];
		}
	}

	ll tot = 1ll * n * (n - 1) / 2 - m;
	if (tot == t_0) {
		for (pair<int, pll> et : edges) {
			pll e = et.Y;
			if (used.find(e) != used.end()) continue;
			bool b = LCA(e.X, e.Y);
			if (b) return cout << min(ans + et.X, ans + x) << endl, 0;
		}
		
		cout << ans + x << endl;
		return 0;	
	} 

	cout << ans << endl;
	return 0;
}