#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 10000005;

int n, p_cnt, p[MAXN], phi[MAXN], minp[MAXN], cnt[MAXN];

inline LL Solve0()
{
	int x = 1, cnt;
	while (x <= p_cnt && p[x] * 2 <= n)
		x ++;
	cnt = p_cnt + 1 - x;
	return n - 1 + 1LL * cnt * (n - cnt - 1) + 1LL * cnt * (cnt - 1) / 2;
}

inline LL Solve1()
{
	LL ret = 1LL * n * (n - 1) / 2;
	for (int i = 2; i <= n; i ++)
		ret -= phi[i];
	return ret;
}

inline LL Solve2()
{
	LL ret = 0;
	for (int i = 2; i <= n; i ++)
		cnt[minp[i]] ++;
	for (int i = 2; i <= n; i ++)
		cnt[i] += cnt[i - 1];
	for (int i = 2, j = n; i <= n; i ++)
	{
		while (i * j > n)
			j --;
		if (i > j)
			break;
		ret += 1LL * (cnt[i] - cnt[i - 1]) * (cnt[j] - cnt[i]) + 1LL * (cnt[i] - cnt[i - 1] - 1) * (cnt[i] - cnt[i - 1]) / 2;
	}
	return ret;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	if (n == 1)
		return puts("0"), 0;
	for (int i = 2; i <= n; i ++)
	{
		if (!minp[i])
			p[++ p_cnt] = minp[i] = i, phi[i] = i - 1;
		for (int j = 1; i * p[j] <= n; j ++)
		{
			minp[i * p[j]] = min(minp[i], p[j]);
			phi[i * p[j]] = phi[i] * (p[j] - 1);
			if (i % p[j] == 0)
			{
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
	LL ans0 = Solve0(), ans1 = Solve1(), ans2 = Solve2() - ans1, ans3 = 1LL * n * (n - 1) / 2 - ans0 - ans1 - ans2;
	cout << ans1 + ans2 * 2 + ans3 * 3 << endl;
	return 0;
}