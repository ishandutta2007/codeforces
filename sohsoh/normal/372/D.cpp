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

const ll MAXN = 1e5 + 10;
const ll LOG = 20;

int k, n, tin[MAXN], par[MAXN][LOG], tot, t, H[MAXN]; // tout
vector<int> adj[MAXN];
set<pll> st;

void dfs(int v, int p) {
	par[v][0] = p;
	H[v] = H[p] + 1;
	tin[v] = ++t;

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

inline int dist(int v, int u) {
	return H[v] + H[u] - 2 * H[LCA(u, v)];
}

inline int prv(set<pll>::iterator it) {
	if (it == st.begin()) return prev(st.end()) -> Y;
	return prev(it) -> Y;
}

inline int nxt(set<pll>::iterator it) {
	it = next(it);
	if (it == st.end()) return st.begin() -> Y;
	return it -> Y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	k = k * 2 - 2;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];

	int r = 1, ans = 1;
	tot = 0;
	st.insert({tin[1], 1});
	for (int l = 1; l <= n; l++) {
		while (r <= n && tot <= k) {
			r++;
			if (r > n) break;

			auto it = st.lower_bound(make_pair(tin[r], r));
			if (it == st.end()) it = st.begin();
			tot -= dist(it -> Y, prv(it));

			st.insert({tin[r], r});
			it = st.find({tin[r], r});
			tot += dist(prv(it), it -> Y);
			tot += dist(it -> Y, nxt(it));
		}

		ans = max(ans, r - l);
		auto it = st.find(make_pair(tin[l], l));
		tot -= dist(prv(it), it -> Y);
		tot -= dist(it -> Y, nxt(it));
		st.erase(it);
		
		if (l == n) break;
		it = st.lower_bound(make_pair(tin[l], l));
		if (it == st.end()) it = st.begin();
		tot += dist(it -> Y, prv(it));
	}

	cout << ans << endl;
	return 0;
}