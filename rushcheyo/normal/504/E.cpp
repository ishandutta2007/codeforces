#include <bits/stdc++.h>
using namespace std;

const int N = 300005, MOD[2] = {1035534743, 1043802787}, B[2] = {327337, 329191};
int n, m, pw[N][2], size[N], fa[N], dep[N], son[N], top[N], dfn[N], dfs_clock, pos[N];
char s[N];
vector<int> g[N];
array<int, 2> hsh[N], rhsh[N];

void dfs(int u) {
	size[u] = 1;
	for (int v : g[u])
		if (v != fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
			size[u] += size[v];
			if (size[v] > size[son[u]])
				son[u] = v;
		}
}
void divide(int u) {
	dfn[u] = ++dfs_clock, pos[dfs_clock] = u;
	if (son[u]) top[son[u]] = top[u], divide(son[u]);
	for (int v : g[u])
		if (v != fa[u] && v != son[u])
			top[v] = v, divide(v);
}

auto query(array<int, 2> *_hsh, int l, int r) {
	array<int, 2> res;
	for (int i = 0; i < 2; ++i) {
		res[i] = (_hsh[r][i] - 1ll * _hsh[l - 1][i] * pw[r - l + 1][i]) % MOD[i];
		if (res[i] < 0) res[i] += MOD[i];
	}
	return res;
}
auto query(int l, int r) { return l <= r ? query(hsh, l, r) : query(rhsh, n - l + 1, n - r + 1); }

auto get(int a, int b, int &t) {
	vector<pair<int, int>> v1, v2;
	while (top[a] != top[b])
		if (dep[top[a]] > dep[top[b]]) {
			v1.emplace_back(dfn[a], dfn[top[a]]);
			a = fa[top[a]];
		} else {
			v2.emplace_back(dfn[top[b]], dfn[b]);
			b = fa[top[b]];
		}
	if (dep[a] > dep[b])
		v1.emplace_back(dfn[a], dfn[b]), t = b;
	else
		v2.emplace_back(dfn[a], dfn[b]), t = a;
	reverse(v2.begin(), v2.end());
	v1.reserve(v1.size() + v2.size());
	for (const auto &x : v2) v1.push_back(x);
	return v1;
}
auto calc(const vector<pair<int, int>> &v, int len) {
	array<int, 2> res = {};
	int now = 0;
	for (int i = 0; i < (int)v.size() && now != len; ++i) {
		int tmp = min(len - now, abs(v[i].second - v[i].first) + 1);
		const auto &tmpx = query(v[i].first, v[i].first + (v[i].first <= v[i].second ? 1 : -1) * (tmp - 1));
		for (int j = 0; j < 2; ++j)
			res[j] = (1ll * res[j] * pw[tmp][j] + tmpx[j]) % MOD[j];
		now += tmp;
	}
	return res;
}

int main() {
	scanf("%d%s", &n, s + 1);
	for (int c = 0; c < 2; ++c)
		for (int i = pw[0][c] = 1; i <= n; ++i)
			pw[i][c] = 1ll * pw[i - 1][c] * B[c] % MOD[c];
	for (int i = 1, u, v; i < n; ++i) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	top[1] = 1, divide(1);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 2; ++j) {
			hsh[i][j] = (1ll * hsh[i - 1][j] * B[j] + s[pos[i]]) % MOD[j];
			rhsh[i][j] = (1ll * rhsh[i - 1][j] * B[j] + s[pos[n - i + 1]]) % MOD[j];
		}
	scanf("%d", &m);
	for (int a, b, c, d; m--;) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int t1, t2;
		auto p = get(a, b, t1), q = get(c, d, t2);
		t1 = dep[a] + dep[b] - 2 * dep[t1] + 1;
		t2 = dep[c] + dep[d] - 2 * dep[t2] + 1;
		int l = 0, r = min(t1, t2);
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (calc(p, mid) == calc(q, mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}