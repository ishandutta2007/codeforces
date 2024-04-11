#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int N = 5e5 + 5;
vector<int> g[N];
bool ok[N];
int col[N], side[N], id[N], fa[N << 1];
map<pii, vector<pii>> mp;

bool dfs(int p) {
	for (int i: g[p]) {
		if (col[i] != col[p]) continue;
		if (side[i] == -1) {
			side[i] = side[p] ^ 1;
			id[i] = id[p];
			if (!dfs(i)) return false;
		} else if (side[i] != (side[p] ^ 1)) return false;
	}
	return true;
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; ++i) ok[i] = true;
	for (int i = 1; i <= n; ++i) scanf("%d", &col[i]);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
		if (col[x] != col[y]) {
			int u = min(col[x], col[y]), v = max(col[x], col[y]);
			mp[{u, v}].emplace_back(x, y);
		}
	}
	memset(side, -1, sizeof side);
	long long ans = 1ll * k * (k - 1) / 2, cnt = k, num = 0;
	for (int i = 1; i <= n; ++i) {
		if (side[i] == -1 && ok[col[i]]) {
			side[i] = 0;
			id[i] = ++num;
			if (!dfs(i)) ok[col[i]] = false;
		}
	}
	for (int i = 1; i <= k; ++i) if (!ok[i]) ans -= --cnt;
	for (int i = 0; i <= (n << 1) + 5; ++i) fa[i] = i;
	for (auto &pr: mp) {
		auto p = pr.first;
		if (!ok[p.first] || !ok[p.second]) continue;
		auto &e = pr.second;
		for (pii i: e) {
			int x = i.first, y = i.second;
			assert(fa[id[x] << 1 | side[x]] == (id[x] << 1 | side[x]));
			assert(fa[id[y] << 1 | side[y]] == (id[y] << 1 | side[y]));
		}
		for (pii i: e) {
			int x = i.first, y = i.second;
			if (find(id[x] << 1 | side[x]) == find(id[y] << 1 | side[y])) {
				--ans;
				break;
			} else {
				fa[find(id[x] << 1 | side[x])] = find(id[y] << 1 | side[y] ^ 1);
				fa[find(id[y] << 1 | side[y])] = find(id[x] << 1 | side[x] ^ 1);
			}
		}
		for (pii i: e) {
			int x = i.first, y = i.second;
			fa[id[x] << 1 | side[x]] = id[x] << 1 | side[x];
			fa[id[y] << 1 | side[y]] = id[y] << 1 | side[y];
			fa[id[x] << 1 | side[x] ^ 1] = id[x] << 1 | side[x] ^ 1;
			fa[id[y] << 1 | side[y] ^ 1] = id[y] << 1 | side[y] ^ 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}