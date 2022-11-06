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

char	s[1000007];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	gets(s);
	int N = strlen(s);
	unsigned char last = 0;
	for (int i = 0; i < N; ++ i)
	{
		unsigned char ch = 0, x = s[i];
		for (int i = 0; i < 8; ++ i)	if (x & (1 << i))
			ch += 1 << (8 - i - 1);
		last -= ch;
		printf("%d\n", last);
		last = ch;
	}

	return 0;
}