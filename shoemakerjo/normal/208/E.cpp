#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define pii pair<int, int>

int n, m;
int par[18][maxn];
vector<vector<int>> adj(maxn); //store the children
int ans[maxn]; //store for later printing
int subsize[maxn];
int dep[maxn];
vector<vector<pii>> quers(maxn); //stored as depth by index

int walk(int u, int k) { //classic binary lifting walking
	for (int i = 17; i >= 0; i--) {
		if (k & (1 << i)) {
			u = par[i][u];
		}
		if (u == -1) return u;
	}
	return u;
}

void getsubsize(int u, int p) {
	dep[u] = p == -1 ? 1 : dep[p]+1;
	subsize[u] = 1;
	for (auto v : adj[u]) {
		getsubsize(v, u);
		subsize[u] += subsize[v];
	}
}

void dfs(int u, int p, map<int, int>& cm) {
	// cout << "dfsing   " << u << endl;
	int mx = -1;
	int bigChild = -1;
	for (auto v : adj[u]) {
		if (subsize[v] > mx) {
			mx = subsize[v];
			bigChild = v;
		}
	}
	if (mx != -1) {
		dfs(bigChild, u, cm);
	}
	for (auto v : adj[u]) { //time for the me-me-me-meeeerge
		if (v != bigChild) {
			map<int, int> tempo;
			dfs(v, u, tempo);
			for (auto it = tempo.begin(); it != tempo.end(); ++it) {
				int cd = it->first;
				int ct = it->second;
				if (cm.count(cd) == 0) {
					cm[cd] = ct;
				}
				else cm[cd] += ct;
			}
		}
	}
	cm[dep[u]] = 1; //always the only guy of my depth in my subtree
	for (int i = 0; i < quers[u].size(); i++) {
		// cout << "this boy has a query " << endl;
		int cd = quers[u][i].first;
		int ind = quers[u][i].second;
		assert(cm.count(cd) > 0);
		ans[ind] = cm[cd]-1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int p;
	for (int i = 1; i <= n; i++) {
		cin >> p;
		if (p == 0) {
			p = -1;
		}
		else {
			adj[p].push_back(i);
		}
		par[0][i] = p;
	}
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[i-1][j] != -1) {
				par[i][j] = par[i-1][par[i-1][j]]; //yay for LCA (-like table)
			}
			else {
				par[i][j] = -1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (par[0][i] == -1) {
			getsubsize(i, -1);
		}
	}
	cin >> m;
	int v;
	for (int i = 0; i < m; i++) {
		cin >> v >> p;
		int spot = walk(v, p);
		// cout << "v   " << v << "   " << spot << endl;
		if (spot == -1) {
			ans[i] == 0;
			continue;
		}
		quers[spot].push_back(pii(dep[v], i)); 

	}

	//actually calculate answers
	for (int i = 1; i <= n; i++) {
		if (par[0][i] == -1) { //this boy is a root
			map<int, int> cm;
			dfs(i, -1, cm);
		}
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	cin >> n;
}