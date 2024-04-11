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

const int MAXN = 100005;

int n, m, t, T, a[MAXN], l[MAXN], f[MAXN];

inline void Solve()
{
	for (int i = 1; i <= n; i ++)
		a[i] = l[i] = Read();
	sort(l + 1, l + n + 1), m = unique(l + 1, l + n + 1) - l - 1;
	if (t >= m)
	{
		printf("%d\n", m);
		return ;
	}
	for (int i = 1; i <= n; i ++)
		a[i] = lower_bound(l + 1, l + m + 1, a[i]) - l;
	for (int i = 1; i <= m; i ++)
		f[i] = 0;
	for (int j = 1; j <= t; j ++)
		for (int i = 1; i <= n; i ++)
			for (int k = a[i]; k <= m; k ++)
				if (f[k] < f[a[i] - 1] + 1)
					f[k] = f[a[i] - 1] + 1;
				else
					break;
	printf("%d\n", f[m]);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	T = Read(), n = Read(), Read(), t = Read();
	while (T --)
		Solve();
	return 0;
}