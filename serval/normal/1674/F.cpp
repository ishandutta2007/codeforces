#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m, q;
int tot;
int id[N][N];
int a[N][N], b[N][N];
int x, y;
int cnt;

void flip(int x, int y)
{
	//printf("flip %d %d id %d\n", x, y, id[x][y]);
	if (id[x][y] <= tot)
		cnt -= (a[x][y] == b[x][y]);
	tot -= a[x][y];
	a[x][y] ^= 1;
	tot += a[x][y];
	if (id[x][y] <= tot)
		cnt += (a[x][y] == b[x][y]);
}
void move(int p)
{
	if (p < 0)
	{
		x += p;
		if (x < 1)
		{
			x = n;
			y--;
		}
	}
	if (id[x][y] <= tot - p)
		cnt -= (a[x][y] == b[x][y]);
	b[x][y] ^= 1;
	if (id[x][y] <= tot)
		cnt += (a[x][y] == b[x][y]);
	if (p > 0)
	{
		x += p;
		if (x > n)
		{
			x = 1;
			y++;
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	x = 1, y = 1;
	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= n; i++)
			id[i][j] = ++tot;
	tot = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char c;
			scanf("%c", &c);
			while (c != '.' && c != '*')
				scanf("%c", &c);
			if (c == '*')
				flip(i, j);
			if (a[i][j])
				move(1);
			//printf("%d %d tot %d cnt %d\n", i, j, tot, cnt);
		}
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		flip(x, y);
		if (a[x][y])
			move(1);
		else
			move(-1);
		//printf("tot %d cnt %d\n", tot, cnt);
		printf("%d\n", tot - cnt);
	}
	return 0;
}