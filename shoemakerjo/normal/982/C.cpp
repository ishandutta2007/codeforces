#include <bits/stdc++.h>

using namespace std;

#define maxn 100010

int n;
vector<vector<int>> adj(maxn);

int subsize[maxn];
int ans;

void dfs(int u, int p) {

	subsize[u] = 1;
	for (auto v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		subsize[u] += subsize[v];
	}
	if (p != -1 && subsize[u] % 2 == 0) ans++;
}

int main() {
	// int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << -1 << endl;
		return 0;
	}
	int u,  v;
	for (int i = 0; i < n-1; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ans = 0;
	dfs(1, -1);
	cout << ans << endl;
	cin >> n;


}