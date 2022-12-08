#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

#define maxn 1000
int st;
int en;
vector<vector<int>> adj;
int n, m;
bool seen[maxn];
bool atall[maxn];
vector<pii> cyc;
bool incyc = false;
bool isdone = false;
int dest;
int dfs_num[maxn];
int dsf_low[maxn];
stack<int> S;
bool visited[maxn];
int dfsNumberCounter;
bool ok;

void rec(int u) {
	if (atall[u]) return;
	if (isdone) return;
	seen[u] = true;
	atall[u] = true;
	for (int i = 0; i < adj[u].size(); i++) {
		if (isdone || incyc) return;
		int v = adj[u][i];
		if (seen[v]) {
			incyc = true;
			dest = v;
			cyc.push_back(pii(u, v));
			return;
		}
		rec(v);
		if (incyc) {
			cyc.push_back(pii(u, v));
			if (u == dest) {
				isdone = true;
				incyc = false;
			}
			return;
		}
	}
	seen[u] = false;
}

void scc(int u) {
	dsf_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push(u);
	visited[u] = true;
	for (int j = 0; j < adj[u].size(); j++)  {
		int v = adj[u][j];
		if (u == st && v == en) continue;
		if (dfs_num[v] == -1) {
			scc(v);
		}
		if (visited[v]) {
			dsf_low[u] = min(dsf_low[u], dsf_low[v]);
		}
	}
	if (dsf_low[u] == dfs_num[u]) {
		int sz = 0;
		while (1) {
			int v = S.top(); S.pop();
			visited[v] = false;
			sz++;
			if (v == u) break;
		}
		if (sz > 1) ok = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		vector<int> bl;
		adj.push_back(bl);
		seen[i] = false;
		atall[i] = false;
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (!atall[i]) rec(i);
	}
	if (cyc.size() == 0) {
		cout << "YES" << endl;
		return 0;
	}
	// if (cyc.size() > n) {
	// 	cout << "THIS IS BAD" << endl;
	// 	return 0;
	// }
	bool ans = false;
	for (int i = 0; i < cyc.size(); i++) {
		ok = true;
		dfsNumberCounter = 0;
		st = cyc[i].first;
		en = cyc[i].second;
		for (int j = 1; j <= n; j++) {
			dfs_num[j] = -1;
			dsf_low[j] = 0;
			visited[j] = false;
		}
		for (int j = 1; j <= n; j++) {
			if (dfs_num[j] == -1) scc(j);
		}
		if (ok) ans = true;
	}
	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	// cout << endl;
	cin >> n;
}