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

const int N = 101;
const int M = 1000;

int n, ax, ay, bx, by, d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, pre[2005][2005];
char way[4] = {'U', 'D', 'R', 'L'};
bool a[205][205];

inline bool G(int x)
{
	putchar(way[x]);
	ax += d[x][0], ay += d[x][1];
	int cx = bx + d[x][0], cy = by + d[x][1];
	if (cx >= 0 && cx <= N << 1 && cy >= 0 && cy <= N << 1 && a[cx][cy])
		return false;
	return bx = cx, by = cy, true;
}

inline void BFS(int sx, int sy)
{
	queue <pii> q;
	mset(pre, -1), pre[sx + M][sy + M] = 4, q.push(mp(sx, sy));
	while (!q.empty())
	{
		pii x = q.front(); q.pop();
		for (int i = 0; i < 4; i ++)
		{
			int nx = x.xx + d[i][0], ny = x.yy + d[i][1];
			if (nx < -M || ny < -M || nx >= M || ny >= M || ~pre[nx + M][ny + M])
				continue;
			if (nx >= 0 && ny >= 0 && nx <= N << 1 && ny <= N << 1 && a[nx][ny])
				continue;
			pre[nx + M][ny + M] = i, q.push(mp(nx, ny));
		}
	}
}

inline void Follow(int x, int y, int bx, int by, bool f)
{
	vector <int> vec;
	int cx = x, cy = y;
	while ((cx ^ bx) || (cy ^ by))
	{
		int way = pre[cx + M][cy + M];
		vec.pb(way), cx -= d[way][0], cy -= d[way][1];
	}
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i ++)
	{
		if (G(vec[i]) && f)
			vec.pb(vec[i]);
		if (ax == ::bx && ay == ::by)
			return ;
	}
}

inline void Solve()
{
	if (ay > by)
	{
		swap(way[0], way[1]);
		for (int i = 0; i < N; i ++)
			for (int j = 0; j < N << 1; j ++)
				swap(a[j][i], a[j][(N << 1) - i]);
		ay = (N << 1) - ay, by = (N << 1) - by;
	}
	if (ax > bx)
	{
		swap(way[2], way[3]);
		for (int i = 0; i < N; i ++)
			for (int j = 0; j < N << 1; j ++)
				swap(a[i][j], a[(N << 1) - i][j]);
		ax = (N << 1) - ax, bx = (N << 1) - bx;
	}
	BFS(ax, ay), Follow(0, 0, ax, ay, 0);
	for (int i = 0; i < N * 3; i ++)
		G(1);
	BFS(bx, by), Follow(0, 0, bx, by, 0);
	pii pos = mp(1 << 15, 1 << 15);
	for (int i = 0; i < N << 1; i ++)
		for (int j = 0; j < N << 1; j ++)
			if (a[i][j])
				pos = min(pos, mp(j, i));
	swap(pos.xx, pos.yy);
	while (bx ^ pos.xx)
		G(2);
	while ((ay ^ by) || (by ^ pos.yy - 1))
		G(0);
	G(3), G(0);
	while (ax ^ bx)
		G(2);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	ax = Read() + N, ay = Read() + N, bx = Read() + N, by = Read() + N, n = Read();
	if (!n)
		return puts("-1"), 0;
	for (int i = 1, x, y; i <= n; i ++)
		x = Read() + N, y = Read() + N, a[x][y] = 1;
	BFS(ax, ay);
	if (!~pre[bx + M][by + M])
		return puts("-1"), 0;
	if (!~pre[M][M])
		Follow(bx, by, ax, ay, 1);
	else
		Solve();
	putchar(10);
	return 0;
}