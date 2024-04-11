#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int dist[MAXN], n, m, s, t;
vector<int> adj[MAXN];
vector<int> adj_val[MAXN];
multiset<int> st[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
	}

	cin >> s >> t;
	for (int i = 1; i <= n; i++)
		for (int u : adj[i]) 
			adj_val[i].push_back(INF), st[u].insert(INF);
	
	fill(dist, dist + MAXN, INF);
	dist[t] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, t});
	
	while (!pq.empty()) {
		int v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (d_v != dist[v]) continue;
		
		for (int i = 0; i < (int)adj[v].size(); i++) {
			int u = adj[v][i], val = adj_val[v][i];
			if (val > d_v) {
				adj_val[v][i] = d_v;
				st[u].erase(st[u].find(val));
				st[u].insert(d_v);
				int d_u = min(*st[u].begin() + 1, *st[u].rbegin());
				if (d_u < dist[u]) {
					dist[u] = d_u;
					pq.push({d_u, u});
				}
			}
		}	
	}
	
	if (dist[s] == INF) dist[s] = -1;
	cout << dist[s] << endl;
	return 0;
}