#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

int n, tot, p[755], id[10000005], ch[10000005][2], fail[10000005];
bool vis[1505];
bitset<755> g[755];
char s[10000005];

namespace flow {
	const int V = 2 * 750 + 5, E = (750 * 750 + 750 + 750) * 2 + 5;
	int S, T, tot = 1, nxt[E], fst[V], to[E], f[E], cur[V], d[V];
	void addedge(int u, int v, int w) {
		nxt[++tot] = fst[u]; fst[u] = tot; to[tot] = v; f[tot] = w;
		nxt[++tot] = fst[v]; fst[v] = tot; to[tot] = u; f[tot] = 0;
	}
	bool bfs() {
		static int q[E];
		int st = 0, ed = 0;
		q[ed++] = S;
		for (int i = 1; i <= T; i++) d[i] = -1, cur[i] = fst[i];
		d[S] = 0;
		while (st < ed) {
			int u = q[st++];
			for (int i = fst[u]; i; i = nxt[i])
				if (f[i] && d[to[i]] == -1) {
					d[to[i]] = d[u] + 1;
					if (to[i] == T) return true;
					q[ed++] = to[i];
				}
		}
		return false;
	}
	int aug(int u, int flow) {
		if (u == T || !flow) return flow;
		int used = 0;
		for (int &i = cur[u], w; i; i = nxt[i])
			if (d[to[i]] == d[u] + 1 && (w = aug(to[i], min(f[i], flow - used)))) {
				f[i] -= w, f[i ^ 1] += w;
				if ((used += w) == flow) break;
			}
		if (!used) d[u] = -1;
		return used;
	}
	int dinic() {
		int ans = 0;
		while (bfs()) ans += aug(S, inf);
		return ans;
	}
}

void dfs(int u) {
	using namespace flow;
	vis[u] = true;
	for (int i = fst[u]; i; i = nxt[i])
		if (f[i] && !vis[to[i]]) dfs(to[i]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s + p[i]), p[i + 1] = p[i] + strlen(s + p[i]);
		int u = 0;
		for (int j = p[i]; j < p[i + 1]; ++j) {
			if (!ch[u][s[j] - 'a']) ch[u][s[j] - 'a'] = ++tot;
			u = ch[u][s[j] - 'a'];
		}
		id[u] = i;
	}
	static int q[10000005];
	int st = 0, ed = 0;
	for (int i = 0; i < 2; ++i) if (ch[0][i]) q[ed++] = ch[0][i];
	while (st < ed) {
		int u = q[st++];
		if (!id[u]) id[u] = id[fail[u]];
		else if (id[fail[u]]) g[id[u]][id[fail[u]]] = true;
		for (int i = 0; i < 2; ++i)
			if (ch[u][i]) fail[ch[u][i]] = ch[fail[u]][i], q[ed++] = ch[u][i];
			else ch[u][i] = ch[fail[u]][i];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = p[i], u = 0; j < p[i + 1]; ++j) {
			u = ch[u][s[j] - 'a'];
			if (id[u] && id[u] != i) g[i][id[u]] = true;
		}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			if (g[i][k])
				g[i] |= g[k];
	flow::S = n + n + 1, flow::T = n + n + 2;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (g[i][j]) flow::addedge(i, n + j, inf);
	for (int i = 1; i <= n; ++i) {
		flow::addedge(flow::S, i, 1);
		flow::addedge(i + n, flow::T, 1);
	}
	flow::dinic();
	dfs(flow::S);
	vector<int> ans;
	for (int i = 1; i <= n; ++i)
		if (vis[i] && !vis[i + n]) ans.push_back(i);
	printf("%d\n", (int)ans.size());
	for (int x : ans) printf("%d ", x);
	puts("");
}