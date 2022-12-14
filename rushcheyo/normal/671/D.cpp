#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 300005;
int n, m, dep[N];
ll ans, cov[N];
vector<int> g[N];
set<pair<ll, int>> s[N];

void dfs(int u, int fa) {
	for (int v : g[u])
		if (v != fa) {
			dfs(v, u);
			if (s[u].size() < s[v].size()) {
				for (const auto &p : s[u])
					s[v].emplace(p.first + cov[u] - cov[v], p.second);
				s[u].swap(s[v]);
				cov[u] = cov[v];
			} else {
				for (const auto &p : s[v])
					s[u].emplace(p.first + cov[v] - cov[u], p.second);
			}
			s[v].clear();
		}
	if (u != 1) {
		while (!s[u].empty() && s[u].begin()->second >= dep[u])
			s[u].erase(s[u].begin());
		if (s[u].empty()) {
			puts("-1");
			exit(0);
		} else {
			ll tmp = s[u].begin()->first + cov[u];
			ans += tmp;
			cov[u] -= tmp;
		}
	}
}

void getdep(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for (int v : g[u]) if (v != fa) getdep(v, u);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	getdep(1, 0);
	for (int i = 1, u, v, c; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &c);
		s[u].emplace(c, dep[v]);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}