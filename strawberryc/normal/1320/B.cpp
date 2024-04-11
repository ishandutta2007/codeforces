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

const int N = 2e5 + 5;

int n, m, ecnt, nxt[N], adj[N], go[N], k, p[N], len, que[N], dis[N], ri[N], ir[N];
bool vis[N], os[N];

std::vector<int> eg[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

void bfs(int S)
{
	vis[que[len = 1] = S] = 1;
	for (int i = 1; i <= len; i++)
	{
		int u = que[i];
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			if (!vis[v]) vis[v] = 1, dis[que[++len] = v] = dis[u] + 1;
	}
}

int main()
{
	int x, y;
	read(n); read(m);
	while (m--) read(x), read(y), add_edge(y, x), eg[x].push_back(y);
	read(k);
	for (int i = 1; i <= k; i++) read(p[i]);
	bfs(p[k]);
	for (int i = 1; i <= k; i++)
	{
		int l = i, r = k;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (mid - i + dis[p[mid]] == dis[p[i]]) l = mid + 1;
			else r = mid - 1;
		}
		ri[i] = r;
	}
	int ans1 = -1, ans2 = 0;
	for (int i = 1; i <= k;) ans1++, i = ri[i] + 1;
	for (int i = 1; i < k; i++)
	{
		int u = p[i];
		for (int j = 0; j < eg[u].size(); j++)
			if (dis[eg[u][j]] + 1 == dis[u] && eg[u][j] != p[i + 1])
				os[i] = 1;
	}
	for (int i = 1; i < k; i++) if (os[i]) ans2++;
	return std::cout << ans1 << " " << ans2 << std::endl, 0;
}