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

char s[10];
int n, h;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	scanf("%s", s);
	if (s[0] == 'B')
		return printf("%d\n", Read()), 0;
	n = Read(), h = Read();
	double ans = n, t = 1;
	for (int i = 1; i <= h; i ++)
	{
		t = t * 0.5;
		double cur = 1, p = 1 - t;
		for (int j = 1; j < n; j ++)
			ans += (n - j) * t * cur * (1 - 0.5 * (1 + (j - 1) / (1 / t - 1))), cur *= p;
	}
	return printf("%.9lf\n", ans), 0;
}