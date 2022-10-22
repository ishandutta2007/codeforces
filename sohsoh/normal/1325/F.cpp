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

int n, m, sq, D[MAXN], par[MAXN];
vector<int> adj[MAXN], sets[MAXN];
bool vis[MAXN];

void dfs(int v, int d, int p = 0) {
	par[v] = p;
	vis[v] = true;
	D[v] = d;
	sets[d % sq].push_back(v);
	for (int u : adj[v]) {
		if (!vis[u]) dfs(u, d + 1, v);
		else {
			if (d - D[u] >= sq) {
				cout << 2 << endl;
				cout << d - D[u] + 1 << endl;
				cout << v << sep;
				
				while (v != u) {
					cout << par[v] << sep;
					v = par[v];
				}

				exit(0);
			} 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	sq = sqrt(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	int sq_c = ceil(sqrt(n));
	for (int i = 0; i < sq; i++) {
		if (sets[i].size() >= sq_c) {
			cout << 1 << endl;
			for (int j = 0; j < sq_c; j++) cout << sets[i][j] << sep;
			cout << endl;
			return 0;
		}
	}

	cout << ":/" << endl;
	return 0;
}