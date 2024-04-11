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

int n, C[MAXN], par[MAXN], tmp, col[MAXN], dist[MAXN]; // pressed, not pressed, red, white
vector<int> adj[MAXN], adj_t[MAXN];
bool vis[MAXN];

void dfs(int v) {
	vis[v] = true;
	par[v] = tmp;
	col[tmp] = C[v];
	for (int u : adj_t[v]) if (C[u] == C[v] && !vis[u]) dfs(u);
}

void diam(int v, int p) {
	for (int u : adj[v]) {
		if (u != p) {
			dist[u] = dist[v] + 1;
			diam(u, v);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> C[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj_t[u].push_back(v);
		adj_t[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			tmp++;
			dfs(i);	
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int u : adj_t[i]) {
			if (par[u] != par[i]) adj[par[u]].push_back(par[i]);
		}
	}

	diam(1, 0);
	int v = 1;
	for (int i = 1; i <= n; i++) if (dist[i] > dist[v]) v = i;
	memset(dist, 0, sizeof dist);
	diam(v, 0);	
	cout << (*max_element(dist, dist + MAXN) + 1) / 2 << endl;
	return 0;
}