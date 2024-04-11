#include <bits/stdc++.h>

#define maxn 100001
using namespace std;

int n;
vector<vector<int>> adj;
int depth[maxn];
int par[17][maxn];
int subsize[maxn];

void dfs(int u, int pa) {
	subsize[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == pa) continue;
		par[0][v] = u;
		depth[v] = depth[u]+1;
		dfs(v, u);
		subsize[u] += subsize[v];
	}
}

int walk(int u, int k) {
	for (int d = 0; d<= 16 && u != -1; d++) {
		if (((1 << d) & k) > 0) {
			u = par[d][u];
		}
	}
	return u;
}

int lca(int u, int v) {
	if (depth[u] > depth[v]) {
		u = walk(u, depth[u] - depth[v]);
	}
	if (depth[v] > depth[u]) {
		v = walk(v, depth[v] - depth[u]);
	}
	if (u == v) return u;
	for (int d = 16; d >= 0; d--) {
		if (par[d][u] != par[d][v]) {
			u = par[d][u];
			v = par[d][v];
		}
	}
	return par[0][u];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		adj.push_back(b);
	}
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i <= 16; i++) {
		for (int j = 0; j <= n; j++) {
			par[i][j] = -1;
		}
	}
	depth[1] = 1;
	dfs(1, -1);

	for (int d = 1; d <= 16; d++) {
		for (int j = 1; j <= n; j++) {
			int mid = par[d-1][j];
			if (mid != -1) {
				par[d][j] = par[d-1][mid];
			}
		}
	}
	int m;
	cin >> m;
	int x, y;
	int ans;
	// for (int i = 1; i <= n; i++) {
	// 	cout << "su:  " << subsize[i] << endl;
	// }
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (depth[x] < depth[y]) {
			int temp = x;
			x = y;
			y = temp;
		}
		int lc = lca(x, y);
		if (depth[x] == depth[y]) {
			ans = n;
			int dist = depth[x]-depth[lc];
			// cout << "dist:  " << dist << endl;
			ans -= subsize[walk(x, dist-1)];
			// cout << "sub:  " << subsize[walk(x, dist-1)] << endl;
			ans -= subsize[walk(y, dist-1)];
		}
		else {
			ans = -1;
			int ld = depth[x] - depth[lc];
			int rd = depth[y] - depth[lc];
			ld-=rd;
			if (ld%2 == 1) ans = 0;
			else {
				int spot = walk(x, rd + ld/2);
				ans = subsize[spot] - 
					subsize[walk(x, rd + ld/2 - 1)];
			}
		}
		cout << ans << '\n';
	}
	// cin >> m;

}