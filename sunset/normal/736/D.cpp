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

const int MAXN = 2005;
const int MAXM = 500005;

bitset <MAXN << 1> a[MAXN];
int n, m, x[MAXM], y[MAXM];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= m; i ++)
		x[i] = Read(), y[i] = Read(), a[x[i]][y[i]] = 1;
	for (int i = 1; i <= n; i ++)
		a[i][i + n] = 1;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i; j <= n; j ++)
			if (a[j][i])
			{
				swap(a[i], a[j]);
				break;
			}
		for (int j = 1; j <= n; j ++)
			if (i ^ j)
				if (a[j][i])
					a[j] ^= a[i];
	}
	for (int i = 1; i <= m; i ++)
		if (a[y[i]][x[i] + n])
			puts("NO");
		else
			puts("YES");
	return 0;
}