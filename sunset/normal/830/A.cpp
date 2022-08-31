#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pii;

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

int n, m, p, ans = INT_MAX, a[MAXN], b[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), p = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	for (int i = 1; i <= m; i ++)
		b[i] = Read();
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	for (int i = 0; i <= m - n; i ++)
	{
		int cur = 0;
		for (int j = 1; j <= n; j ++)
			cur = max(cur, abs(b[i + j] - a[j]) + abs(p - b[i + j]));
		ans = min(ans, cur);
	}
	return printf("%d\n", ans), 0;
}