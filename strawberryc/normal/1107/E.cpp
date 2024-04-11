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

typedef long long ll;

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 105;

int n, a[N], cnt[N][N][2];
char s[N];
ll f[N][N][N][2], g[N][N];

int main()
{
	n = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int l = n; l >= 1; l--)
		for (int r = l; r <= n; r++)
		{
			cnt[l][r][0] = cnt[l + 1][r][0] + (s[l] == '0');
			cnt[l][r][1] = cnt[l][r - 1][1] + (s[r] == '1');
			for (int i = 2; i <= cnt[l][r][s[r] == '1']; i++)
				f[l][r][i][s[r] == '1'] =
					f[l][r - 1][i - 1][s[r] == '1'] + a[i] - a[i - 1];
			f[l][r][1][s[r] == '1'] = g[l][r - 1] + a[1];
			for (int op = 0; op <= 1; op++)
				for (int i = 1; i <= cnt[l][r][op]; i++)
					for (int mid = l + 1; mid <= r; mid++)
						if (cnt[l][mid - 1][op] >= i)
							f[l][r][i][op] = Max(f[l][r][i][op],
								f[l][mid - 1][i][op] + g[mid][r]);
			for (int i = 1; i <= cnt[l][r][0]; i++)
				g[l][r] = Max(g[l][r], f[l][r][i][0]);
			for (int i = 1; i <= cnt[l][r][1]; i++)
				g[l][r] = Max(g[l][r], f[l][r][i][1]);
		}
	std::cout << g[1][n] << std::endl;
	return 0;
}