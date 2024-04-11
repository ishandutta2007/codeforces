#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

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
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, dist[MAXN], m, ans[MAXN];
queue<int> q;
vector<int> adj[MAXN], bfs_adj[MAXN];
bool vis[MAXN];

inline void BFS(int v) {
	dist[v] = 0;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (dist[u] == INF) {
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
}

void dfs(int v) {
	ans[v] = dist[v];
	vis[v] = true;
	for (int u : adj[v]) {
		if (dist[u] > dist[v]) {
			if (!vis[u]) dfs(u);	
			ans[v] = min(ans[v], ans[u]);
		}
	}
	for (int u : adj[v])
		ans[v] = min(ans[v], dist[u]);
}

inline int solve() {
	fill(dist, dist + n + 10, INF);
	fill(ans, ans + n + 10, INF);
	fill(vis, vis + n + 10, false);
	for (int i = 0; i < n + 10; i++) adj[i].clear(), bfs_adj[i].clear();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	BFS(1);	
	dfs(1);
	for (int i = 1; i <= n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = MAXN - 20;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}