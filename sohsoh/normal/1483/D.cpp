#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

const ll MAXN = 600 + 10;
const ll INF = 4e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dist[MAXN][MAXN], q_dist[MAXN][MAXN], n, m, q;
vector<pair<pll, ll>> edges;
vector<pll> Q[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) fill(dist[i], dist[i] + MAXN, INF), dist[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = w;
		edges.push_back({{u, v}, w});
	}

	for (int t = 1; t <= n; t++)
		for (int v = 1; v <= n; v++)
			for (int u = 1; u <= n; u++)
				dist[v][u] = min(dist[v][u], dist[v][t] + dist[t][u]);

	cin >> q;
	while (q--) {
		int u, v, l;
		cin >> u >> v >> l;
		Q[v].push_back({u, l});
		Q[u].push_back({v, l});
	}
	
	for (int v = 1; v <= n; v++) {
		for (int d = 1; d <= n; d++) {
			for (pll e : Q[d]) {
				int s = e.X, l = e.Y;
				q_dist[v][d] = max(q_dist[v][d], l - dist[s][v]);
			}
		}
	}


	int ans = 0;
	for (auto e : edges) {
		int w = e.Y, u = e.X.X, v = e.X.Y;
		for (int d = 1; d <= n; d++) {
			int c = q_dist[u][d];
			if (c >= w + dist[v][d]) {
				ans++;
				break;
			}
		}

	}

	cout << ans << endl;
	return 0;
}