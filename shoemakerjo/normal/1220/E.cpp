#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll maxbad = 0;

ll res = 0;

const int maxn = 200010;

bool seen[maxn];
vector<int> adj[maxn];

ll msum[maxn];

bool ok[maxn];
ll w[maxn];

void dfs(int u, int p = -1) {
	msum[u] = w[u];
	seen[u] = true;
	for (int v : adj[u]) {
		if (v == p) continue;
		if (seen[v]) {
			ok[u] = true;
			continue;
		}
		dfs(v, u);
		if (ok[v]) ok[u] = true;
		else msum[u] = max(msum[u], msum[v] + w[u]);
	}
	if (ok[u]) res += w[u];
	else maxbad = max(maxbad, msum[u]);
}

int n, m, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u  >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cin >> s;
	dfs(s);
	cout << res + maxbad << endl;

}