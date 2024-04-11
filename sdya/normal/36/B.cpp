#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n;
char c[5][5];
char res[300][300];

void f(int x1, int y1, int x2, int y2)
{
	for (int i = x1; i < x2; i ++)
		for (int j = y1; j < y2; j ++)
			res[i][j] = '*';
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int level;
	scanf("%d%d\n", &n, &level);
	for (int i = 0; i < n; i ++)
		gets(c[i]);

	int m = 1;
	for (int i = 1; i <= level; i ++)
		m *= n;

	for (int i = 0; i < m; i ++)
		for (int j = 0; j < m; j ++)
			res[i][j] = '.';

	int p = m;
	for (int i = 1; i <= level; i ++)
	{
		for (int j = 0; j < m / p; j ++)
			for (int k = 0; k < m / p; k ++)
				if (res[j * p][k * p] == '.')
				{
					for (int i1 = 0; i1 < n; i1 ++)
						for (int j1 = 0; j1 < n; j1 ++)
							if (c[i1][j1] == '*') f(j * p + i1 * (p / n), k * p + j1 * (p / n), j * p + p / n + i1 * (p / n), k * p + p / n + j1 * (p / n));
				}
		p /= n;
	}

	for (int i = 0; i < m; i ++)
		puts(res[i]);
	return 0;
}