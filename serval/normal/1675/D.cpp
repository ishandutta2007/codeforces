#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int h[N], nx[N];
int p[N];
int top[N], hs[N], cnt;
int rt;

void dfs(int u, int t)
{
	if (t)
		top[++cnt] = u;
	hs[u] = h[u];
	if (hs[u])
		dfs(hs[u], 0);
	for (int i = nx[h[u]]; i; i = nx[i])
		dfs(i, 1);
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		h[i] = nx[i] = hs[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		if (p[i] == i)
		{
			rt = i;
			continue;
		}
		nx[i] = h[p[i]];
		h[p[i]] = i;
	}
	cnt = 0;
	dfs(rt, 1);
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
	{
		int cur = top[i];
		int len = 0;
		while (cur)
		{
			cur = hs[cur];
			len++;
		}
		printf("%d\n", len);
		cur = top[i];
		while (len--)
		{
			printf("%d%c", cur, " \n"[len == 0]);
			cur = hs[cur];
		}
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}