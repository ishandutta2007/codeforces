#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj;

ll t0 = 0, t1 = 0;
void dfs(int u, int par, int type) {
	int curtype = 1-type;
	if (type == 0) t0+=1LL;
	else t1+=1LL;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == par) continue;
		dfs(v, u, curtype);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		adj.push_back(b);
	}
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	t0 = 0LL;
	t1 = 0LL;
	dfs(1, 0, 0);
	ll ans = t0*t1 - (n-1);
	cout << ans << endl;
	// cin >> n;
}