#include <bits/stdc++.h>

using namespace std;

#define maxn 100010

int depth[maxn];
int par[maxn];
vector<vector<int>> adj(maxn);
int ans;
int maxd;
int ct[maxn];

void rec(int u) {
	depth[u] = par[u] == -1 ? 0 : depth[par[u]]+1;
	ct[depth[u]]++;
	maxd = max(maxd, depth[u]);
	for (int i = 0; i < adj[u].size(); i++) {
		rec(adj[u][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ans = 0;
	int n;
	cin >> n;
	int p;
	par[1] = -1;
	for (int i = 2; i <= n; i++) {
		cin >> p;
		par[i] = p;
		adj[p].push_back(i);
	}
	fill(ct, ct+maxn, 0);
	ans = 1;
	depth[1] = 0;
	maxd = 0;
	rec(1);
	for (int j = 1; j <= maxd; j++) {
		if (ct[j]%2 == 1) ans++;
		ct[j] = 0;
	}
	
	cout << ans << endl;
	cin >> n;
}