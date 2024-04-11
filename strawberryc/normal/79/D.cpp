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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 1e4 + 5, E = 25, M = 205, C = (1 << 20) + 5, INF = 0x3f3f3f3f;

int n, k, m, arr[N], a[M], tot, w[E], g[E][E], dis[N], len, que[N],
f[C], Cm, dn[C];

void bfs(int S)
{
	memset(dis, INF, sizeof(dis));
	dis[que[len = 1] = S] = 0;
	for (int i = 1; i <= len; i++)
	{
		int u = que[i];
		for (int j = 1; j <= m; j++)
		{
			int v = u + a[j];
			if (v < 1 || v > n + 1 || dis[v] < INF) continue;
			dis[que[++len] = v] = dis[u] + 1;
		}
	}
}

int main()
{
	n = read(); k = read(); m = read();
	for (int i = 1; i <= k; i++) arr[read()] = 1;
	for (int i = n; i; i--) arr[i] ^= arr[i - 1];
	for (int i = 1; i <= m; i++)
		a[i] = read(), a[i + m] = -a[i];
	m <<= 1;
	for (int i = 1; i <= n; i++)
		if (arr[i]) w[++tot] = i;
	for (int i = 1; i <= tot; i++)
	{
		bfs(w[i]);
		for (int j = 1; j <= tot; j++)
			g[i][j] = dis[w[j]];
	}
	bfs(n + 1);
	memset(f, INF, sizeof(f));
	f[0] = 0;
	Cm = 1 << tot;
	for (int i = 1; i <= tot; i++) dn[1 << i - 1] = i;
	for (int S = 1; S < Cm; S++)
	{
		int id = dn[S & -S], T = S ^ (S & -S);
		f[S] = Min(f[S], f[T] + dis[w[id]]);
		for (int i = 1; i <= tot; i++)
			if ((T >> i - 1) & 1)
				f[S] = Min(f[S], f[T ^ (1 << i - 1)] + g[id][i]);
	}
	printf("%d\n", f[Cm - 1] == INF ? -1 : f[Cm - 1]);
	return 0;
}