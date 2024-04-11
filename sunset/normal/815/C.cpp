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

const int MAXN = 5005;

int f[2][MAXN][MAXN], n, size[MAXN], a[MAXN], b[MAXN], c;
vector < int > G[MAXN];

inline void dfs(int x, int fa = 0)
{
	size[x] = 1;
	for (auto y : G[x]) dfs(y, x), size[x] += size[y];
	f[1][x][0] = c + 1; f[1][x][1] = min(c + 1, b[x]);
	f[0][x][0] = 0; f[0][x][1] = min(c + 1, a[x]);
	for (int i = 2; i <= size[x]; i ++) f[0][x][i] = f[1][x][i] = c + 1;
	size[x] = 1;
	for (auto y : G[x])
	{
		for (int i = size[x]; ~i; i --)
			for (int j = size[y]; ~j; j --)
				f[0][x][i + j] = min(f[0][x][i + j], f[0][x][i] + f[0][y][j]), f[1][x][i + j] = min(f[1][x][i + j], f[1][x][i] + min(f[0][y][j], f[1][y][j]));
		size[x] += size[y];
	}
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = read(), c = read();
	for (int i = 1; i <= n; i ++)
	{
		a[i] = read(), b[i] = a[i] - read();
		if (i ^ 1) G[read()].pb(i);
	}
	dfs(1);
	for (int i = n; ~i; i --) if (min(f[1][1][i], f[0][1][i]) <= c) return printf("%d\n", i), 0;
}