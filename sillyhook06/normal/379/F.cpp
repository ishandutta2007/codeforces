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

int Q, N, fa[1000006][22], height[1000006];

inline void buildLCA()
{
	for (int i = 1; i < 20; ++ i)
		for (int j = 0; j <= N; ++ j)
			fa[j][i] = fa[fa[j][i - 1]][i - 1];
}
inline int  LCA(int x, int y)
{
	if (height[x] < height[y])  swap(x, y);
	for (int i = height[x] - height[y], j = 0; i; i /= 2, ++ j)
		if (i & 1)  x = fa[x][j];
	if (x == y) return x;
	for (int i = 19; i >= 0; -- i)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

inline int length(int x, int y)
{
	int z = LCA(x, y);
	return height[x] - height[z] + height[y] - height[z];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	Q = read();
	N = 4;
	height[0] = 0, height[1] = 1, height[2] = height[3] = height[4] = 2;
	fa[0][0] = 0, fa[1][0] = 0, fa[2][0] = fa[3][0] = fa[4][0] = 1;
	buildLCA();
	int S = 2, T = 3, ans = 2;
	while (Q --)
	{
		int x = read();
		N ++;
		fa[N][0] = x, height[N] = height[x] + 1;
		for (int i = 1; i < 20; ++ i)
			fa[N][i] = fa[fa[N][i - 1]][i - 1];
		
		N ++;
		fa[N][0] = x, height[N] = height[x] + 1;
		for (int i = 1; i < 20; ++ i)
			fa[N][i] = fa[fa[N][i - 1]][i - 1];
		
		if (length(S, N) > ans)
			ans ++, T = N;
		if (length(T, N) > ans)
			ans ++, S = N;
		printf("%d\n", ans);
	}

	return 0;
}