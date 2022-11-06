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

const int INF = 1 << 30;

int N;
struct	POINT //pascalrecord 
{
	int x, y;
}	a[305];

int	det(POINT a, POINT b, POINT c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("quadrilateral.in", "r", stdin);
	freopen("quadrilateral.out", "w", stdout);
#endif

	N = read();
	for (int i = 1; i <= N; ++ i)
		a[i].x = read(), a[i].y = read();
	int ans = 0;
	for (int i = 1; i <= N; ++ i)
		for (int j = i + 1; j <= N; ++ j)
		{
			int MIN = INF, MAX = -INF;
			for (int k = i + 1; k <= N; ++ k)	if (k != j)
			{
				int D = det(a[i], a[j], a[k]);
				MIN = min(MIN, D);
				MAX = max(MAX, D);
			}
			ans = max(ans, MAX - MIN);
		}
	printf("%.15lf\n", ans / 2.);

	return 0;
}