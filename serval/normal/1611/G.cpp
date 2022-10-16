#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 1e6 + 5;

int n, m;
char s[N];
char *p[N];
int nx[N];
int ans;

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		p[i] = &s[(i - 1) * m];
		scanf("%s", p[i] + 1);
	}
	for (int i = 2; i <= n + m; i++)
	{
		int x = i - 1, y = 1;
		nx[i] = 0;
		if (x > n)
		{
			x = n;
			y = i - x;
		}
		while (x > 0 && y <= m)
		{
			if (x <= n)
				if (p[x][y] == '1')
				{
					nx[i] = x;
					break;
				}
			x--;
			y++;
		}
	}
	ans = 0;
	for (int i = 2; i <= n + m; i++)
	{
		if (!nx[i])
			continue;
		ans++;
		int x = 1, y = i - 1;
		while (y > m)
		{
			x++;
			y--;
		}
		while (x <= n)
		{
			if (x > nx[x + y])
			{
				x++;
				if (y == m)
					y--;
				else
					y++;
				continue;
			}
			while (x < nx[x + y])
			{
				p[x][y] = '0';
				x++;
				y--;
			}
			p[x][y] = '0';
			int xx = nx[x + y], yy = x + y - xx;
			while (xx > 0 && yy <= m && p[xx][yy] == '0')
			{
				xx--;
				yy++;
			}
			if (yy > m)
				nx[xx + yy] = 0;
			else
				nx[xx + yy] = xx;
		}
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}