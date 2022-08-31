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

const int MAXN = 3005;
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m, q, ans, f[MAXN * (MAXN << 1)], a[MAXN][MAXN << 1];

inline int Idx(int x, int y)
{
	return (y - 1) * n + x;
}

inline int Find(int x)
{
	while (x ^ f[x])
		x = f[x] = f[f[x]];
	return x;
}

inline void Add(int x, int y)
{
	a[x][y] = 1;
	for (int i = 0; i < 8; i ++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 1 || nx > n)
			continue;
		if (ny < 1)
			ny += m << 1;
		if (ny > m << 1)
			ny -= m << 1;
		if (a[nx][ny])
			f[Find(Idx(x, y))] = Find(Idx(nx, ny));
	}
}

inline bool Chk(int x, int y)
{
	for (int i = 0; i < 8; i ++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 1 || nx > n)
			continue;
		if (ny < 1)
			ny += m << 1;
		if (ny > m << 1)
			ny -= m << 1;
		if (a[nx][ny])
			for (int j = 0; j < 8; j ++)
			{
				int mx = x + dx[j], my = y + dy[j] + m;
				if (mx < 1 || mx > n)
					continue;
				if (my < 1)
					my += m << 1;
				if (my > m << 1)
					my -= m << 1;
				if (a[mx][my] && Find(Idx(nx, ny)) == Find(Idx(mx, my)))
					return false;
			}
	}
	return true;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), q = Read();
	if (m == 1)
		return puts("0"), 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m << 1; j ++)
			f[Idx(i, j)] = Idx(i, j);
	while (q --)
	{
		int x = Read(), y = Read();
		if (Chk(x, y))
			ans ++, Add(x, y), Add(x, y + m);
	}
	return printf("%d\n", ans), 0;
}