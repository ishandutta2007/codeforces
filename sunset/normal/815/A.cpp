#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof x)
#define copy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

const int MAXN = 105;

int n, m, a[MAXN][MAXN], ans1, ans2, p1, p2;

inline bool solve1()
{
	int ans = 0;
	for (int i = 1; i < n; i ++)
	{
		int delta = a[i][1] - a[i + 1][1];
		for (int j = 2; j <= m; j ++)
			if (a[i][j] - a[i + 1][j] ^ delta)
				return 0;
	}
	int p = 1;
	for (int i = 2; i <= n; i ++) if (a[i][1] < a[p][1]) p = i;
	for (int i = 1; i <= m; i ++) ans += a[p][i];
	for (int i = 1; i <= n; i ++) ans += a[i][1] - a[p][1];
	ans1 = ans;
	p1 = p;
	return 1;
}

inline void solve2()
{
	int ans = 0;
	int p = 1;
	for (int i = 2; i <= m; i ++) if (a[1][i] < a[1][p]) p = i;
	for (int i = 1; i <= n; i ++) ans += a[i][p];
	for (int i = 1; i <= m; i ++) ans += a[1][i] - a[1][p];
	ans2 = ans;
	p2 = p;
}


int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = read(), m = read();
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			a[i][j] = read();
	if (!solve1()) return puts("-1"), 0;
	solve2();
	if (ans1 < ans2)
	{
		printf("%d\n", ans1);
		for (int i = 1; i <= n; i ++) while (a[i][1] ^ a[p1][1]) printf("row %d\n", i), a[i][1] --;
		for (int i = 1; i <= m; i ++) while (a[p1][i]) printf("col %d\n", i), a[p1][i] --;
		return 0;
	}
	else
	{
		printf("%d\n", ans2);
		for (int i = 1; i <= m; i ++) while (a[1][i] ^ a[1][p2]) printf("col %d\n", i), a[1][i] --;
		for (int i = 1; i <= n; i ++) while (a[i][p2]) printf("row %d\n", i), a[i][p2] --;
	}
}