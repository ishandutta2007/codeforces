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

vector<int> adj[MAXN], adj_p[MAXN];
int n, m, dist[MAXN];

int BFS(vector<int> G[MAXN]) {
	queue<int> q;
	fill(dist, dist + MAXN, INF);
	dist[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : G[v]) if (dist[u] == INF) dist[u] = dist[v] + 1, q.push(u);
	}

	return dist[n];
}	
	
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) if (find(all(adj[i]), j) == adj[i].end()) adj_p[i].push_back(j);
	}

	int ans = max(BFS(adj), BFS(adj_p));
	if (ans == INF) return cout << -1 << endl, 0;
	cout << ans << endl;
	return 0;
}