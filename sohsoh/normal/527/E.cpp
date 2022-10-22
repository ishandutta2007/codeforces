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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, mark[MAXN];
vector<pll> adj[MAXN], tour;

void Euler(int v, int p) {
	while (!adj[v].empty()) {
		pll e = adj[v].back();
		adj[v].pop_back();
		if (mark[e.Y]) continue;
		mark[e.Y] = true;
		Euler(e.X, v);
	}

	tour.push_back({v, p});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}

	vector<int> odd_deg;
	for (int i = 1; i <= n; i++)
		if (adj[i].size() & 1)
			odd_deg.push_back(i);

	while (!odd_deg.empty()) {
		int u = odd_deg.back();
		odd_deg.pop_back();
		int v = odd_deg.back();
		odd_deg.pop_back();
		adj[v].push_back({u, m});
		adj[u].push_back({v, m});
		m++;
	}

	if (m & 1) {
		adj[1].push_back({1, m});
		adj[1].push_back({1, m});
		m++;
	}

	Euler(1, 0);
	tour.pop_back();
	cout << tour.size() << endl;
	for (int i = 0; i < tour.size(); i++) {
		if (i & 1) cout << tour[i].Y << sep << tour[i].X << endl;
		else cout << tour[i].X << sep << tour[i].Y << endl;
	}
	return 0;
}