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

vector<int>	ans;
int a[100006];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	int N = read();
	ans.clear();
	bool	flag1 = 0, flag2 = 0, flag3 = 0;
	for (int i = 1; i <= N; ++ i)
	{
		int x = a[i] = read();
		if (x == 0)	ans.push_back(x);
		if (x && x < 10 && !flag1)	ans.push_back(x), flag1 = 1;
		if (x && x < 100 && x % 10 == 0 && !flag2)	ans.push_back(x), flag2 = 1;
		if (x == 100 && !flag3)	ans.push_back(x), flag3 = 1;
	}
	for (int i = 1; i <= N; ++ i)
	{
		int x = a[i];
		if (x && x < 100 && x % 10 && !flag1 && !flag2)	ans.push_back(x), flag1 = flag2 = 1;
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++ i)
		printf("%d%c", ans[i], i < ans.size() - 1 ? ' ' : '\n');

	return 0;
}