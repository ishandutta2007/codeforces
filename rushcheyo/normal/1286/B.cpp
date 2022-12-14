#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, p[N], c[N], a[N];
vector<int> g[N];

vector<pair<int, int>> dfs(int u) {
	vector<pair<int, int>> res;
	for (int v : g[u]) {
		auto tmp = dfs(v);
		for (const auto &x : tmp) res.push_back(x);
	}
	sort(res.begin(), res.end());
	if (c[u] > res.size()) { puts("NO"); exit(0); }
	vector<pair<int, int>> rr;
	for (int i = 0; i < c[u]; ++i) rr.push_back(res[i]);
	rr.push_back(c[u] == 0 ? make_pair(1, u) : make_pair(res[c[u] - 1].first + 1, u));
	for (int i = c[u]; i < (int)res.size(); ++i) rr.push_back({res[i].first + 2, res[i].second});
	return rr;
}

int main() {
	scanf("%d", &n);
	int rt;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", p + i, c + i);
		if (p[i] == 0) rt = i;
		else g[p[i]].push_back(i);
	}
	auto t = dfs(rt);
	for (const auto &tt : t) a[tt.second] = tt.first;
	puts("YES");
	for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
}