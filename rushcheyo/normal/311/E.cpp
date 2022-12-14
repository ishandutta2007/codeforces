#include <bits/stdc++.h>
using namespace std;

const int N = 10005, M = 2005, K = 11, inf = 0x3f3f3f3f, V = N + M, E = 2 * (N + M * K);

int n, m, g, ans, a[N], tot = 1, S, T, nxt[E], fst[V], to[E], f[E], h[V], cur[V];

void addedge(int u, int v, int w) {
	nxt[++tot] = fst[u]; fst[u] = tot; to[tot] = v; f[tot] = w;
	nxt[++tot] = fst[v]; fst[v] = tot; to[tot] = u; f[tot] = 0;
}

bool bfs() {
	for (int i = 1; i <= n + m + 2; i++) cur[i] = fst[i], h[i] = -1;
	static int q[V];
	int l = 0, r = 0;
	q[r++] = S;
	h[S] = 0;
	while (l < r) {
		int u = q[l++];
		for (int i = fst[u]; i; i = nxt[i])
			if (f[i] > 0 && h[to[i]] == -1) {
				h[to[i]] = h[u] + 1;
				if (to[i] == T) return true;
				q[r++] = to[i];
			}
	}
	return false;
}

int aug(int u, int flow) {
	if (!flow || u == T) return flow;
	int used = 0;
	for (int i = cur[u]; i; i = nxt[i])
		if (f[i] > 0 && h[to[i]] == h[u] + 1) {
			int t = aug(to[i], min(flow - used, f[i]));
			if (f[i] -= t) cur[u] = i;
			f[i ^ 1] += t;
			if ((used += t) == flow) break;
		}
	if (!used) h[u] = -1;
	return used;
}

int main() {
	scanf("%d%d%d", &n, &m, &g);
	S = n + m + 1, T = n + m + 2;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1, v; i <= n; i++) {
		scanf("%d", &v);
		if (a[i] == 0) addedge(S, i, v);
		else addedge(i, T, v);
	}
	for (int i = 1, j, x, y, w, k; i <= m; i++) {
		scanf("%d%d%d", &x, &w, &k);
		ans += w;
		while (k--) {
			scanf("%d", &j);
			if (x == 0) addedge(n + i, j, inf);
			else addedge(j, n + i, inf);
		}
		scanf("%d", &y);
		if (x == 0) addedge(S, n + i, w + y * g);
		else addedge(n + i, T, w + y * g);
	}
	while (bfs()) ans -= aug(S, inf);
	printf("%d\n", ans);
	return 0;
}