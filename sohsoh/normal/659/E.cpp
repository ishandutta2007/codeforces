#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int ans = 0, n, m;
bool flag = true, vis[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	vis[v] = true;
	for (int u : adj[v]) {
		if (u == p) continue;
		if (vis[u]) flag = false;
		else dfs(u, v);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			flag = true;
			dfs(i, 0);
			ans += flag;
		}
	}

	cout << ans << endl;
	return 0;
}