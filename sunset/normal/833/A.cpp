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

int a, b, c;

inline int Cal(LL x)
{
	int l = 1, r = 1000000, ret = 0;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (1LL * mid * mid * mid <= x)
			ret = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	return ret;
}

inline void Sol()
{
	a = Read(), b = Read(), c = Cal(1LL * a * b);
	if (1LL * c * c * c == 1LL * a * b && a % c == 0 && b % c == 0)
		puts("Yes");
	else
		puts("No");
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	for (int T = Read(); T; T --)
		Sol();
	return 0;
}