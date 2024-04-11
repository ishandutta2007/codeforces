#include <bits/stdc++.h>

using namespace std;

#define maxn 200010

vector<vector<int>> adj(maxn);
int n, m;
int deg[maxn];

bool seen[maxn];

vector<int> curcon;
void dfs(int u) {

	if (seen[u]) return;
	curcon.push_back(u);
	seen[u] = true;
	for (auto v : adj[u]) dfs(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int a, b;
	fill(deg, deg+maxn, 0);
	fill(seen, seen+maxn, false);
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!seen[i]) {
			curcon.clear();
			dfs(i);
			bool ok = true;
			for (int j = 0; j < curcon.size(); j++) {
				if (deg[curcon[j]] != 2) ok = false;
			}
			if (ok && curcon.size() > 2) ans++;
		}
	}
	cout << ans << endl;
	cin >> a;
}