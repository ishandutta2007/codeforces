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

inline int Solve()
{
	int n = Read(), ret = 0;
	if (n & 1)
		n -= 9, ret ++;
	if ((n & 3) == 2)
		n -= 6, ret ++;
	if (n < 0)
		return -1;
	if (n || ret)
		return ret + n / 4;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	for (int T = Read(); T; T --)
		printf("%d\n", Solve());
	return 0;
}