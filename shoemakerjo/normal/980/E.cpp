#include <bits/stdc++.h>

using namespace std;
#define maxn 1000010

int par[21][maxn];
bool isin[maxn];
int k, n;
int numin;

vector<vector<int>> adj(maxn);

void dfs(int u, int p) {
	par[0][u] = p;
	for (auto v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	numin = 1;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(n, -1);
	fill(isin, isin+maxn, false);
	isin[n] = true;

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[i-1][j] != -1) {
				par[i][j] = par[i-1][par[i-1][j]];
			}
			else {
				par[i][j] = -1;
			}
		}
	}

	for (int i = n-1; i >= 1; i--) {
		if (isin[i]) continue;
		int numneed = 1;
		int cur = i;
		for (int j = 20; j >= 0; j--) {
			if (par[j][cur] == -1) continue;
			if (!isin[par[j][cur]]) {
				numneed += 1 << j;
				cur = par[j][cur];
			}
		}
		if (numneed + numin <= n-k) {
			numin += numneed;
			cur = i;
			while (!isin[cur]) {
				isin[cur] = true;
				cur = par[0][cur];
			}
		}

	}
	for (int i = 1; i <= n; i++) {
		if (!isin[i]) cout << i << " ";
	}
	cout << endl;
	cin >> n;
}