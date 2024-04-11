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

int N, a[1005][1005];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	for (int i = 1; i <= N; ++ i)
	for (int j = 1; j <= N; ++ j)
		a[i][j] = read() & 1;
		
	int ans = 0;
	for (int i = 1; i <= N; ++ i)
		ans = (ans + a[i][i]) & 1;
	
	int Q = read();
	while (Q --)
	{
		int t = read();
		if (t == 3)	printf("%d", ans);
		else
		{
			int i = read();
			ans = (ans + a[i][i]) & 1;
			a[i][i] ^= 1;
			ans = (ans + a[i][i]) & 1;
		}
	}

	return 0;
}