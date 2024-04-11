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
		res = (res << 3) + (res << 1) + (c - '0');
	return bo ? ~res + 1 : res;
}

const int N = 150005;

int n, fa[N], ed[N], nxt[N];
bool vis[N];

int cx(int x)
{
	if (fa[x] != x) fa[x] = cx(fa[x]);
	return fa[x];
}

void zm(int x, int y)
{
	int ix = cx(x), iy = cx(y);
	nxt[ed[ix]] = iy; fa[iy] = ix;
	ed[ix] = ed[iy];
}

int main()
{
	int x, y;
	n = read();
	for (int i = 1; i <= n; i++) fa[i] = ed[i] = i;
	for (int i = 1; i < n; i++)
		x = read(), y = read(), zm(x, y);
	for (int i = 1; i <= n; i++) vis[nxt[i]] = 1;
	int Rt;
	for (int i = 1; i <= n; i++) if (!vis[i]) Rt = i;
	while (Rt)
	{
		printf("%d ", Rt);
		Rt = nxt[Rt];
	}
	std::cout << std::endl;
	return 0;
}