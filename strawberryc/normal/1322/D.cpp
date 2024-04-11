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
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 2005, M = N << 1, INF = 0x3f3f3f3f;

int n, m, l[N], s[N], c[M], cnt[M], f[N][N], g[N][N];
bool vis[N];

std::vector<int> pt[M];

int main()
{
	read(n); read(m); m += n;
	for (int i = 1; i <= n; i++) read(l[i]), cnt[l[i]]++, pt[l[i]].push_back(i);
	for (int i = 1; i <= n; i++) read(s[i]);
	for (int i = 1; i <= m; i++) read(c[i]);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		f[i][j] = -INF;
	for (int i = 1; i <= n; i++) f[i][0] = 0;
	for (int i = 1; i <= m; i++)
	{
		memset(vis, 0, sizeof(vis));
		for (int j = 0; j < pt[i].size(); j++) vis[pt[i][j]] = 1;
		cnt[i] += cnt[i - 1];
		for (int j = n; j >= 1; j--)
		{
			for (int k = cnt[i]; k >= 0; k--)
				if (g[j][k] = k <= cnt[i - 1] ? f[j][k] : -INF, j < n)
					g[j][k] = Max(g[j][k], g[j + 1][k]);
			if (vis[j]) for (int k = cnt[i]; k >= 1; k--)
				g[j][k] = Max(g[j][k], g[j][k - 1] - s[j]);
		}
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k <= (cnt[i] >> 1); k++)
				f[j][k] = -INF;
			for (int k = 0; k <= cnt[i]; k++)
				f[j][k >> 1] = Max(f[j][k >> 1], g[j][k] + k * c[i]);
		}
		cnt[i] >>= 1;
	}
	return std::cout << f[1][0] << std::endl, 0;
}