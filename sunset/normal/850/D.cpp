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

const int MAXN = 65;
const int MAXM = 705;

int n, tp, a[MAXN], ret[MAXN], per[MAXN], adj[MAXN][MAXN], f[MAXN][MAXN][MAXM];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 0; i < n; i ++)
		a[i] = Read();
	sort(a, a + n);
	mset(f, -1);
	f[0][0][0] = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < MAXN; j ++)
			for (int k = 0; k < MAXM; k ++)
				if (~f[i][j][k])
					if (k + a[i] - j >= 0)
						f[i][j + 1][k + a[i] - j] = f[i + 1][j + 1][k + a[i] - j] = i;
	for (int i = 1; i < MAXN; i ++)
		if (~f[n][i][0])
		{
			int m = i, p = n, q = i, r = 0;
			while (q)
				ret[++ tp] = a[f[p][q][r]], p = f[p][q][r], q --, r = r + q - a[p];
			printf("%d\n", m);
			reverse(ret + 1, ret + tp + 1);
			for (int i = 1; i <= m; i ++)
			{
				int cnt = 0;
				for (int j = i + 1; j <= m; j ++)
					per[++ cnt] = j;
				sort(per + 1, per + cnt + 1, [&](int x, int y) { return ret[x] < ret[y]; });
				for (int j = 1; j <= cnt; j ++)
					if (ret[i])
						ret[i] --, adj[i][per[j]] = 1;
					else
						ret[per[j]] --, adj[per[j]][i] = 1;
			}
			for (int i = 1; i <= m; i ++, putchar(10))
				for (int j = 1; j <= m; j ++)
					putchar(adj[i][j] + '0');
			return 0;
		}
	return puts("=("), 0;
}