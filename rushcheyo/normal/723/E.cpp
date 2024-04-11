#include <bits/stdc++.h>
using namespace std;

const int maxn = 205, maxm = maxn * maxn;
int T, n, m, tot, nxt[maxm], to[maxm], fst[maxn], deg[maxn];
bool visv[maxn], vise[maxm], ori[maxm];

void adde(int u, int v)
{
	nxt[++tot] = fst[u]; fst[u] = tot; to[tot] = v;
	nxt[++tot] = fst[v]; fst[v] = tot; to[tot] = u;
}

void dfs(int u)
{
	visv[u] = true;
	for (int i = fst[u]; i; i = nxt[i])
		if (!vise[i + 1 >> 1])
		{
			vise[i + 1 >> 1] = true;
			if (ori[i + 1 >> 1]) printf("%d %d\n", u, to[i]);
			dfs(to[i]);
		}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) visv[i] = fst[i] = deg[i] = 0;
		tot = 0;
		for (int a, b; m--; ) scanf("%d%d", &a, &b), adde(a, b), deg[a]++, deg[b]++, ori[tot >> 1] = true;
		int lst = 0, ans = n;
		for (int i = 1; i <= n; i++)
			if (deg[i] & 1)
			{
				if (!lst) lst = i;
				else adde(i, lst), ori[tot >> 1] = false, lst = 0;
				ans--;
			}
		for (int i = 1; i <= tot >> 1; i++) vise[i] = 0;
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++)
			if (!visv[i]) dfs(i);
	}
	return 0;
}