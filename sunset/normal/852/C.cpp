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

int n, a[MAXN], b[MAXN], p[MAXN], q[MAXN];

inline bool Cmp(int x, int y)
{
	return b[x] - a[x] > b[y] - a[y];
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read(), b[i % n + 1] = n - a[i], p[i] = i;
	sort(p + 1, p + n + 1, Cmp);
	for (int i = 1; i <= n; i ++)
		q[p[i]] = i - 1;
	for (int i = 1; i <= n; i ++)
		printf("%d%c", q[i % n + 1], i == n ? '\n' : ' ');
	return 0;
}