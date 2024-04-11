#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ll long long
int n;
vector<vector<int>> adj;
ll minc[maxn];
ll mdec[maxn];
ll vals[maxn];

void dfs(int u, int p) {
	minc[u] = mdec[u] = 0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
		minc[u] = max(minc[u], minc[v]);
		mdec[u] = max(mdec[u], mdec[v]);
	}
	int va = vals[u] + minc[u] - mdec[u];
	if (va > 0) {
		mdec[u] += va;
	}
	else {
		minc[u] += (0-va);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
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
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
	}
	dfs(1, -1);
	cout << mdec[1]+minc[1] << endl;
	cin >> n;
}