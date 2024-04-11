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

vector<pll> ed;
int col[MAXN] = {0}, n, m, tin[MAXN], timer = 0, low[MAXN];
vector<ll> adj[MAXN];

void dfs(int v, int p = -1) {
	col[v] = 1;
	tin[v] = low[v] = timer++;
	for (ll u : adj[v]) {
		if (u == p) continue;
		if (col[u]) {
			if (col[u] == 1) ed.push_back({v, u});
			low[v] = min(low[v], tin[u]);
		} else {
			dfs(u, v);
			ed.push_back({v, u});
			low[v] = min(low[v], low[u]);
			if (low[u] > tin[v]) {
				cout << 0 << endl;
				exit(0);
			}
		}
	}

	col[v] = 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	for (pll e : ed) cout << e.X << sep << e.Y << endl;
	return 0;
}