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

int n, m, q, c, a[MAXN], b[MAXN];
LL ans;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), q = Read();
	for (int i = 1, x; i <= n; i ++)
		if ((x = Read()) == a[c])
		{
			b[c] ++;
			if (b[c] == m)
				c --;
		}
		else
			c ++, a[c] = x, b[c] = 1;
	if (!c)
		return puts("0"), 0;
	int tot = 0, del = 0, pos = 0;
	for (int i = 1; i <= c; i ++)
		tot += b[i];
	for (int i = 1; i < c + 1 - i; i ++)
		if (a[i] == a[c + 1 - i] && b[i] + b[c + 1 - i] == m)
			del += m;
		else
		{
			pos = i;
			break;
		}
	if (pos)
	{
		if (a[pos] == a[c + 1 - pos] && b[pos] + b[c + 1 - pos] > m)
			del += m;
		ans = 1LL * tot * q - 1LL * del * (q - 1);
	}
	else
	{
		ans = 1LL * b[(c >> 1) + 1] * q % m;
		if (ans)
			ans += tot - b[(c >> 1) + 1];
	}
	cout << ans << endl;
	return 0;
}