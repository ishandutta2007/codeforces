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

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	int n = Read();
	double x = 0, y = 0, a = 2 * acos(-1) / n, l = 500;
	if (n <= 4)
		return puts("No solution"), 0;
	for (int i = 1; i <= n - 2; i ++)
		printf("%lf %lf\n", x, y), l += 0.01, x += l * cos(a * i), y += l * sin(a * i);
	printf("%lf %lf\n", x, y);
	return printf("%lf %lf\n", x - y / tan(a * (n - 1)), 0.0), 0;
}