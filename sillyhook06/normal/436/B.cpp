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

int N, M, K;
char	a[2005][2005];
int	cnt[2005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read(), K = read();
	for (int i = 1; i <= N; ++ i)
		scanf("%s", a[i] + 1);
	for (int i = 1; i <= N; ++ i)
	for (int j = 1; j <= M; ++ j)
		if (a[i][j] == 'L')
		{
			if (j - i + 1 > 0)	cnt[j - i + 1] ++;
		}
		elif (a[i][j] == 'R')
		{
			if (j + i - 1 <= M)	cnt[j + i - 1] ++;
		}
		elif (a[i][j] == 'U')
		{
			if (i % 2)	cnt[j] ++;
		}
	for (int i = 1; i <= M; ++ i)	printf("%d%c", cnt[i], i < M ? ' ' : '\n');

	return 0;
}