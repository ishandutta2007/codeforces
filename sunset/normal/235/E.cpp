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

int a, b, c, mu[MAXN];
LL ans;

inline int F(int x, int y)
{
	int ret = 0;
	for (int i = 1; i <= y; i ++)
		if (__gcd(i, x) == 1)
			ret += y / i;
	return ret;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	a = Read(), b = Read(), c = Read(), mu[1] = 1;
	for (int i = 1; i <= b; i ++)
		for (int j = i + i; j <= b; j += i)
			mu[j] -= mu[i];
	for (int i = 1; i <= a; i ++)
		for (int x = 1; x <= b; x ++)
			if (__gcd(i, x) == 1)
				ans += 1LL * mu[x] * (a / i) * F(i, b / x) * F(i, c / x);
	return printf("%d\n", ans & (1 << 30) - 1), 0;
}