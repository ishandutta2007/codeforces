#include <bits/stdc++.h>

using namespace std;

int n, croot, ccent, centc;
vector<vector<int>> g(200001), ans;
vector<int> w(200001, 1), par(200001), ct, now(3);

void dfs(int v, int p) {
	int s = n - 1, cc = 1;
	for (int u : g[v]) {
		if (u == p)
			continue;
		dfs(u, v);
		if (w[u] > n / 2)
			cc = 0;
		s -= w[u];
		w[v] += w[u];
	}
	if (cc && s <= n / 2)
		ct.push_back(v);
}

void dfs2(int v, int p) {
	now[0] = ccent;
	now[1] = centc;
	now[2] = v;
	ans.push_back(now);
	centc = v;
	now[0] = v;
	now[1] = p;
	now[2] = croot;
	ans.push_back(now);
	for (int u : g[v]) {
		if (u == p)
			continue;
		dfs2(u, v);
	}
}


int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	if (ct.size() == 2) {
		g[ct[0]].erase(find(g[ct[0]].begin(), g[ct[0]].end(), ct[1]));
		g[ct[1]].erase(find(g[ct[1]].begin(), g[ct[1]].end(), ct[0]));
	}
	for (int v : ct) {
		ccent = v;
		for (int u : g[v]) {
			croot = u;
			centc = u;
			for (int w : g[croot]) {
				if (w == ccent)
					continue;	
				dfs2(w, croot);
			}
			now[0] = ccent;
			now[1] = centc;
			now[2] = croot;
			ans.push_back(now);
		}
	}
	cout << ans.size() << '\n';
	for (auto vv : ans)
		cout << vv[0] << ' ' << vv[1] << ' ' << vv[2] << '\n';
}