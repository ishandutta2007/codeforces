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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, vis[MAXN], dist[MAXN];
vector<int> adj[MAXN], t_c;

inline void kill_it() {
	cout << -1 << endl;
	exit(0);
}

void dfs(int v) {
	t_c.push_back(v);
	for (int u : adj[v]) {
		if (vis[u] == vis[v]) kill_it();
		else if (vis[u] == 0) vis[u] = 3 - vis[v], dfs(u);
	}
}

inline int O_o(int v) {
	for (int e : t_c) dist[e] = INF;
	queue<int> q;
	q.push(v);
	dist[v] = 0;
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

	int ans = 0;
	for (int e : t_c) ans = max(ans, dist[e]);
	return ans;
}

inline int SMT() {
	int ans = 0;
	for (int e : t_c)
		ans = max(ans, O_o(e));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fill(dist, dist + MAXN, INF);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			t_c.clear();
			vis[i] = 1;
			dfs(i);
			ans += SMT();
		}
	}

	cout << ans << endl;
	return 0;
}