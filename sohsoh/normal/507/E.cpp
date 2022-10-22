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

int n, m, par[MAXN];
vector<pair<int, int>> adj[MAXN];
pair<int, int> dist[MAXN];
set<pll> roads;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, b;
		cin >> u >> v >> b;
		adj[u].push_back({v, b});
		adj[v].push_back({u, b});
		if (b) roads.insert({u, v});
	}

	for (int i = 0; i < MAXN; i++) dist[i] = {INF, INF};

	queue<int> q;
	dist[1] = {0, 0};
	par[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (pair<int, int> u : adj[v]) {
			pair<int, int> d = dist[v];
			d.X++;
			d.Y += 1 - u.Y;
			if (dist[u.X].X == INF) dist[u.X] = d, q.push(u.X), par[u.X] = v;
			else if (d < dist[u.X]) dist[u.X] = d, par[u.X] = v;
		}	
	}

	vector<pair<int, int>> ans;

	int v = n;
	while (v) {
		if (par[v]) {
			if (roads.find({v, par[v]}) != roads.end() || roads.find({par[v], v}) != roads.end()) {
				roads.erase({v, par[v]});
				roads.erase({par[v], v});
			} else ans.push_back({v, par[v]});
		}

		v = par[v];
	}

	cout << ans.size() + roads.size() << endl;
	for (pll e : ans) cout << e.X << sep << e.Y << sep << 1 << endl;
	for (pll e : roads) cout << e.X << sep << e.Y << sep << 0 << endl;
	return 0;
}