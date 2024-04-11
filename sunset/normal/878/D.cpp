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
const int MAXM = 4100;

int n, m, q, c, a[12][MAXN];
bitset <MAXM> b[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	m = Read(), n = c = Read(), q = Read();
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			a[i][j] = Read();
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < 1 << n; j ++)
			if (j >> i & 1)
				b[i][j] = 1;
	for (int i = 1, opt, x, y; i <= q; i ++)
		if ((opt = Read()) == 1)
			x = Read() - 1, y = Read() - 1, b[n ++] = b[x] | b[y];
		else if (opt == 2)
			x = Read() - 1, y = Read() - 1, b[n ++] = b[x] & b[y];
		else
		{
			x = Read() - 1, y = Read() - 1;
			int ans = 0;
			for (int j = 0; j < c; j ++)
			{
				int cur = 0;
				for (int k = 0; k < c; k ++)
					if (a[k][y] >= a[j][y])
						cur |= 1 << k;
				if (b[x][cur])
					ans = max(ans, a[j][y]);
			}
			printf("%d\n", ans);
		}
	return 0;
}