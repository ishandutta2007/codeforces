#include <bits/stdc++.h>

typedef long long ll;

const int M = 105, E = 65, N = 6222;

int n, m, tot, lc[N], rc[N], sze[N];
char s[M][E];

void jiejuediao(int T, int u, ll rk)
{
	if (!T) return;
	ll szelc = (1ll << T - 1) - sze[lc[u]];
	if (rk <= szelc) putchar('0'), jiejuediao(T - 1, lc[u], rk);
	else putchar('1'), jiejuediao(T - 1, rc[u], rk - szelc);
}

void work()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	tot = 1;
	memset(lc, 0, sizeof(lc)); memset(rc, 0, sizeof(rc));
	memset(sze, 0, sizeof(sze));
	for (int i = 1; i <= n; i++)
	{
		int u = 1;
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '0')
			{
				if (!lc[u]) lc[u] = ++tot;
				sze[u = lc[u]]++;
			}
			else
			{
				if (!rc[u]) rc[u] = ++tot;
				sze[u = rc[u]]++;
			}
	}
	jiejuediao(m, 1, (1ll << m) - n + 1 >> 1);
	puts("");
}

int main()
{
	int T; std::cin >> T;
	while (T--) work();
	return 0;
}