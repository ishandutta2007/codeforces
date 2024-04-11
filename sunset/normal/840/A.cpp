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

int n, a[MAXN], c[MAXN];
pii b[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	for (int i = 1; i <= n; i ++)
		b[i] = mp(Read(), i);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	reverse(b + 1, b + n + 1);
	for (int i = 1; i <= n; i ++)
		c[b[i].yy] = a[i];
	for (int i = 1; i <= n; i ++)
		printf("%d%c", c[i], i == n ? '\n' : ' ');
}