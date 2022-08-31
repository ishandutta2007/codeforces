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

const int MAXN = 105;

int a[MAXN], b[MAXN], n;
LL ans, m;

inline bool Chk(LL x)
{
	LL ret = 0;
	for (int i = 1; i <= n; i ++)
		ret += ((b[i] + 1) * x - a[i]) % x;
	return ret <= m;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(); cin >> m;
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	for (int i = 1, f = 1; f; i ++)
	{
		f = 0;
		for (int j = 1; j <= n; j ++)
			if (b[j] = a[j] / i)
				f = 1;
		LL p = 1LL << 40, c = 0, d = m, e = 0;
		for (int j = 1; j <= n; j ++)
			if (b[j])
				p = min(p, (LL)a[j] / b[j]);
		if (Chk(i))
			ans = i;
		for (int j = 1; j <= n; j ++)
			c += b[j] + 1, d += a[j];
		e = d / c;
		if (e > i && e < p)
			ans = e;
		if (Chk(p))
			ans = p;
		i = p;
	}
	cout << ans << endl;
	return 0;
}