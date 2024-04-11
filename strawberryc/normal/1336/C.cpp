#include <bits/stdc++.h>

const int N = 3005, djq = 998244353;

int n, m, f[N][N], ans;
char s[N], t[N];

int main()
{
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1); m = strlen(t + 1);
	for (int i = 1; i <= n + 1; i++) f[i][i - 1] = 1;
	for (int l = n; l >= 1; l--)
		for (int r = l; r <= n; r++)
		{
			if (l > m || s[r - l + 1] == t[l]) f[l][r] += f[l + 1][r];
			if (r > m || s[r - l + 1] == t[r]) f[l][r] += f[l][r - 1];
			if (f[l][r] >= djq) f[l][r] -= djq;
			if (l == 1 && r >= m)
				ans = (ans + f[l][r]) % djq;
		}
	return std::cout << ans << std::endl, 0;
}