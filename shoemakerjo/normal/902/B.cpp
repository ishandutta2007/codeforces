#include <bits/stdc++.h>

using namespace std;

#define maxn 10010

int c[maxn];

vector<vector<int>> adj;

int dfs(int u, int p) {
	bool has = false;
	int ans = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		if (c[u] == c[v]) ans--;
		ans += dfs(v, u);

	}
	// if (!has) ans++;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		vector<int> bl;
		adj.push_back(bl);
	}
	int p;
	for (int i = 2; i <= n; i++) {
		cin >> p;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}
	for (int i  = 1; i <= n; i++) {
		cin >> c[i];
	}
	int ans = dfs(1, -1);
	cout << ans << endl;
	cin >> ans;
}