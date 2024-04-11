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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	LL	x = read(), y = read(), m = read();
	if (x >= m || y >= m)	return printf("0\n"), 0;
	if (x <= 0 && y <= 0)	return printf("-1\n"), 0;
	if (x < y)	swap(x, y);
	LL	ans = 0;
	if (y < 0)
	{
		ans += (-y) / x;
		y += ans * x;
	}
	while (x < m && y < m)
	{
		if (x < y)	swap(x, y);
		y += x;
		ans ++;
	}
	cout << ans << endl;

	return 0;
}