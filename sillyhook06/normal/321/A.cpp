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

LL X, Y;
pair<LL, LL>	a[105];
char	s[105];
LL N;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	X = -read(), Y = -read();
	scanf("%s", s + 1);
	N = strlen(s + 1);
	a[0] = make_pair(0, 0);
	LL minX = 0, maxX = 0, minY = 0, maxY = 0;
	for (LL i = 1; i <= N; ++ i)
	{
		if (s[i] == 'U')
		{
			a[i].first = a[i - 1].first;
			a[i].second = a[i - 1].second + 1;
		}
		if (s[i] == 'D')
		{
			a[i].first = a[i - 1].first;
			a[i].second = a[i - 1].second - 1;
		}
		if (s[i] == 'L')
		{
			a[i].first = a[i - 1].first - 1;
			a[i].second = a[i - 1].second;
		}
		if (s[i] == 'R')
		{
			a[i].first = a[i - 1].first + 1;
			a[i].second = a[i - 1].second;
		}
		minX = min(minX, a[i].first);
		maxX = max(maxX, a[i].first);
		minY = min(minY, a[i].second);
		maxY = max(maxY, a[i].second);
	}
	if (X + maxX < 0 && a[N].first)
	{
		LL t = (-maxX - X) / abs(a[N].first);
		X += a[N].first * t;
		Y += a[N].second * t;
	}
	if (X + minX > 0 && a[N].first)
	{
		LL t = (X + minX) / abs(a[N].first);
		X += a[N].first * t;
		Y += a[N].second * t;
	}
	if (Y + maxY < 0 && a[N].second)
	{
		LL t = (- maxY - Y) / abs(a[N].second);
		X += a[N].first * t;
		Y += a[N].second * t;
	}
	if (Y + minY > 0 && a[N].second)
	{
		LL t = (Y + minY) / abs(a[N].second);
		X += a[N].first * t;
		Y += a[N].second * t;
	}
	for (LL t = 0; t <= 100; ++ t)
	{
		for (LL i = 0; i <= N; ++ i)
			if (X + a[i].first == 0 && Y + a[i].second == 0)
				return printf("Yes\n"), 0;
		X += a[N].first, Y += a[N].second;
	}
	printf("No\n");
	
	return 0;
}