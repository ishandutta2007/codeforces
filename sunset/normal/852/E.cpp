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
const int mod = 1e9 + 7;

int n, m, p, q, d[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1, x, y; i < n; i ++)
		x = Read(), y = Read(), d[x] ++, d[y] ++;
	for (int i = 1; i <= n; i ++)
		m += d[i] == 1;
	p = 1;
	for (int i = 1; i <= n - m; i ++)
		p = (p << 1) % mod;
	q = (p << 1) % mod;
	return printf("%d\n", (1LL * q * m + 1LL * p * (n - m)) % mod), 0;
}