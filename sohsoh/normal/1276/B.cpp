#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, a, b, C[MAXN], c, sz[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int v) {
	if (v == a || C[v]) return;
	C[v] = c;
	sz[c]++;
	
	for (int u : adj[v]) 
		dfs(u);
}

void dfs2(int v) {
	if (v == b || vis[v]) return;
	vis[v] = true;

	for (int u : adj[v])
		dfs2(u);
}


inline int solve() {
	for (int i = 0; i < n + 5; i++) {
		adj[i].clear();
		vis[i] = false;
		C[i] = 0;
		c = 0;
		sz[i] = 0;
	}

	cin >> n >> m >> a >> b;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		if (i != a && C[i] == 0)
			c++, dfs(i);

	ll t1 = 0, t2 = sz[C[b]] - 1;
	for (int i = 1; i <= n; i++)
		if (i != a && C[i] != C[b]) 
			t1++;


	dfs2(a);
	for (int i = 1; i <= n; i++) 
		if (vis[i] && C[i] == C[b])
			t2--;
	cout << t1 * t2 << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}