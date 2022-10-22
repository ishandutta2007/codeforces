#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 64, M = 1e4 + 5, ZZQ = 1e9 + 7;

ll num;
int k, S, n, p[N], cnt[N], m, f[M][N][N], inv[N], ans = 1;

void add(int &a, int b)
{
	a += b;
	if (a >= ZZQ) a -= ZZQ;
}

int main()
{
	std::cin >> num >> k;
	S = sqrt(num);
	for (int i = 2; i <= S; i++)
	{
		if (num % i) continue;
		p[++n] = i;
		while (num % i == 0) cnt[n]++, num /= i;
		m = Max(m, cnt[n]);
	}
	if (num > 1) cnt[++n] = 1, p[n] = num % ZZQ, m = Max(m, 1);
	inv[1] = 1;
	for (int i = 2; i <= m + 1; i++)
		inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	for (int i = 0; i <= m; i++) f[0][i][i] = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			int sum = f[i - 1][j][j];
			f[i][j][j] = 1ll * inv[j + 1] * sum % ZZQ;
			for (int k = j + 1; k <= m; k++)
			{
				add(sum, f[i - 1][k][j]);
				f[i][k][j] = 1ll * inv[k + 1] * sum % ZZQ;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int delta = 0, pw = 1;
		for (int j = 0; j <= cnt[i]; j++)
		{
			delta = (1ll * pw * f[k][cnt[i]][j] + delta) % ZZQ;
			pw = 1ll * pw * p[i] % ZZQ;
		}
		ans = 1ll * ans * delta % ZZQ;
	}
	std::cout << ans << std::endl;
	return 0;
}