#include <bits/stdc++.h>

#define ll long long
#define maxn 400000

using namespace std;

int n, m;
ll costs[maxn+1];
int dfs_low[maxn];
int dfs_num[maxn];
ll mod = 1000000007;
bool visited[maxn+1];
vector<vector<int>> adj;
vector<int> S;
ll ans, cant;
int counter;
void scc(int u) {
	dfs_low[u] = dfs_num[u] = counter++;
	S.push_back(u);
	visited[u] = true;
	for (int j = 0; j < adj[u].size(); j++) {
		int v = adj[u][j];
		if (dfs_num[v] == -1) {
			scc(v);
		}
		if (visited[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}

	if (dfs_low[u] == dfs_num[u]) {
		ll ct = 1;
		ll curmin = -1;
		while (1) {
			int v = S.back();
			S.pop_back();
			visited[v] = false;
			if (costs[v] < curmin || curmin == -1) {
				curmin = costs[v];
				ct = 1;
			}
			else if (costs[v] == curmin) ct++;
			if (u == v) break;
		}
		cant = (cant*ct)%mod;
		ans += curmin;
	}
}

int main() {
	counter = 0;
	cin >> n;
	ans = 0;
	cant = 1;
	for (int i = 0; i <= n; i++) {
		visited[i] = false;
		dfs_low[i] = 0;
		dfs_num[i] = -1;
		vector<int> b;
		adj.push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		cin >> costs[i];
	}
	cin >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		// adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (dfs_num[i] == -1) {
			scc(i);
		}
	}
	cout << ans << " " << cant << endl;
	cin >> n;
}