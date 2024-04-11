#include <bits/stdc++.h>
using namespace std;

int n, m, v[7], e[7][7], st[7], ed[7], fa[7];
pair<int, int> lc[100];

namespace flow {
	const int M = 1005;
	int S, T, tot = 1, nxt[M], fst[M], to[M], f[M], cur[M], d[M];
	void addedge(int u, int v, int w) {
		nxt[++tot] = fst[u]; fst[u] = tot; to[tot] = v; f[tot] = w;
		nxt[++tot] = fst[v]; fst[v] = tot; to[tot] = u; f[tot] = 0;
	}
	bool bfs() {
		static int q[M];
		int st = 0, ed = 0;
		q[ed++] = S;
		for (int i = 1; i <= T; i++) d[i] = -1, cur[i] = fst[i];
		d[S] = 0;
		while (st < ed) {
			int u = q[st++];
			for (int i = fst[u]; i; i = nxt[i])
				if (f[i] > 0 && d[to[i]] == -1) {
					d[to[i]] = d[u] + 1;
					if (to[i] == T) return true;
					q[ed++] = to[i];
				}
		}
		return false;
	}
	int aug(int u, int flow) {
		fprintf(stderr, "%d %d\n", u, flow);
		if (u == T || !flow) return flow;
		int used = 0;
		for (int i = cur[u]; i; i = nxt[i])
			if (f[i] > 0 && d[to[i]] == d[u] + 1) {
				int w = aug(to[i], min(f[i], flow - used));
				if (w > 0) {
					f[i] -= w; if (f[i] > 0) cur[u] = i;
					f[i ^ 1] += w;
					used += w; if (used == flow) break;
				}
			}
		if (!used) d[u] = -1;
		return used;
	}
	int dinic() {
		int ans = 0;
		while (bfs()) ans += aug(S, 1 << 30);
		return ans;
	}
}

int find(int x) {
	return !fa[x] ? x : fa[x] = find(fa[x]);
}

bool check(int e[7][7]) {
	for (int i = 1; i <= flow::T; ++i) flow::fst[i] = 0;
	flow::tot = 1;
	flow::S = m * (m + 1) / 2 + m + 1, flow::T = m * (m + 1) / 2 + m + 2;
	for (int i = 1, idx = 0; i <= m; ++i)
		for (int j = i; j <= m; ++j) {
			if (e[i][j] < 0) return false;
			++idx;
			flow::addedge(idx, m * (m + 1) / 2 + i, 1 << 30);
			if (j != i) flow::addedge(idx, m * (m + 1) / 2 + j, 1 << 30);
			flow::addedge(flow::S, idx, e[i][j]);
		}
	for (int i = 1; i <= m; ++i)
		flow::addedge(m * (m + 1) / 2 + i, flow::T, v[i] - 1);
	int res = flow::dinic();
	return res == n - m;
}

int main() {
	scanf("%d", &n);
	v[m = 1] = min(n, 9);
	if (n >= 10) v[m = 2] = min(n, 99) - 9;
	if (n >= 100) v[m = 3] = min(n, 999) - 99;
	if (n >= 1000) v[m = 4] = min(n, 9999) - 999;
	if (n >= 10000) v[m = 5] = min(n, 99999) - 9999;
	if (n >= 100000) v[m = 6] = n - 99999;
	int sum = 0;
	for (int i = 1; i <= m; ++i)
		st[i] = ed[i] = sum + 1, sum += v[i];
	for (int i = 1; i < n; ++i) {
		static char x[10], y[10];
		scanf("%s%s", x, y);
		int lenx = strlen(x), leny = strlen(y);
		if (lenx > leny) swap(lenx, leny);
		++e[lenx][leny];
	}
	for (int i = 1, idx = 0; i <= m; ++i)
		for (int j = i; j <= m; ++j)
			lc[++idx] = {i, j};
	for (int s = 0; s < 1 << m * (m - 1) / 2; ++s) {
		if (__builtin_popcount(s) != m - 1) continue;
		int tmpe[7][7] = {};
		memcpy(tmpe, e, sizeof e);
		memset(fa, 0, sizeof fa);
		bool flag = true;
		vector<pair<int, int>> cs;
		for (int i = 1, idx = 0; i <= m && flag; ++i)
			for (int j = i + 1; j <= m && flag; ++j, ++idx)
				if (s >> idx & 1) {
					if (find(i) == find(j)) {
						flag = false;
						break;
					}
					fa[find(i)] = find(j);
					cs.emplace_back(i, j);
					--tmpe[i][j];
				}
		if (flag && check(tmpe)) {
			for (const auto &e : cs)
				printf("%d %d\n", st[e.first], st[e.second]);
			for (int j = 2; j <= flow::tot; j += 2) {
				int u = flow::to[j ^ 1], v = flow::to[j];
				if (u >= 1 && u <= m * (m + 1) / 2 && v > m * (m + 1) / 2 && v <= m * (m + 1) / 2 + m)
					while (flow::f[j ^ 1]--)
						printf("%d %d\n", st[lc[u].first + lc[u].second - (v - m * (m + 1) / 2)], ++ed[v - m * (m + 1) / 2]);
			}
			return 0;
		}
	}
	puts("-1");
}