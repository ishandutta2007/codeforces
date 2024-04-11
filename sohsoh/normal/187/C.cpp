#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

const int MAXN = 1e6 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, k, qr, dist[MAXN], src[MAXN], tq, ans[MAXN];
vector<pll> new_add[MAXN];
queue<int> q;
vector<int> adj[MAXN], src_node[MAXN];
vector<pair<int, int>> adj2[MAXN];

inline void BFS() {
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (dist[u] == INF) {
				dist[u] = dist[v] + 1;
				src[u] = v;
				src_node[v].push_back(u);
				q.push(u);
			}
		}
	}	
}

void c_merge(int v, int u) {
	v = src[v];
	u = src[u];
	if (v == u) return;
	
	if (src_node[v].size() > src_node[u].size()) swap(v, u);	
	for (int e : src_node[v]) {	
		src_node[u].push_back(e);
		src[e] = u;
	}

	for (int e : src_node[v]) {
		for (pll edge : adj2[e]) {	
			if (src[edge.X] == u)
				ans[edge.Y] = min(ans[edge.Y], tq);
		}
	}

	src_node[v].clear();
}

inline void bullshit(int v) {
	dist[v] = 0;
	src[v] = v;
	src_node[v].push_back(v);
	q.push(v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(dist, dist + MAXN, INF);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int v;
		cin >> v;
		bullshit(v);
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);	
	}

	qr = 1;
	for (int i = 1; i <= qr; i++) {
		int u, v;
		cin >> u >> v;
		adj2[u].push_back({v, i});
		adj2[v].push_back({u, i});
		if (dist[v] == INF) bullshit(v);
		if (dist[u] == INF) bullshit(u);
	}

	BFS();

	for (int i = 1; i <= n; i++) {
		for (int u : adj[i]) {
			if (src[i] != src[u]) {
				new_add[dist[i] + dist[u] + 1].push_back({u, i});
				new_add[dist[i] + dist[u] + 1].push_back({i, u});
			}
		}
	}

	fill(ans, ans + MAXN, INF);

	
	while (tq < 2 * n + m) {
		for (pll e : new_add[tq]) {	
			c_merge(e.X, e.Y);
		}
		tq++;
	}	

	for (int i = 1; i <= qr; i++) {
		if (ans[i] == INF) ans[i] = -1;
		cout << ans[i] << sep;
	}

	cout << endl;
	return 0;
}