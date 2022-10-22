#include <bits/stdc++.h>

// 0830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 505, M = N << 1, L = 1e6 + 5, INF = 0x3f3f3f3f;

int n, w[N], q, S, T, ecnt = 1, nxt[L], adj[L], st[L], go[L], cap[L], cost[L], E,
len, que[L], dis[L], pre[L], flow, ans;
bool flag = 1, vis[L];

void add_edge(int u, int v, int w, int x)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; st[ecnt] = u;
	go[ecnt] = v; cap[ecnt] = w; cost[ecnt] = x;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; st[ecnt] = v;
	go[ecnt] = u; cap[ecnt] = 0; cost[ecnt] = -x;
}

bool spfa()
{
	for (int i = S; i <= T; i++) dis[i] = -INF;
	dis[que[len = 1] = S] = 0;
	for (int i = 1; i <= len; i++)
	{
		int u = que[i]; vis[u] = 0;
		for (int e = adj[u], v; e; e = nxt[e])
			if (cap[e] && dis[u] + cost[e] > dis[v = go[e]])
			{
				dis[v] = dis[u] + cost[pre[v] = e];
				if (!vis[v]) vis[que[++len] = v] = 1;
			}
	}
	return dis[T] > -INF / 2;
}

void jiejuediao()
{
	int fl = INF;
	for (int e = pre[T]; e; e = pre[st[e]])
		fl = Min(fl, cap[e]);
	for (int e = pre[T]; e; e = pre[st[e]])
		cap[e] -= fl, cap[e ^ 1] += fl;
	flow += fl; ans += fl * dis[T];
}

struct tree
{
	int Root, ecnt, nxt[M], adj[N], go[M], limit[N], top[N], fa[N];
	
	void add_edge(int u, int v)
	{
		nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
		nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
	}
	
	void dfs(int u, int fu)
	{
		if (fa[u] = fu)
		{
			top[u] = limit[fu] == -1 ? top[fu] : fu;
			if (limit[u] != -1)
			{
				limit[top[u]] -= limit[u];
				if (limit[top[u]] < 0) flag = 0;
			}
		}
		for (int e = adj[u], v; e; e = nxt[e])
			if ((v = go[e]) != fu) dfs(v, u);
	}
} A, B;

int main()
{
	int x, y;
	n = read(); A.Root = read(); B.Root = read();
	for (int i = 1; i <= n; i++) w[i] = read();
	for (int i = 1; i < n; i++)
		x = read(), y = read(), A.add_edge(x, y);
	for (int i = 1; i < n; i++)
		x = read(), y = read(), B.add_edge(x, y);
	memset(A.limit, -1, sizeof(A.limit));
	memset(B.limit, -1, sizeof(B.limit));
	q = read();
	while (q--) A.limit[read()] = read();
	q = read();
	while (q--) B.limit[read()] = read();
	if (A.limit[A.Root] != B.limit[B.Root]) return puts("-1"), 0;
	E = A.limit[A.Root];
	A.dfs(A.Root, 0); B.dfs(B.Root, 0);
	if (!flag) return puts("-1"), 0;
	S = 1; T = (n << 1) + 2;
	for (int u = 1; u <= n; u++)
	{
		if (A.limit[u] == -1) add_edge(1 + A.fa[u], 1 + u, INF, 0);
		else add_edge(S, 1 + u, A.limit[u], 0);
		add_edge(1 + u, 1 + n + u, 1, w[u]);
		if (B.limit[u] == -1) add_edge(1 + n + u, 1 + n + B.fa[u], INF, 0);
		else add_edge(1 + n + u, T, B.limit[u], 0);
	}
	while (spfa()) jiejuediao();
	if (flow < E) puts("-1");
	else std::cout << ans << std::endl;
	return 0;
}