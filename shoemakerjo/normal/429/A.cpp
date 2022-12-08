#include <bits/stdc++.h>

using namespace std;
#define maxn 100010

int dep[maxn];
vector<vector<int>> adj(maxn);
int ans = 0;
int nums[maxn];
int gn[maxn];
vector<int> take;

void dfs(int u, int p, int oc, int ec) {
	dep[u] = p == -1? 1: dep[p]+1;
	if (dep[u]%2 == 1) {
		nums[u] = (nums[u]+oc)%2;
	}
	else {
		nums[u] = (nums[u]+ec)%2;
	}
	if (nums[u] != gn[u]) {
		ans++;
		take.push_back(u);
		if (dep[u]%2 == 0) ec++;
		else oc++;
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u, oc, ec);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int u, v;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> gn[i];
	}
	dfs(1, -1, 0, 0);
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
		cout << take[i] << endl;
	}
	cin >> n;
}