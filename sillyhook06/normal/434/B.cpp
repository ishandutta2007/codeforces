/*
* Problem: 
* Author: Leo Yu
* Time: 
* State: SOLVED
* Memo: 
*/
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
#define right Right
#define left Left

int N, M, Q;
int a[1005][1005];
int left[1005][1005], right[1005][1005];
int up[1005][1005], down[1005][1005];

inline void	row(int i)
{
	left[i][0] = 1;
	for (int j = 1; j <= M; ++ j)
		if (a[i][j])	left[i][j] = left[i][j - 1];
		else	left[i][j] = j + 1;
	right[i][M + 1] = M;
	for (int j = M; j; -- j)
		if (a[i][j])	right[i][j] = right[i][j + 1];
		else	right[i][j] = j - 1;
}

inline void	column(int j)
{
	up[0][j] = 1;
	for (int i = 1; i <= N; ++ i)
		if (a[i][j])	up[i][j] = up[i - 1][j];
		else	up[i][j] = i + 1;
	down[N + 1][j] = N;
	for (int i = N; i; -- i)
		if (a[i][j])	down[i][j] = down[i + 1][j];
		else	down[i][j] = i - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read(), Q = read();
	for (int i = 1; i <= N; ++ i)
	for (int j = 1; j <= M; ++ j)
		a[i][j] = read();
		
	for (int i = 1; i <= N; ++ i)
	{
		row(i);
	}
	
	for (int j = 1; j <= M; ++ j)
	{
		column(j);
	}
	
	while (Q --)
	{
		int op = read(), x = read(), y = read();
		if (op == 1)
		{
			a[x][y] ^= 1;
			row(x);
			column(y);
		}
		else
		{
			int ans = 0;
			int l = left[x][y], r = right[x][y];
			for (int i = x; i <= N; ++ i)
			{
				l = max(l, left[i][y]);
				r = min(r, right[i][y]);
				if (l <= r)	ans = max(ans, (i - x + 1) * (r - l + 1));
				else	break;
			}
			l = left[x][y], r = right[x][y];
			for (int i = x; i; -- i)
			{
				l = max(l, left[i][y]);
				r = min(r, right[i][y]);
				if (l <= r)	ans = max(ans, (x - i + 1) * (r - l + 1));
				else	break;
			}
			l = up[x][y], r = down[x][y];
			for (int j = y; j <= M; ++ j)
			{
				l = max(l, up[x][j]);
				r = min(r, down[x][j]);
				if (l <= r)	ans = max(ans, (j - y + 1) * (r - l + 1));
				else	break;
			}
			l = up[x][y], r = down[x][y];
			for (int j = y; j; -- j)
			{
				l = max(l, up[x][j]);
				r = min(r, down[x][j]);
				if (l <= r)	ans = max(ans, (y - j + 1) * (r - l + 1));
				else	break;
			}
			printf("%d\n", ans);
		}
	}
	

	return 0;
}