#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
vector<int> tsort(vector<vector<int> > G) {
	int n = G.size();
	vector<int> ret, vis(n);
	function<bool(int)> dfs = [&](int v) {
		vis[v] = true;
		for (auto &e : G[v]) if (!vis[e] && !dfs(e)) return false;
		ret.push_back(v);
		return true;
	};
	for (int i = 0; i < n; i++) if (!vis[i] && !dfs(i)) return{};
	reverse(ret.begin(), ret.end());
	return ret;
}
int n, m, a[200009], b[200009]; vector<int> v;
bool solve(int x) {
	set<pair<int, int> > s;
	for (int i = 0; i < x; i++) s.insert(make_pair(a[i], b[i]));
	for (int i = 1; i < v.size(); i++) {
		if (!s.count(make_pair(v[i - 1], v[i]))) return false;
	}
	return true;
}
int main() {
	scanf("%d %d", &n, &m);
	vector<vector<int> > G(n);
	for (int i = 0; i < m; i++) scanf("%d %d", &a[i], &b[i]), a[i]--, b[i]--, G[a[i]].push_back(b[i]);
	v = tsort(G);
	if (!solve(m)) printf("-1\n");
	else {
		int l = 0, r = m + 1;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (solve(m)) r = m;
			else l = m;
		}
		printf("%d\n", r);
	}
	return 0;
}