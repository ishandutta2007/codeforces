#include <bits/stdc++.h>

// 20030830

const int N = 105;

int n;
char s[N];

int main()
{
	while (1)
	{
		puts("next 1"); fflush(stdout);
		scanf("%d", &n);
		while (n--) scanf("%*s");
		puts("next 0 1"); fflush(stdout);
		scanf("%d", &n);
		if (n == 2)
		{
			while (n--) scanf("%*s");
			break;
		}
		else while (n--) scanf("%*s");
	}
	while (1)
	{
		puts("next 0 1 2 3 4 5 6 7 8 9"); fflush(stdout);
		scanf("%d", &n);
		if (n == 1)
		{
			scanf("%*s");
			return puts("done"), fflush(stdout), 0;
		}
		else while (n--) scanf("%*s");
	}
	return 0;
}