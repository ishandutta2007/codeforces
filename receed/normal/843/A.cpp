#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> a;
vector<vector<int>> g, ans;
vector<int> used;

void dfs(int v) {
	used[v] = 1;
	ans[ans.size() - 1].push_back(v);
	for (int u : g[v]) 
		if (!used[u])
			dfs(u);	
}

int main() {
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	g.resize(n);
	for (int i = 0; i < n; i++) {
		g[i].push_back(a[i].second);
		g[a[i].second].push_back(i);
	}
	used.assign(n, 0);
	for (int i = 0; i < n; i++) {
		if (used[i])
			continue;
		ans.push_back(vector<int>());
		dfs(i);
	}
	cout << ans.size() << '\n';
	for (auto v : ans) {
		cout << v.size() << ' ';
		for (int i : v)
			cout << i + 1 << ' ';
		cout << '\n';
	}
}