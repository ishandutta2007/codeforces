// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int xa, ya, xb, yb;

int main()
{
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
	if (xa == xb)
		printf("%d %d %d %d\n", xa + yb - ya, ya, xa + yb - ya, yb);
	else
		if (ya == yb)
			printf("%d %d %d %d\n", xa, ya + xb - xa, xb, ya + xb - xa);
		else
			if (abs(xa - xb) != abs(ya - yb))
				puts("-1");
			else
				printf("%d %d %d %d\n", xa, yb, xb, ya);
}