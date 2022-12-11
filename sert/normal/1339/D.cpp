#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int pr, int lvl, int num[], vector<vector<int>> &es) {
	if (es[v].size() == 1u) num[lvl]++;
	for (int w : es[v]) {
		if (w == pr) continue;
		dfs(w, v, 1 - lvl, num, es);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> es(n);
	vector<int> deg(n, 0);
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
		deg[v1]++;
		deg[v2]++;
	}
	int leafs = 0;
	for (int i = 0; i < n; i++) if (deg[i] == 1) leafs++;
	set<int> pre_leafs;
	for (int i = 0; i < n; i++) if (deg[i] == 1) pre_leafs.insert(es[i][0]);
	int mx = pre_leafs.size() + n - leafs - 1;
	int num[2] = {0, 0};
	dfs(0, -1, 0, num, es);
	if (num[0] > 0 && num[1] > 0) cout << "3 "; 
	else cout << "1 ";
	cout << mx << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
#ifdef SERT
	int t = 3;
	for (int i = 1; i < t; i++) {
		solve();
	}
#endif
}