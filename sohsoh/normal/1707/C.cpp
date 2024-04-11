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

const ll MAXN = 1e6 + 10;
const ll LOG = 20;

int ps[MAXN], tin[MAXN], tout[MAXN], f[MAXN], n, m, t, par[MAXN], H[MAXN], P[MAXN][LOG];
vector<int> adj[MAXN];
vector<pll> vec;

int find(int v) {
	if (par[v] == v) return v;
	par[v] = find(par[v]);
	return par[v];
}

inline bool unite(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[v] = u;
	return true;
}

void dfs(int v, int p) {
	tin[v] = ++t;
	f[t] = v;
	P[v][0] = p;
	H[v] = H[p] + 1;

	for (int u : adj[v])
		if (u != p)
			dfs(u, v);

	tout[v] = t;
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = P[v][i];
	return v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i;

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (unite(u, v)) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		} else vec.push_back({u, v});
	}

	dfs(n, 0); //
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			P[v][i] = P[P[v][i - 1]][i - 1];

	for (auto [u, v] : vec) {
		if (tin[u] > tin[v]) swap(u, v);
		if (tin[u] <= tin[v] && tout[u] >= tout[v]) {
			u = Par(v, H[v] - H[u] - 1);
			ps[tin[u]]++;
			ps[tout[u] + 1]--;
			ps[tin[v]]--;
			ps[tout[v] + 1]++;
		} else {
			ps[tin[v]]--;
			ps[tout[v] + 1]++;
			ps[tin[u]]--;
			ps[tout[u] + 1]++;
			ps[0]++;
		}
	}

	for (int i = 1; i <= n; i++)
		ps[i] += ps[i - 1];

	for (int i = 1; i <= n; i++)
		cout << 1 - min(ps[tin[i]], 1);
	cout << endl;
	return 0;
}