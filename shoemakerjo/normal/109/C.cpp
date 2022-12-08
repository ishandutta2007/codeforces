#include <bits/stdc++.h>

#define pii pair<int, int>
#define ll long long
#define maxn 100001
using namespace std;

vector<vector<pii>> adj;
int child[maxn+1][2]; //0 is 0 edge, 1 is 1 edge, 2 is more than 1 edge
int tot[maxn+1][2];
bool seen[maxn+1];
int parent[maxn+1];
int pt[maxn+1];
int sub[maxn+1];

int n;

void dfs(int u, int par) {
	// cout << "cur:  " << u << " " << par << endl;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		int type = adj[u][i].second;
		if (v == par) continue;
		if (!seen[v]) {
			seen[v] = true;
			parent[v] = u;
			pt[v] = type;
			dfs(v, u);
		}
		if (type == 1) {
			child[u][1] += child[v][0]+1 + child[v][1];
		}
		else {
			child[u][0] += child[v][0]+1;
			child[u][1] += child[v][1];
		}
		sub[u] += sub[v];
	}
}

void runpar(int u) {
	tot[u][0] = child[u][0];
	tot[u][1] = child[u][1];
	int pa = parent[u];
	if (!seen[pa]) {
		seen[pa] = true;
		runpar(pa);
	}
	if (pa == 0) return;
	if (pt[u] == 1) {
		tot[u][1] += n - sub[u]; 
	}
	else {
		tot[u][0] += tot[pa][0] - (tot[u][0] + 1);
		tot[u][1] += tot[pa][1] - tot[u][1];
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int u, v, w, tp;
	for (int i = 0; i <= n; i++) {
		vector<pii> b;
		adj.push_back(b);
		child[u][0] = child[u][1] = 0;
		seen[i] = false;
		tot[i][0] = tot[i][1] = 0;
		sub[i] = 1;
	}

	for (int i = 0; i < n-1; i++) {
		cin >> u >> v >> w;
		bool ok = true;
		while (w > 0) {
			if (w%10 != 4 && w%10 != 7) {
				ok = false;
			}
			w/=10;
		}
		if (ok) tp = 1;
		else tp = 0;
		adj[u].push_back(pii(v, tp));
		adj[v].push_back(pii(u, tp));
	}
	parent[1] = 0;
	seen[1] = true;
	dfs(1, 0);
	for (int i = 0; i <= n; i++) {
		seen[i] = false;
	}
	seen[0] = true;
	for (int i = 1; i <= n; i++) {
		if (!seen[i]) {
			seen[i] = true;
			runpar(i);
		}
	}
	ll ans = 0LL;
	for (int i = 1; i <= n; i++) {
		ll ct = tot[i][1];
		ans += (ct*(ct-1));
		// cout << i << " " << parent[i] << endl;
	}
	cout << ans << endl;
	// cin >> ans;
}