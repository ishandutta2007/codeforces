#include <bits/stdc++.h>

using namespace std;

int mx = 100001;
vector<vector<pair<int, int>>> g(mx);
vector<int> x(mx, 0), used(mx, 0), c;

void dfs(int v) {
	used[v] = 1;
	for (auto u : g[v]) {
		if (used[u.first]) 
			c.push_back(x[u.first] ^ x[v] ^ u.second);
		else {
			x[u.first] = x[v] ^ u.second;
			dfs(u.first);
		}
	}
}

int main() {
	int n, m, u, v, w;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(1);
	vector<int> d;
	for (int i = 27; i >= 0; i--) {
		int t = 0, sh = 1 << i;
		for (int j = 0; j < c.size(); j++)
			if (c[j] & sh) {
				d.push_back(c[j]);
				c.erase(c.begin() + j);
				t = 1;
				break;
			}
		if (!t)
			continue;
		for (int j = 0; j < c.size(); j++)
			if (c[j] & sh)
				c[j] ^= d.back();
	}
	int z = x[n];
	for (int i : d)
		if ((i ^ z) < z)
			z ^= i;
	cout << z;
}