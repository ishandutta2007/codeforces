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

int N;
char	a[5005];
int	f[5005], mex[5005];

inline bool	check()
{
	int now = 0, ans = 0;
	for (int i = 1; i <= N; ++ i)
	{
		if (a[i - 1] == a[i + 1] && a[i] != '$')	++ now;
		else
		{
			ans ^= f[now];
			now = 0;
		}
	}
	return ans == 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	scanf("%s", a + 1);
	N = strlen(a + 1);
	f[0] = 0;
	for (int i = 1; i <= N; ++ i)
	{
		for (int j = 1; j <= i; ++ j)
			mex[f[max(j - 1 - 1, 0)] ^ f[max(i - j - 1, 0)]] = i;
		for (int j = 0; ; ++ j)
			if (mex[j] != i)
			{
				f[i] = j;
				break;
			}
	}
	a[0] = '#', a[N + 1] = '%';
	for (int i = 1; i <= N; ++ i)	if (a[i - 1] == a[i + 1])
	{
		char ori = a[i];
		a[i] = '$';
		
		if (check())
		{
			printf("First\n%d\n", i);
			return 0;
		}
		
		a[i] = ori;
	}
	printf("Second\n");

	return 0;
}