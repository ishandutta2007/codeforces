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

const ll MAXN = 1e5 + 10;
const ll MAXP = 51;
const ll INF = 1e15;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m;
ll dist[MAXN][MAXP];
pll par[MAXN][MAXP];
vector<pll> adj[MAXN];

inline void Dijkstra() {
	for (int i = 1; i <= n; i++) memset(dist[i], 63, sizeof dist[i]);
	dist[1][0] = 0;
	par[1][0] = {1, 0};

	priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
	pq.push({0, {1, 0}});
	
	while (!pq.empty()) {
		ll v = pq.top().Y.X, v_w = pq.top().Y.Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[v][v_w]) continue;
	
		for (auto e : adj[v]) {
			int u = e.X, w = e.Y, d_u = w * w + v_w * w * 2 + d_v, u_w = w;
			if (v_w) u_w = 0;

			if (dist[u][u_w] > d_u) {
				dist[u][u_w] = d_u;
				pq.push({d_u, {u, u_w}});
			}
		}
	
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	Dijkstra();

	for (int i = 1; i <= n; i++) {
		ll ans = dist[i][0];
		if (ans >= INF) ans = -1;
		cout << ans << sep;
	}
	
	cout << endl;
	return 0;
}