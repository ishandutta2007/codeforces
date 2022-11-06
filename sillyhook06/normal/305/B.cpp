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

int N;
LL	a[100006];

inline bool	work(LL	p, LL q, int k)
{
	if (k == N)	return p / q == a[k] && p % q == 0;
	if (p == 0)	return 0;
	if ((p - 1) / q != a[k])	return 0;
	return work(q, (p - 1) % q + 1, k + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	LL p = read(), q = read();
	N = read();
	for (int i = 1; i <= N; ++ i)	a[i] = read();
	if (work(p, q, 1))	printf("YES\n");
	else	printf("NO\n");

	return 0;
}