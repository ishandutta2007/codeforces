#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 842, M = 2e6 + 5;
const double INF = 1e20;

int n, X[N], Y[N], S, T, ecnt = 1, nxt[M], adj[N], st[M], go[M], cap[M],
len, que[M], pre[N];
double cost[M], dis[N], res, ans;
bool vis[N];

int which(int x, int op) {return (x << 1) + op;}

void add_edge(int u, int v, int w, double x)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; st[ecnt] = u;
	go[ecnt] = v; cap[ecnt] = w; cost[ecnt] = x;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; st[ecnt] = v;
	go[ecnt] = u; cap[ecnt] = 0; cost[ecnt] = -x;
}

bool spfa()
{
	for (int i = S; i <= T; i++) dis[i] = INF;
	dis[que[len = 1] = S] = 0;
	for (int i = 1; i <= len; i++)
	{
		int u = que[i]; vis[u] = 0;
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			if (cap[e] && dis[u] + cost[e] < dis[v])
			{
				dis[que[++len] = v] = dis[u] + cost[pre[v] = e];
				if (!vis[v]) vis[que[++len] = v] = 1;
			}
	}
	return dis[T] < INF;
}

void wzadxzz()
{
	int fl = 0x3f3f3f3f;
	for (int e = pre[T]; e; e = pre[st[e]])
		fl = Min(fl, cap[e]);
	for (int e = pre[T]; e; e = pre[st[e]])
		cap[e] -= fl, cap[e ^ 1] += fl;
	res += fl; ans += dis[T] * fl;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(X[i]), read(Y[i]);
	S = 1; T = n + 1 << 1;
	for (int i = 1; i <= n; i++)
		add_edge(S, which(i, 0), 2, 0), add_edge(which(i, 1), T, 1, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (Y[i] > Y[j]) add_edge(which(i, 0), which(j, 1), 1,
				sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j])));
	while (spfa()) wzadxzz();
	if (res < n - 1) return puts("-1"), 0;
	return printf("%.12lf\n", ans), 0;
}