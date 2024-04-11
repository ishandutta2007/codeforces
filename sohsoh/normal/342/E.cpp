#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll LOG = 20;

vector<int> adj[MAXN];
int par[MAXN][LOG], ct_par[MAXN], n, q, H[MAXN], sz[MAXN], ans[MAXN];
bool B[MAXN];

void dfs(int v, int p) {
	par[v][0] = p;
	H[v] = H[p] + 1;
	ans[v] = H[v] - 1;

	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];

	return v;
}

inline int LCA(int v, int u) {
	if (H[v] < H[u]) swap(v, u);
	v = Par(v, H[v] - H[u]);
	if (v == u) return v;

	for (int i = LOG - 1; i >= 0; i--)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];

	return par[v][0];
}

inline int path(int u, int v) {
	return H[u] + H[v] - 2 * H[LCA(u, v)];
}

int sub_sz(int v, int p) {
	sz[v] = 1;
	for (int u : adj[v])
		if (u != p && !B[u])
			sz[v] += sub_sz(u, v);
	return sz[v];
}

int centroid(int v, int p, int m) {
	for (int u : adj[v])
		if (!B[u] && u != p && sz[u] * 2 > m)
			return centroid(u, v, m);
	return v;
}

void build(int v, int p) {
	v = centroid(v, 0, sub_sz(v, 0));
	B[v] = true;
	ct_par[v] = p;

	for (int u : adj[v])
		if (!B[u])
			build(u, v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	build(1, 0);
	while (q--) {
		int c, v;
		cin >> c >> v;

		if (c == 1) {
			int u = v;
			while (v) {
				ans[v] = min(ans[v], path(u, v));
				v = ct_par[v];
			}

		} else {
			int fans = ans[v], u = v;
			while (v) {
				fans = min(fans, path(u, v) + ans[v]);
				v = ct_par[v];
			}

			cout << fans << endl;
		}
	}
	return 0;
}