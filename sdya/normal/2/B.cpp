#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <stdio.h>

using namespace std;

int n;
int a[1100][1100];
int b[1100][1100];
int c[1100][1100];
int d[1100][1100];

int e[1100][1100], have;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		{
			int x;
			scanf("%d", &x);
			if (x == 0) {e[i][j] = have = 1; continue;}
			while (x % 2 == 0) x /= 2, a[i][j] ++;
			while (x % 5 == 0) x /= 5, b[i][j] ++;
		}

	for (int i = 1; i <= n; i ++)
		c[1][i] = c[1][i - 1] + a[1][i],
		d[1][i] = d[1][i - 1] + b[1][i];
	for (int i = 2; i <= n; i ++)
		c[i][1] = c[i - 1][1] + a[i][1],
		d[i][1] = d[i - 1][1] + b[i][1];

	for (int i = 2; i <= n; i ++)
		for (int j = 2; j <= n; j ++)
			c[i][j] = min(c[i - 1][j], c[i][j - 1]) + a[i][j],
			d[i][j] = min(d[i - 1][j], d[i][j - 1]) + b[i][j];

	int best = min(c[n][n], d[n][n]);
	if (best > 1 && have)
	{
		printf("1\n");
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (e[i][j] == 1)
				{
					for (int k = 2; k <= j; k ++)
						printf("R");
					for (int k = 2; k <= n; k ++)
						printf("D");
					for (int k = j + 1; k <= n; k ++)
						printf("R");
					return 0;
				}
		return 0;
	}
	printf("%d\n", best);
	if (c[n][n] == best)
	{
		int x = n, y = n;
		string s = "";
		while (!(x == 1 && y == 1))
			if (x == 1) s += 'R', y --; else
			if (y == 1) s += 'D', x --; else
			if (c[x][y] == c[x - 1][y] + a[x][y]) s += 'D', x --; else s += 'R', y --;
		reverse(s.begin(), s.end());
		cout << s << endl;
	} else
	{
		int x = n, y = n;
		string s = "";
		while (!(x == 1 && y == 1))
			if (x == 1) s += 'R', y --; else
			if (y == 1) s += 'D', x --; else
			if (d[x][y] == d[x - 1][y] + b[x][y]) s += 'D', x --; else s += 'R', y --;
		reverse(s.begin(), s.end());
		cout << s << endl;
	}

	return 0;
}