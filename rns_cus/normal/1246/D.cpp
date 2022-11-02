#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, p[N], dp[N];
set <int> adj[N];
vector <int> ans, lab;

void dfs(int u) {
	for (auto v : adj[u]) {
		dp[v] = dp[u] + 1;
		dfs(v);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) scanf("%d", &p[i]), adj[p[i]].insert(i);
	dfs(0);
	int k, mx = 0;
	for (k = 0; k < n; k ++) mx = max(mx, dp[k]);
	for (k = 0; k < n; k ++) if (dp[k] == mx) break;
	while (k) {
		int u = p[k];
		if (adj[u].size() > 1) {
			adj[u].erase(k);
			int v = *adj[u].begin();
			ans.push_back(k);
			p[k] = v;
			adj[v].insert(k);
		}
		else {
			lab.push_back(k);
			k = u;
		}
	}
	lab.push_back(k);
	reverse(lab.begin(), lab.end());
	reverse(ans.begin(), ans.end());
	for (auto x : lab) printf("%d ", x); puts("");
	printf("%d\n", ans.size());
	for (auto x : ans) printf("%d ", x); puts("");

}