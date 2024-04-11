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

const int N = 105, INF = 0x3f3f3f3f;

int n, a[N], f[N][N][2], m0, m1;
bool pro[N][2];

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i]);
		if (a[i]) pro[i][(a[i] & 1) ^ 1] = 1;
	}
	memset(f, INF, sizeof(f));
	if (!pro[1][0]) f[1][0][0] = 0;
	if (!pro[1][1]) f[0][1][1] = 0;
	m0 = n >> 1; m1 = n - m0;
	for (int i = 0; i <= m0; i++)
		for (int j = 0; j <= m1; j++)
		{
			if (i + j <= 1) continue;
			if (i && !pro[i + j][0]) f[i][j][0] = Min(f[i - 1][j][0],
				f[i - 1][j][1] + 1);
			if (j && !pro[i + j][1]) f[i][j][1] = Min(f[i][j - 1][1],
				f[i][j - 1][0] + 1);
		}
	return std::cout << Min(f[m0][m1][0], f[m0][m1][1]) << std::endl, 0;
}