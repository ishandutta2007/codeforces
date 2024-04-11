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

int n, ans, a[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = ans = Read();
	int cnt = 0, cur = 0;
	for (int i = 1; i <= n; i ++)
		cnt += (a[i] = Read()) == 1, cur = __gcd(cur, a[i]);
	if (cnt)
		return printf("%d\n", n - cnt), 0;
	if (cur ^ 1)
		return puts("-1"), 0;
	for (int i = 1; i <= n; i ++)
		for (int j = i, x = 0; j <= n; j ++)
			if ((x = __gcd(x, a[j])) == 1)
				ans = min(ans, j - i - 1), j = n;
	return printf("%d\n", ans + n), 0;
}