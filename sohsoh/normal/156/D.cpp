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
ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll ans, C, T, n, m;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int v) {
	vis[v] = true;
	C++;
	for (int u : adj[v]) if (!vis[u]) dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> MOD;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			T++;
			dfs(i);
			ans *= C;
			ans %= MOD;
			C = 0;
		}
	}

	if (T == 1) return cout << 1 % MOD << endl, 0;
	ans *= poww(n, T - 2, MOD);
	cout << ans % MOD << endl;
	return 0;
}