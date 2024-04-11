/*
* Problem:
* Author: Leo Yu
* Time:
* State:
* Memo:
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
inline int   read()
{
	int x = 0;	char ch = getchar();	bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())  if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())    x = x * 10 + ch - '0';
	return positive ? x : -x;
}

char s[1000006];
bool	flag[1000006];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	scanf("%s", s);
	int N = strlen(s);
	reverse(s, s + N);
	s[N ++] = '0', s[N ++] = '0';
	int ans = 0;
	for (int i = 0; i < N; ++ i)	if (s[i] == '1')
	{
		if (s[i + 1] == '1')
		{
			int j = i;
			for (; s[j] == '1'; ++ j)	s[j] = '0';
			s[j] = '1';
			flag[i] = 1;
		}
		++ ans;
	}
	printf("%d\n", ans);
	for (int i = 0; i < N; ++ i)	if (s[i] == '1')	printf("+2^%d\n", i);
	for (int i = 0; i < N; ++ i)	if (flag[i])	printf("-2^%d\n", i);

	return 0;
}