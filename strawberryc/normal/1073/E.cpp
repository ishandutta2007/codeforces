#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

typedef long long ll;

const int N = 20, M = 1030, ZZQ = 998244353, Cm = 1023;

int n, sze[M], a[N], p10[N], f[N][M][2], g[N][M][2], K;
ll l, r;

void add(int &x, int y)
{
	x += y; if (x >= ZZQ) x -= ZZQ;
}

void join(int x, int &res)
{
	int i;
	For (i, 0, Cm) if (sze[i] <= K)
	{
		add(res, g[x][i][0]);
		if (x < n) add(res, g[x][i][1]);
	}
}

int calc(ll N)
{
	if (!N) return 0;
	int i, j, k, t, ans = 0;
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	n = 0;
	while (N) a[++n] = N % 10, N /= 10;
	For (i, 1, 9) f[1][1 << i][i > a[1]]++,
		g[1][1 << i][i > a[1]] += i;
	join(1, ans);
	f[1][1][0]++;
	For (i, 2, n) For (t, 1, 10)
	{
		k = t % 10;
		For (j, 0, Cm)
		{
			if (k < a[i])
			{
				add(f[i][j | (1 << k)][0], (f[i - 1][j][0]
					+ f[i - 1][j][1]) % ZZQ);
				add(g[i][j | (1 << k)][0], (1ll * k * p10[i - 1] % ZZQ
					* (f[i - 1][j][0] + f[i - 1][j][1])
					+ g[i - 1][j][0] + g[i - 1][j][1]) % ZZQ);
			}
			else if (k > a[i])
			{
				add(f[i][j | (1 << k)][1], (f[i - 1][j][0]
					+ f[i - 1][j][1]) % ZZQ);
				add(g[i][j | (1 << k)][1], (1ll * k * p10[i - 1] % ZZQ
					* (f[i - 1][j][0] + f[i - 1][j][1])
					+ g[i - 1][j][0] + g[i - 1][j][1]) % ZZQ);
			}
			else
			{
				add(f[i][j | (1 << k)][0], f[i - 1][j][0]);
				add(f[i][j | (1 << k)][1], f[i - 1][j][1]);
				add(g[i][j | (1 << k)][0], (1ll * k * p10[i - 1] % ZZQ
					* f[i - 1][j][0] + g[i - 1][j][0]) % ZZQ);
				add(g[i][j | (1 << k)][1], (1ll * k * p10[i - 1] % ZZQ
					* f[i - 1][j][1] + g[i - 1][j][1]) % ZZQ);
			}
		}
		if (k == 9) join(i, ans);
	}
	return ans;
}

int main()
{
	int i, j;
	p10[0] = 1;
	For (i, 1, 18) p10[i] = 10ll * p10[i - 1] % ZZQ;
	For (i, 0, Cm) For (j, 0, 9)
		if ((i >> j) & 1) sze[i]++;
	std::cin >> l >> r >> K;
	std::cout << (calc(r) - calc(l - 1) + ZZQ) % ZZQ << std::endl;
	return 0;
}