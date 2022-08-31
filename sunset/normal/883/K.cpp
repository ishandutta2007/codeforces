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

const int MAXN = 200005;

int n, l[MAXN], r[MAXN];
LL ans;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
	{
		l[i] = Read(), r[i] = Read() + l[i], ans -= l[i];
		if (i ^ 1)
		{
			int L = l[i - 1] - 1, R = r[i - 1] + 1;
			if (R < l[i] || L > r[i])
				return puts("-1"), 0;
			l[i] = max(l[i], L), r[i] = min(r[i], R);
		}
	}
	for (int i = n - 1; i; i --)
	{
		int L = l[i + 1] - 1, R = r[i + 1] + 1;
		if (R < l[i] || L > r[i])
			return puts("-1"), 0;
		l[i] = max(l[i], L), r[i] = min(r[i], R);
	}
	for (int i = 1; i <= n; i ++)
		ans += r[i];
	cout << ans << endl;
	for (int i = 1; i <= n; i ++)
		printf("%d%c", r[i], i == n ? '\n' : ' ');
	return 0;
}