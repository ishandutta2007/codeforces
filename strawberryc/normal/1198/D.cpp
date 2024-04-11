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

const int N = 55, INF = 0x3f3f3f3f;

int n, a[N][N], f[N][N][N][N];
char s[N][N];

bool rect(int l, int r, int u, int v)
{
	return !(a[r][v] - a[l - 1][v] - a[r][u - 1] + a[l - 1][u - 1]);
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1]
				+ (s[i][j] == '#');
	for (int l = n; l >= 1; l--)
		for (int r = l; r <= n; r++)
			for (int a = n; a >= 1; a--)
				for (int b = a; b <= n; b++)
				{
					if (rect(l, r, a, b)) {f[l][r][a][b] = 0; continue;}
					f[l][r][a][b] = r - l == b - a ? r - l + 1 : INF;
					for (int i = l; i < r; i++)
						f[l][r][a][b] = Min(f[l][r][a][b],
							f[l][i][a][b] + f[i + 1][r][a][b]);
					for (int i = a; i < b; i++)
						f[l][r][a][b] = Min(f[l][r][a][b],
							f[l][r][a][i] + f[l][r][i + 1][b]);
				}
	return std::cout << f[1][n][1][n] << std::endl, 0;
}