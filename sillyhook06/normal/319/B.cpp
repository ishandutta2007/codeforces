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

int N, a[1000006], f[1000006], top, stack[1000006];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	for (int i = 1; i <= N; ++ i)	a[i] = read();
	int ans = 0;
	top = 0;
	for (int i = N; i; -- i)
	{
		f[i] = 0;
		while (top && a[i] > a[stack[top]])
		{
			int j = stack[top];
			if (f[j] > f[i] + 1)
				f[i] = f[j];
			else
				f[i] = f[i] + 1;
			top --;
		}
		stack[++ top] = i;
		ans = max(ans, f[i]);
	}
	cout << ans << endl;

	return 0;
}