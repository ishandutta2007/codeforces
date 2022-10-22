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

int n, m, H[MAXN];
vector<int> adj[MAXN];
bool par[MAXN], vis[MAXN];

void dfs(int v, int p) {
	stack<int> e;
	H[v] = H[p] + 1;
	vis[v] = true;

	for (int u : adj[v]) {
		if (u == p) continue;
		if (vis[u]) {
			if (H[u] < H[v]) e.push(u);
			continue;
		}
		
		dfs(u, v);
		if (!par[u]) e.push(u);
	}

	while (e.size() > 1) {
		cout << e.top() << sep << v << sep;
		e.pop();
		cout << e.top() << endl;
		e.pop();
	} 

	if (!e.empty()) {
		cout << e.top() << sep << v << sep << p << endl;
		e.pop();
		par[v] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if (m & 1) return cout << "No solution" << endl, 0;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	return 0;
}