#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;
typedef pair<int, pair<int, int>> edge;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, C[MAXN], c, in_deg[MAXN];
vector<edge> edges;
vector<int> adj[MAXN], adj_r[MAXN], ans, T[MAXN], c_adj[MAXN];
stack<int> order_st;
bool vis[MAXN];

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = true;
	for (int u : adj[v]) dfs(u);
	order_st.push(v);
}

void sfd(int v) {
	if (C[v]) return;
	C[v] = c;
	T[c].push_back(v);
	for (int u : adj_r[v]) sfd(u);
}

void BFS() {
	queue<int> q;
	q.push(1);
	vis[1] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			vis[u] = true;
			q.push(u);
		}

		for (int ind : c_adj[v]) {
			int u = C[edges[ind].Y.Y];
			if (!vis[u] && u != 1 && in_deg[u] == 0) {
				vis[u] = true;
				q.push(u);
				ans.push_back(ind);
			}
		}


		if (v == 1) continue;
		for (int e : T[v])
			C[e] = 1, T[1].push_back(e);

		T[v].clear();	
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int t, u, v;
		cin >> u >> v >> t;
		if (t == 0) {
			adj[u].push_back(v);
			adj_r[v].push_back(u);
		}

		edges.push_back({t, {u, v}});
	}


	dfs(1);
	for (int i = 1; i <= n; i++) if (vis[i]) C[i] = 1;
	c = 1;

	for (int i = 2; i <= n; i++) dfs(i);
	while (!order_st.empty()) {
		int v = order_st.top();
		order_st.pop();
		if (C[v] == 0) {
			c++;
			sfd(v);
		}
	}


	for (int i = 1; i <= n; i++) adj[i].clear(), adj_r[i].clear();
	for (int i = 0; i < m; i++) {
		int t = edges[i].X, u = edges[i].Y.X, v = edges[i].Y.Y;
		u = C[u], v = C[v];
		if (u == v) continue;
		if (t == 0) adj[u].push_back(v), in_deg[v]++;
		else c_adj[u].push_back(i);
	}

	memset(vis, false, sizeof vis);
	BFS();

	for (int i = 1; i <= c; i++)
		if (!vis[i]) return cout << -1 << endl, 0;

	cout << ans.size() << endl;
	for (int e : ans) cout << e + 1 << sep;
	cout << endl;
	return 0;
}