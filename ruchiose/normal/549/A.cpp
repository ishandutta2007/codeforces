// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#define i64 long long
#define d64 long double
using namespace std;

int N, M;

char ch[55][55];

bool Find(int x, int y, char c)
{
	int dx, dy;
	fortodo(dx, -1, 0)
		fortodo(dy, -1, 0)
			if (ch[x + dx][y + dy] == c)
				return true;
	return false;
}

int main()
{
	int i, j;
	scanf("%d%d", &N, &M);
	fortodo(i, 1, N)
		scanf("%s", ch[i] + 1);
	int ANS = 0;
	fortodo(i, 2, N)
		fortodo(j, 2, M)
			{
				if (!Find(i, j, 'a')) continue;
				if (!Find(i, j, 'c')) continue;
				if (!Find(i, j, 'e')) continue;
				if (!Find(i, j, 'f')) continue;
				ANS++;
			}
	printf("%d\n", ANS);
	return 0;
}