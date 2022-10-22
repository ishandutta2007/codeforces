#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 1e18;

ll dist[MAXN], n, m;
vector<pll> adj[2][MAXN];

void dijkstra(int ind) {
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for (int i = 1; i <= n; i++)
		pq.push({dist[i], i});

	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[v]) continue;
	
		for (auto [u, w] : adj[ind][v]) {
			ll d_u = d_v + w;
			if (d_u < dist[u]) {
				dist[u] = d_u;
				pq.push({d_u, u});
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
		adj[0][u].push_back({v, w});
		adj[1][v].push_back({u, w});
	}

	memset(dist, 63, sizeof dist);
	dist[1] = 0;
	dijkstra(0);
	dijkstra(1);

	for (int i = 2; i <= n; i++)
		cout << (dist[i] > INF ? -1 : dist[i]) << sep;
	cout << endl;
	return 0;
}