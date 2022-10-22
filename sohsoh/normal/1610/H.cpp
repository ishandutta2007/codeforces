#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LOG = 20;

int n, m, tin[MAXN], tout[MAXN], H[MAXN], par[MAXN][LOG], t, fen[MAXN];
vector<pll> ce;
vector<int> adj[MAXN], Q[MAXN];

inline void update(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[ind] += val;
}

inline int query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];
	return ans;
}

inline int query(int l, int r) {
	if (r < l) return 0;
	int ans = query(r);
	if (l > 0) ans -= query(l - 1);
	return ans;
}

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];

	return v;
}

void dfs(int v) {
	tin[v] = ++t;
	H[v] = H[par[v][0]] + 1;
	for (int u : adj[v])
		dfs(u);
	
	tout[v] = t;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
		par[i][0] = p;
	}

	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	dfs(1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (H[u] > H[v]) swap(u, v);
		if (u == par[v][0]) return cout << -1 << endl, 0;

		if (tin[u] <= tin[v] && tout[u] >= tout[v]) Q[u].push_back(v);
		else ce.push_back({u, v});
	}

	int ans = 0;
	for (int u = n; u > 0; u--) {
		for (int v : Q[u]) {
			int w = Par(v, H[v] - H[u] - 1);
			if (query(tin[w], tout[w]) - query(tin[v], tout[v]) == 0) {
				ans++;
				update(tin[w], 1);
			}
		}
	}

	for (pll e : ce)
		if (query(tin[e.X], tout[e.X]) + query(tin[e.Y], tout[e.Y]) == ans)
			return cout << ans + 1 << endl, 0;

	cout << ans << endl;
	return 0;
}