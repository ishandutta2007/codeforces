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
const ll INF = 1e9;

ll deg[MAXN], n, m, dist[MAXN], fixed_adj[MAXN];
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<int> adj[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		deg[u]++;
	}

	fill(dist, dist + MAXN, INF);
	dist[n] = 0;
	pq.push({0, n});

	while (!pq.empty()) {
		ll d_v = pq.top().X, v = pq.top().Y;
		pq.pop();
		if (d_v != dist[v]) continue; //
	
		for (int u : adj[v]) {
			fixed_adj[u]++;		
			ll d_u = d_v + deg[u] - fixed_adj[u] + 1;
			if (d_u < dist[u]) {
				pq.push({d_u, u});
				dist[u] = d_u;
			}
		}
	}

	cout << dist[1] << endl;
	return 0;
}