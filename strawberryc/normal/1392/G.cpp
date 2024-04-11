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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1050000, E = 21;

int n, m, k, c1, c2, p[N][E], a[N], b[N], c[N], d[N], f[N], g[N], ans = -1;
bool vis[N];
char s[E], t[E];

int main()
{
	read(n); read(m); read(k);
	scanf("%s%s", s + 1, t + 1);
	for (int i = 1; i <= k; i++) p[n + 1][i] = i,
		c1 += s[i] == '1', c2 += t[i] == '1';
	for (int i = 1; i <= n; i++) read(a[i]), read(b[i]);
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= k; j++) p[i][j] = p[i + 1][j];
		std::swap(p[i][a[i]], p[i][b[i]]);
	}
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= k; j++)
		{
			if (s[j] == '1') c[i] |= 1 << p[i][j] - 1;
			if (t[j] == '1') d[i] |= 1 << p[i][j] - 1;
		}
	for (int i = 0; i < (1 << k); i++) f[i] = n + 4, g[i] = -n - 4;
	for (int i = 1; i <= n + 1; i++) f[c[i]] = Min(f[c[i]], i),
		g[d[i]] = Max(g[d[i]], i);
	for (int z = 1; z < (1 << k); z <<= 1)
		for (int i = 0; i < (1 << k); i += z << 1)
			for (int j = 0; j < z; j++)
				f[i + j] = Min(f[i + j], f[i + j + z]),
				g[i + j] = Max(g[i + j], g[i + j + z]);
	for (int i = 0; i < (1 << k); i++)
	{
		int cnt = 0;
		for (int j = 1; j <= k; j++) if ((i >> j - 1) & 1) cnt++;
		if (g[i] - f[i] >= m) ans = Max(ans, cnt);
	}
	std::cout << k - (c2 - ans) - (c1 - ans) << std::endl;
	for (int i = 0; i < (1 << k); i++)
	{
		int cnt = 0;
		for (int j = 1; j <= k; j++) if ((i >> j - 1) & 1) cnt++;
		if (g[i] - f[i] >= m && cnt == ans)
			return std::cout << f[i] << " " << g[i] - 1 << std::endl, 0;
	}
	return 0;
}