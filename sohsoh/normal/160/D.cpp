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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, par[MAXN], S[MAXN], low[MAXN], H[MAXN], ans[MAXN];
vector<pair<pll, int>> edges[MAXN];
vector<int> V, E;
vector<pll> adj[MAXN];
bool edge_vis[MAXN], vis[MAXN];

int Find(int v) {
	if (v == par[v]) return v;
	return par[v] = Find(par[v]);
}

inline void Union(int v, int u) {
	if (S[v] > S[u]) swap(u, v);
	if (S[v] == S[u]) S[u]++;
	par[v] = u;
}

void dfs(int v) {
	vis[v] = true;
	for (pll e : adj[v]) {
		int u = e.X, ind = e.Y;
		if (edge_vis[ind]) continue;
		edge_vis[ind] = true;
		if (!vis[u]) {
			H[u] = H[v] + 1;
			low[u] = H[u];
			dfs(u);
			low[v] = min(low[v], low[u]);
		} else low[v] = min(low[v], H[u]);
	}
}

void dfs2(int v) {
	vis[v] = true;
	for (pll e : adj[v]) {
		int u = e.X, ind = e.Y;
		if (edge_vis[ind]) continue;
		edge_vis[ind] = true;
		if (!vis[u]) {
			if (low[u] > H[v]) ans[ind] = 3;
			dfs2(u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i;

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[w].push_back({{u, v}, i});
	}

	for (int w = 1; w < MAXN; w++) {
		for (auto e : edges[w]) {
			int u = Find(e.X.X), v = Find(e.X.Y), ind = e.Y;
			if (u == v) continue;
			ans[ind] = 1;
			V.push_back(u);
			V.push_back(v);
			E.push_back(ind);
			adj[u].push_back({v, ind});
			adj[v].push_back({u, ind});
		}

		for (int v : V) if (!vis[v]) H[v] = 1, dfs(v);
		for (int v : V) vis[v] = false;
		for (int e : E) edge_vis[e] = false;
		for (int v : V) if (!vis[v]) dfs2(v);
		for (int v : V) {
			low[v] = H[v] = 0;
			adj[v].clear();
			vis[v] = false;
		}

		for (int e : E) edge_vis[e] = false;
		for (auto e : edges[w]) {
			int u = Find(e.X.X), v = Find(e.X.Y);
			if (u != v) Union(u, v);
		}

		V.clear();
		E.clear();
	}

	for (int i = 1; i <= m; i++) {
		if (ans[i] == 0) cout << "none" << endl;
		else if (ans[i] == 1) cout << "at least one" << endl;
		else cout << "any" << endl;
	}
	return 0;
}