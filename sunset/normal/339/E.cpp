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

const int MAXN = 1005;

int n, l[5], r[5], a[MAXN];

inline void DFS(int x)
{
	bool flg = true;
	for (int i = 1; i <= n && flg; i ++)
		if (a[i] ^ i)
			flg = false;
	if (flg)
	{
		printf("%d\n", x);
		for (int i = x - 1; ~i; i --)
			printf("%d %d\n", l[i], r[i]);
		exit(0);
	}
	if (x == 3)
		return ;
	for (int i = 1; i <= n; i ++)
		if ((a[i] ^ i) && ((abs(a[i] - a[i + 1]) ^ 1) || (abs(a[i] - a[i - 1]) ^ 1)))
			for (int j = i + 1; j <= n; j ++)
				if ((a[j] ^ j) && ((abs(a[j] - a[j + 1]) ^ 1) || (abs(a[j] - a[j - 1]) ^ 1)))
				{
					reverse(a + i, a + j + 1);
					l[x] = i, r[x] = j;
					DFS(x + 1);
					reverse(a + i, a + j + 1);
				}
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), a[0] = a[n + 1] = -1;
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	DFS(0);
	return 0;
}