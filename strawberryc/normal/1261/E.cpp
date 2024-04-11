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

const int N = 1005, rqy = 1e9 + 7;

int n, a[N], m, bel[N], sze[N], ans[N][N], T, has[N], tmp[N];

inline bool comp(int a, int b)
{
	return bel[a] < bel[b] || (bel[a] == bel[b] && ans[a][T] < ans[b][T]);
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	std::cout << n + 1 << std::endl;
	for (int i = 1; i <= n + 1; i++) bel[i] = 1;
	m = 1;
	for (int i = 1; i <= n; i++)
	{
		memset(sze, 0, sizeof(sze)); T = i;
		if (m == n + 1)
		{
			for (int j = 1; j <= a[i]; j++) ans[j][i] = 1;
			continue;
		}
		int p, cnt, tot = 0;
		for (int j = 1; j <= n + 1; j++) sze[bel[j]]++;
		for (int j = 1; j <= m; j++) if (sze[j] > 1) p = j;
		for (int j = 1; j < sze[p] && j <= a[i]; j++)
			if (a[i] - j <= n + 1 - sze[p])
				{cnt = j; break;}
		for (int j = 1; j <= n + 1; j++)
			if (bel[j] == p && (++tot) <= cnt) ans[j][i] = 1;
		tot = m = 0;
		for (int j = 1; j <= n + 1; j++)
			if (bel[j] != p && (++tot) <= a[i] - cnt) ans[j][i] = 1;
		for (int j = 1; j <= n + 1; j++) has[j] = j;
		std::sort(has + 1, has + n + 2, comp);
		for (int j = 1; j <= n + 1; j++)
		{
			int u = has[j], v = has[j - 1];
			if (j == 1 || bel[u] != bel[v] || ans[u][i] != ans[v][i]) m++;
			tmp[u] = m;
		}
		for (int j = 1; j <= n + 1; j++) bel[j] = tmp[j];
	}
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 1; j <= n; j++) printf("%d", ans[i][j]);
		puts("");
	}
	return 0;
}