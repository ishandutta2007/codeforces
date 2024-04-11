#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

typedef long long ll;

inline ll readll()
{
	ll res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1e5 + 5, M = 4e5 + 5, B = 64, ZZQ = 1e9 + 7;

int n, m, ecnt, nxt[M], adj[N], go[M], ans, cnt0, cnt1, p2[B];
ll val[M], arr[B], dis[N], arrs[N][B];
bool vis[N];

void ins(ll x)
{
	for (int i = 60; i >= 0; i--)
	{
		if (!((x >> i) & 1)) continue;
		if (arr[i] == -1) return (void) (arr[i] = x);
		else x ^= arr[i];
	}
}

void add_edge(int u, int v, ll w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; val[ecnt] = w;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; val[ecnt] = w;
}

void dfs(int u)
{
	vis[u] = 1;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (!vis[v]) dis[v] = dis[u] ^ val[e], dfs(v);
		else if (e & 1) ins(dis[v] ^ dis[u] ^ val[e]);
}

void calc(int u, int id)
{
	vis[u] = 1;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (!vis[v]) calc(v, id);
	((dis[u] >> id) & 1 ? cnt1 : cnt0)++;
}

int jiejuediao(int id)
{
	memset(vis, 0, sizeof(vis));
	int res = 0;
	for (int i = 1; i <= n; i++) if (!vis[i])
	{
		cnt0 = cnt1 = 0; calc(i, id);
		int bcnt0 = 0, bcnt1 = 0, scnt0 = 0, scnt1 = 0;
		for (int j = 0; j <= 60; j++)
			if (arrs[i][j] != -1)
				((arrs[i][j] >> id) & 1 ? bcnt1 : bcnt0)++;
		if (bcnt1) scnt0 = scnt1 = p2[bcnt0 + bcnt1 - 1];
		else scnt0 = p2[bcnt0];
		res = (1ll * cnt0 * cnt1 % ZZQ * scnt0 + res) % ZZQ;
		res = ((1ll * cnt0 * (cnt0 - 1) + 1ll * cnt1 * (cnt1 - 1) >> 1)
			% ZZQ * scnt1 + res) % ZZQ;
	}
	return res;
}

int main()
{
	int x, y, bas = 1; ll z;
	n = read(); m = read();
	while (m--) x = read(), y = read(), z = readll(),
		add_edge(x, y, z);
	p2[0] = 1;
	for (int i = 1; i <= 60; i++) p2[i] = (p2[i - 1] << 1) % ZZQ;
	for (int i = 1; i <= n; i++) if (!vis[i])
	{
		memset(arr, -1, sizeof(arr));
		dfs(i);
		for (int j = 0; j <= 60; j++) arrs[i][j] = arr[j];
	}
	for (int i = 0; i <= 60; i++)
	{
		ans = (1ll * bas * jiejuediao(i) + ans) % ZZQ;
		bas = (bas << 1) % ZZQ;
	}
	std::cout << ans << std::endl;
	return 0;
}