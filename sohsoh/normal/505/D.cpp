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

int n, m, ans, col[MAXN];
vector<int> adj[MAXN], C, ud_adj[MAXN];
bool vis[MAXN];

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = true;
	C.push_back(v);
	for (int u : ud_adj[v]) dfs(u);
}

bool dfs2(int v) {
	if (col[v]) return false;
	col[v] = 1;

	for (int u : adj[v]) {
		if (col[u] == 0) {
			if (dfs2(u)) 
				return true;
		} else if (col[u] == 1) return true;
	}

	col[v] = 2;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		ud_adj[u].push_back(v);
		ud_adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;	
		C.clear();
		dfs(i);

		bool cyc = false;
		for (int e : C) cyc |= dfs2(e);
		ans += C.size() - int(!cyc);
	}

	cout << ans << endl;
	return 0;
}