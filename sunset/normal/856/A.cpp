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

const int MAXN = 105;
const int MAXM = 1000005;

int n, m, a[MAXN], b[MAXN];
bool f[MAXM];

inline void Solve()
{
	mset(f, 0), n = Read(), m = 0;
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			f[abs(a[i] - a[j])] = 1;
	for (int cur = 1; m < n; cur ++)
	{
		bool flg = true;
		for (int i = 1; i <= m; i ++)
			if (f[cur - b[i]])
				flg = false, i = m;
		if (flg)
			b[++ m] = cur;
	}
	puts("YES");
	for (int i = 1; i <= m; i ++)
		printf("%d%c", b[i], i == n ? '\n' : ' ');
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	for (int T = Read(); T; T --)
		Solve();
	return 0;
}