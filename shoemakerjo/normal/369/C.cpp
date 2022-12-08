#include <bits/stdc++.h>

#define maxn 100001
#define pii pair<int, int>

using namespace std;

int minchild[maxn+1];
int par[maxn+1];
vector<vector<pii>> adj;
vector<int> ans;

bool recurse(int u, bool trouble) {
	// cout << "start:   " << u << " " << trouble << endl;
	bool taken = false;
	for (int i = 0; i < adj[u].size(); i++) {

		int v = adj[u][i].first;
		if (par[u] == v) continue;
		int type = adj[u][i].second;
		par[v] = u;
		// cout << "u: " << u << "  v: " << v << endl;
		if (type == 2) {

			taken = taken | recurse(v, true);
		}
		else {
			taken = taken | recurse(v, false);
		}
		minchild[u] = min(minchild[u], minchild[v]);

	}
	// cout << u << " " << taken << endl;
	if (trouble && !taken) {
		taken = true;
		ans.push_back(minchild[u]);
	}
	return taken;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		vector<pii> b;
		adj.push_back(b);
	}
	for (int i = 0; i <= n; i++) {
		minchild[i] = i;
		par[i] = -1;
	}
	int x, y, t;
	for (int i = 0; i < n-1; i++) {
		cin >> x >>  y >> t;
		adj[x].push_back(pii(y, t));
		adj[y].push_back(pii(x, t));
	}
	recurse(1, false);
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0) cout << " ";
		cout << ans[i];
		
	}
	cout << endl;
	cin >> n;
}