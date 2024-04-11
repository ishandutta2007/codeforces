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
priority_queue<int>	Q;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	for (int i = 1; i <= N; ++ i)	Q.push(-read());
	int last = -1, ans = 0;
	while (!Q.empty())
	{
		int now = -Q.top();
		Q.pop();
		if (!Q.empty() && -Q.top() == now)
		{
			Q.pop();
			Q.push(-(now + 1));
		}
		else
		{
			ans += now - last - 1;
			last = now;
		}
	}
	cout << ans << endl;

	return 0;
}