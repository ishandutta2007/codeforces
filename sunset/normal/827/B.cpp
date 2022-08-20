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

const int MAXN = 200005;

int n, m, a[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	int t = n - m - 1;
	for (int i = 1; i <= m; i ++)
		a[i] += t / m;
	for (int i = 1; i <= t % m; i ++)
		a[i] ++;
	printf("%d\n", a[1] + a[2] + 2);
	for (int i = 1, cur = m + 1; i <= m; i ++)
	{
		int lst = 1;
		for (int j = 1; j <= a[i]; j ++)
			printf("%d %d\n", lst, ++ cur), lst = cur;
		printf("%d %d\n", lst, i + 1);
	}
	return 0;
}