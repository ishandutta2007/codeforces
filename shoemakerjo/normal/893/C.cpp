#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ll long long

int small;
int cost[maxn];
int n, m;
bool vis[maxn];

vector<vector<int>> adj;

void flood(int u) {
	vis[u] = true;
	small = min(small, cost[u]);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis[v]) flood(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		adj.push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		vis[i] = false;
	}
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ll ans = 0LL;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			small = 2000000000;
			flood(i);
			ans = ans + (small+0LL);
		}
	}
	cout << ans << endl;
	cin >> ans;
}