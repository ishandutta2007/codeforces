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
inline LL	read()
{
	LL x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

int N, top = 0, stack[100005];
LL	x[100005], y[100005];

int height[100005], fa[100005][20];

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


int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	for (int i = 1; i <= N; ++ i)	x[i] = read(), y[i] = read();
	
	fa[0][0] = 0, height[0] = 0;
	for (int i = N; i; -- i)
	{
		while (top > 1)
		{
			int j = stack[top], k = stack[top - 1];
			if ((y[k] - y[i]) * (x[j] - x[i]) > (y[j] - y[i]) * (x[k] - x[i]))	-- top;
			else	break;
		}
		if (top)	fa[i][0] = stack[top];
		else	fa[i][0] = 0;
		height[i] = height[fa[i][0]] + 1;
		stack[++ top] = i;
	}
	buildLCA();
	
	int Q = read();
	while (Q --)
	{
		int x = read(), y = read();
		printf("%d ", LCA(x, y));
	}

	return 0;
}