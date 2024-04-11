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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m;
vector<pll> adj[MAXN], tour;
set<pll> extra_edges;
bool mark[MAXN];

void Euler(int v, int p = 0) {
	while (!adj[v].empty()) {
		pll e = adj[v].back();
		adj[v].pop_back();
		if (mark[e.Y]) continue;
		mark[e.Y] = true;
		Euler(e.X, v);
	}

	if (p) tour.push_back({v, p});
}

inline int solve() {
	for (int i = 0; i < n + 10; i++) adj[i].clear();
	tour.clear();
	fill(mark, mark + m + n + 10, false);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}

	int ans = n;
	stack<int> odd_deg;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() & 1) {
			ans--;
			odd_deg.push(i);
		}
	}

	while (!odd_deg.empty()) {
		int u = odd_deg.top();
		odd_deg.pop();
		int v = odd_deg.top();
		odd_deg.pop();
		adj[u].push_back({v, m});
		adj[v].push_back({u, m});
		extra_edges.insert({v, u});
		extra_edges.insert({u, v});
		m++;
	}

	for (int i = 1; i <= n; i++) Euler(i);
	cout << ans << endl;
	for (pll e : tour) {
		if (extra_edges.find(e) != extra_edges.end()) {
			extra_edges.erase(e);
			extra_edges.erase({e.Y, e.X});
			continue;
		}
		cout << e.X << sep << e.Y << endl;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}