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

int N, a[100005], b[100005];
LL	f[100005];
struct	node
{
	LL	k, b;
	node (LL _k = 0, LL _b = 0) : k(_k), b(_b)	{}
}	stack[100005];
int	top;

inline LL calc(node a, LL x)
{
	return a.k * x + a.b;
}
inline double cross(node a, node b)
{
	return (b.b - a.b) * 1. / (a.k - b.k);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	for (int i = 1; i <= N; ++ i)	a[i] = read();
	for (int i = 1; i <= N; ++ i)	b[i] = read();
	f[1] = 0;
	stack[top = 1] = node(b[1], 0);
	for (int i = 2, now = 1; i <= N; ++ i)
	{
		now = min(now, top);
		while (now < top && calc(stack[now + 1], a[i]) < calc(stack[now], a[i]))	now ++;
		f[i] = calc(stack[now], a[i]);
		node x(b[i], f[i]);
		while (top > 1 && cross(stack[top - 1], x) <= cross(stack[top - 1], stack[top])) -- top;
		stack[++ top] = x;
	}
	cout << f[N] << endl;

	return 0;
}