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

const int MAXN = 2000005;

int n, m, cnt, b[MAXN], sum[MAXN];
bool use[MAXN];
pii a[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= m; i ++)
	{
		int l = Read(), r = Read() + l - 1;
		a[l] = max(a[l], mp(r, i)), sum[l] ++, sum[r + 1] --;
	}
	for (int i = 1; i <= n; i ++)
		sum[i] += sum[i - 1], b[i] = a[b[i - 1]] > a[i] ? b[i - 1] : i;
	int r = 0;
	for (int i = 1; i <= n; i ++)
		if (i > r && sum[i])
		{
			use[a[i].yy] = 1, r = a[i].xx, cnt ++;
			while (a[b[r + 1]].xx > r)
				use[a[b[r + 1]].yy] = 1, r = a[b[r + 1]].xx, cnt ++;
		}
	printf("%d\n", m - cnt);
	for (int i = 1; i <= m; i ++)
		if (!use[i])
			printf("%d ", i);
	putchar(10);
	return 0;
}