#include <bits/stdc++.h>

using namespace std;
#define maxn 200001

int depth[maxn];
int maxd[maxn];
vector<int> path;
vector<vector<int>> adj;
bool done;
int n, x;

void dfs(int u, int p) {
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		depth[v] = depth[u]+1;
		dfs(v, u);
	}
}

void dfs2(int u, int p) {
	maxd[u] = depth[u];
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs2(v, u);
		maxd[u] = max(maxd[u], maxd[v]);
	}
}

void dfspath(int u, int p) {
	if (done) return;
	path.push_back(u);

	if (u == x) {
		done = true;
		return;
	}

	for (int i = 0; i < adj[u].size(); i++) {
		if (done) return;
		int v = adj[u][i];
		if (v == p) continue;
		dfspath(v, u);
	}
	if (done) return;
	path.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> x;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		adj.push_back(b);
	}
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	done = false;
	depth[1] = 0;
	dfs(1, 0);
	dfs2(1, 0);
	dfspath(1, 0);
	int ans = 0;
	// cout << path.size() << endl;
	// for (int i = 0; i < path.size(); i++) {
	// 	cout << "--->  " <<  path[i] << endl;
	// }
	for (int i = 0; i < (path.size())/2; i++) {
		ans = max(ans, maxd[path[path.size()-i-1]]);
	}
	cout << ans*2 << endl;
	// cin >> ans;
}