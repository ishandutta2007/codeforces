#include <bits/stdc++.h>

// 20030830

char s[10];

int main()
{
	while (1)
	{
		scanf("%s", s + 1);
		if (s[1] == 'e') break;
		int th = 1, l, r = 0;
		while (1)
		{
			l = r; r = l + th;
			if (l) th <<= 1;
			printf("? %d %d\n", l, r);
			fflush(stdout);
			scanf("%s", s + 1);
			if (s[1] == 'x') break;
		}
		while (l + 1 < r)
		{
			int mid = l + r >> 1;
			printf("? %d %d\n", l, mid);
			fflush(stdout);
			scanf("%s", s + 1);
			if (s[1] == 'y') l = mid;
			else r = mid;
		}
		printf("! %d\n", r);
		fflush(stdout);
	}
	return 0;
}