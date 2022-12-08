#include <bits/stdc++.h>

using namespace std;
#define maxn 300010
int n, m;
string ky;

bool vis[maxn];
bool curin[maxn];
int comp[maxn][26];
bool ok = true;
int ans = 0;

vector<vector<int>> adj(maxn);

void rec(int u) {
	if (!ok) return;
	curin[u] = true;
	vis[u] = true;
	for (int j = 0; j < adj[u].size(); j++) {
		int v = adj[u][j];
		if (curin[v]) {
			ok = false;
			return;
		}
		if (!vis[v]) rec(v);
		for (int i = 0; i < 26; i++) {
			comp[u][i] = max(comp[u][i], comp[v][i]);
		}
	}
	comp[u][ky[u-1]-'a']++;
	ans = max(ans, comp[u][ky[u-1]-'a']);
	curin[u] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cin >> ky;
	int x, y;
	while (m-- > 0) {
		cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < 26; j++) {
			comp[i][j] = 0;
		}
	}
	fill(vis, vis+maxn, false);
	fill(curin, curin+maxn, false);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) rec(i);
	}
	if (ok) cout << ans << endl;
	else cout << -1 << endl;
	cin >> x;
}