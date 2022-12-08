#include <bits/stdc++.h>

using namespace std;

bool ans;
vector<vector<int>> adj;
#define maxn 100010
bool isleaf[maxn];

void dfs(int u, int p) {
	int ct = 0;
	if (adj[u].size() == 1 && p != -1) {
		isleaf[u] = true;
	}
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		
		dfs(v, u);
		if (isleaf[v]) ct++;
	}
	if (isleaf[u]) return;
	if (ct < 3) ans = false;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ans = true;
	for (int i = 0; i <= n; i++) {
		vector<int> bl;
		isleaf[i] = false;
		adj.push_back(bl);
	}
	int p;
	for (int i = 2; i <= n; i++) {
		cin >> p;
		adj[p].push_back(i);
		adj[i].push_back(p);
	}
	dfs(1, -1);
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	cin >> n;
}