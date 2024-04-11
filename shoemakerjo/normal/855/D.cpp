#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int par[100001][18];
int type[100001][18];
int depth[100001];
int root[100001];
vector<vector<int>> children;

int dfs(int cur, int par) {
	for (int i = 0; i < children[cur].size(); i++) {
		int v = children[cur][i];
		if (v == par) continue;
		root[v] = root[cur];
		depth[v] = depth[cur]+1;
		dfs(v, cur);
	}
}

pii walk(int i, int k) {
	if (k == 0) {
		return pii(i, 2);
	}
	int curtype = type[i][0];
	for (int d = 0; d < 18; d++) {
		if (((1 << d) & k) > 0) {
			if (curtype != type[i][d]) {
				curtype = -1;
			}
			// cout << "curi   " << i << endl;
			i = par[i][d];

		}
	}
	return pii(i, curtype);
}

int lca(int i, int j) {
	// cout << "dep:  " << i << " " << j << " " << depth[i] << " " << depth[j] << endl;
	if (depth[i] > depth[j]) {
		i = walk(i, depth[i]-depth[j]).first;
	}
	if (depth[j] >  depth[i]) {
		j = walk(j, depth[j]-depth[i]).first;
	}
	if (i == j) return i;
	// cout << "initial:  " << i << " " << j << endl;
	for (int d = 17; d >= 0; d--) {
		// cout << "d: " << d << " " << i << " " << j <<  endl;
		if (par[i][d] != par[j][d]) {
			i = par[i][d];
			j = par[j][d];
		}
		
	}
	return par[i][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	//type -1 means it is nothing
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		children.push_back(b);
	}
	int parent, ty;
	for (int i = 1; i <= n; i++) {
		cin >> parent >> ty;
		par[i][0] = parent;
		type[i][0] = ty;
		if (parent > 0) {
			children[parent].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (par[i][0] == -1) {
			depth[i] = 0;
			root[i] = i;
			dfs(i, -1);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 18; j++) {
			par[i][j]= type[i][j] = -1;
		}
	}
	for (int d = 1; d < 18; d++) {
		for (int i = 1; i <= n; i++) {
			int mid = par[i][d-1];
			if (mid == -1) {
				par[i][d] = -1;
				type[i][d] = -1;
			}
			else {
				par[i][d] = par[mid][d-1];
				if (type[i][d-1] == type[mid][d-1]) {
					type[i][d] = type[i][d-1];
				}
				else type[i][d] = -1;
			}
		}
	}
	int q;
	cin >> q;
	int ct, u, v;
	// cout << "HERE\n";
	for (int i = 0; i < q; i++) {
		cin >> ct >> u >> v;
		if (root[u] != root[v]) {
			cout << "NO\n";
			continue;
		}
		// cout << "lc is bad" << endl;
		int lc = lca(u,v);
		// cout << "lc: " << lc << endl;
		int ut = walk(u, depth[u]-depth[lc]).second;
		int vt = walk(v, depth[v]-depth[lc]).second;
		// cout << "vt: " << vt << endl;
		if (ct == 1) {
			if (u == lc && vt == 0) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
		else {
			if (vt == 1 && ut == 0 || u == lc && vt == 1) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	
	}
	// cin >> q;


}