#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define fo(p, q, r) for(p = (q); p <= (r); ++p)
#define fow(p, q, r) for(p = (q); p >= (r); --p)
#define arclr(p, q) memset(p, (q), sizeof(p))
using namespace std;

int ys[105][2], enabled[105], lasttwo[2];

int main()
{
	int t;
	scanf("%d", &t);
	char s[5];
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
		{
			printf("? %d %d\n", i * 2 - 1, i * 2);
			fflush(stdout);
			scanf("%s", s);
			ys[i][0] = i * 2 - 1; ys[i][1] = i * 2;
			if (s[0] == '<') swap(ys[i][0], ys[i][1]);
		}
		for(int i = 1; i <= n; ++i) enabled[i] = 1;
		for(int i = 1; i <= n; ++i)
		{
			int mn;
			for(int j = 1; j <= n; ++j)
				if (enabled[j] == 1)
				{
					mn = j;
					break;
				}
			for(int j = mn + 1; j <= n; ++j)
				if (enabled[j] == 1)
				{
					printf("? %d %d\n", ys[mn][1], ys[j][1]);
					fflush(stdout);
					scanf("%s", s);
					if (s[0] == '>') mn = j;
				}
			if (i == n)
			{
				for(int j = 1; j <= n; ++j)
					if (enabled[j] == 0)
					{
						printf("? %d %d\n", ys[mn][1], ys[j][0]);
						fflush(stdout);
						scanf("%s", s);
					}	
			}
			lasttwo[i % 2] = mn;
			enabled[mn] = 0;
			if (i % 2 == 0 && i != n)
			{
				printf("? %d %d\n", ys[lasttwo[0]][0], ys[lasttwo[1]][0]);
				fflush(stdout);
				scanf("%s", s);
				if (s[0] == '>')
				{
					ys[lasttwo[0]][1] = ys[lasttwo[1]][0];
					enabled[lasttwo[0]] = 1;
					enabled[lasttwo[1]] = -1;
				}
				else
				{
					ys[lasttwo[1]][1] = ys[lasttwo[0]][0];
					enabled[lasttwo[0]] = -1;
					enabled[lasttwo[1]] = 1;					
				}
			}
		}
		printf("!\n");
		fflush(stdout);
	}
}