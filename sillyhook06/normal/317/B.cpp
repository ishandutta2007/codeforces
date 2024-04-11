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

int d = 1500;
int N, T;
int a[3005][3005];
int b[3005][3005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif

	N = read(), T = read();
	a[d][d] = N;
	int M = 0;
	for (int i = 1; ; ++ i)
	{
		int m = M;
		for (int x = d - M - 1; x <= d + M + 1; ++ x)
		for (int y = d - M - 1; y <= d + M + 1; ++ y)
		{
			b[x][y] = a[x][y] % 4 + a[x - 1][y] / 4 + a[x][y - 1] / 4 + a[x + 1][y] / 4 + a[x][y + 1] / 4;
			if (b[x][y])	m = max(m, x - d);
		}
		M = m;
		bool	flag = 0;
		for (int x = d - M - 1; x <= d + M + 1; ++ x)
		for (int y = d - M - 1; y <= d + M + 1; ++ y)
		{
			if (a[x][y] != b[x][y])	flag = 1;
			a[x][y] = b[x][y];
		}
		if (!flag)	break;
	}
	//printf("%d", M);
	while (T --)
	{
		int x = read(), y = read();
		if (abs(x) > M || abs(y) > M)
			printf("0\n");
		else
			printf("%d\n", a[x + d][y + d]);
	}

	return 0;
}