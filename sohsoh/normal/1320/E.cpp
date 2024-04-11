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

const ll MAXN = 2e5 + 10;
const ll LOG = 20;

int par[MAXN][LOG], tin[MAXN], tout[MAXN], t, V[MAXN], H[MAXN], S[MAXN], F[MAXN], T[MAXN], tdist[MAXN];
vector<int> adj[MAXN], c_adj[MAXN];

void dfs(int v, int p) {
	par[v][0] = p;
	tin[v] = ++t;
	H[v] = H[p] + 1;

	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
	tout[v] = t;
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

inline int dist(int u, int v) {
	return (H[v] + H[u]) - 2 * min(H[u], H[v]);
}

inline void solve() {
	int k, m;
	cin >> k >> m;
	vector<int> vec = {1}, imp;
	priority_queue<pll, vector<pll>, greater<pll>> pq;

	for (int i = 1; i <= k; i++) {
		cin >> F[i] >> S[i];
		vec.push_back(F[i]);
		pq.push({i - k, F[i]});
		V[F[i]] = i;
		T[F[i]] = i - k;
	}
	
	for (int i = 0; i < m; i++) {
		int v;
		cin >> v;
		imp.push_back(v);
		vec.push_back(v);
	}


	sort(all(vec), [] (int v, int u) {
		return tin[v] < tin[u];
	});

	int sz = vec.size();
	for (int i = 0; i < sz; i++)
		vec.push_back(LCA(vec[i], vec[(i + 1) % sz]));


	sort(all(vec), [] (int v, int u) {
		return tin[v] < tin[u];
	});

	vec.resize(unique(all(vec)) - vec.begin());
	stack<int> st;
	st.push(1);

	for (int i = 1; i < int(vec.size()); i++) {
		int v = vec[i];
		while (tout[st.top()] < tout[v]) st.pop();

		c_adj[st.top()].push_back(v);
		c_adj[v].push_back(st.top());
		st.push(v);
	}
	
	while (!pq.empty()) {
		int d_v = pq.top().X;
		int v = pq.top().Y, r = F[V[v]];
		pq.pop();
		if (d_v != T[v]) continue;
		
		for (int u : c_adj[v]) {
			int d_u = T[r] + k * ((dist(u, v) + tdist[v] + S[V[v]] - 1) / S[V[v]]);
		
			if (V[u] == 0 || d_u < T[u]) {
				V[u] = V[v];
				T[u] = d_u;
				tdist[u] = tdist[v] + dist(u, v);
				pq.push({d_u, u});
			}
		}	
	}

	for (int e : imp)
		cout << V[e] << sep;
	cout << endl;

	for (int v : vec) {
		T[v] = V[v] = tdist[v] = 0;
		c_adj[v].clear();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
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

	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}