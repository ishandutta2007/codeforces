#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

int N, M, K, W;
char a[1005][15][15];
int d[1005][1005];
bool	visit[1005];
int dist[1005], pre[1005];
int x[1005], y[1005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read(), K = read(), W = read();
	for (int i = 1; i <= K; ++ i)
	{
		for (int j = 1; j <= N; ++ j)
			scanf("%s", a[i][j] + 1);
	}
	for (int i = 1; i <= K; ++ i)
	for (int j = 1; j <= K; ++ j)
	{
		int c = 0;
		for (int x = 1; x <= N; ++ x)
		for (int y = 1; y <= M; ++ y)
			c += (a[i][x][y] != a[j][x][y]);
		d[i][j] = c * W;
	}
	dist[0] = 0;
	visit[0] = 1;
	for (int i = 1; i <= K; ++ i)	dist[i] = N * M, pre[i] = 0;
	int ans = 0;
	for (int i = 1; i <= K; ++ i)
	{
		int p = -1;
		for (int j = 1; j <= K; ++ j)	if (!visit[j])
			if (p == -1 || dist[j] < dist[p])
				p = j;
		ans += dist[p];
		x[i] = p, y[i] = pre[p];
		visit[p] = 1;
		dist[p] = 0;
		for (int j = 1; j <= K; ++ j)	if (!visit[j])
			if (d[p][j] < dist[j])
				dist[j] = d[p][j], pre[j] = p;
	}
	cout << ans << endl;
	for (int i = 1; i <= K; ++ i)	printf("%d %d\n", x[i], y[i]);

	return 0;
}