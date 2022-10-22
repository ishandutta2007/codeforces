#include <bits/stdc++.h>

const int N = 705, djq = 1e9 + 7;

int n, f[N][N][2], a[N], g[10][N], pw[N], ans;
char s[N];

inline void add(int &a, const int &b) {if ((a += b) >= djq) a -= djq;}

int main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) a[i] = s[n - i + 1] - '0';
	for (int d = 0; d < 10; d++)
	{
		f[0][0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= i; j++) f[i][j][0] = f[i][j][1] = 0;
			for (int j = 0; j < i; j++)
				for (int c = 0; c < 10; c++)
				{
					add(f[i][j + (c >= d)][c > a[i]], f[i - 1][j][0]);
					add(f[i][j + (c >= d)][c >= a[i]], f[i - 1][j][1]);
				}
		}
		for (int i = 0; i <= n; i++) g[d][i] = f[n][i][0];
	}
	pw[1] = 1;
	for (int i = 2; i <= n; i++) pw[i] = 10ll * pw[i - 1] % djq;
	for (int i = 2; i <= n; i++) add(pw[i], pw[i - 1]);
	for (int d = 0; d < 10; d++)
	{
		int delta = 0;
		for (int i = 0; i <= n; i++)
		{
			delta = (1ll * pw[i] * g[d][i] + delta) % djq;
			if (d < 9) delta = (delta - 1ll * pw[i] * g[d + 1][i] % djq + djq) % djq;
		}
		ans = (1ll * delta * d + ans) % djq;
	}
	return std::cout << ans << std::endl, 0;
}