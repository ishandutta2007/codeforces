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

int N, a[1000006], S;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read();
	for (int i = 1; i <= N; ++ i)	a[read()] = 1;
	
	S = 1000000;
	
	int wei = 0;
	for (int i = 1; i <= S / 2; ++ i)
		if (a[i] && a[S - i + 1])
			++ wei;
	
	printf("%d\n", N);
	for (int i = 1; i <= S / 2; ++ i)
		if (!a[i] && !a[S - i + 1])
		{
			if (wei)
			{
				printf("%d %d ", i, S - i + 1);
				-- wei;
			}
		}
		else
		{
			if (a[i] && a[S - i + 1])	continue;
			if (a[i])	printf("%d ", S - i + 1);
			else	printf("%d ", i);
		}
	

	return 0;
}