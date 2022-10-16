#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 4e5 + 5;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, m;
int a[N], v[N];
int *p[N], *vp[N];
int cnt, ans;

int check(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i], yy = y + dy[i];
		if (0 < xx && xx <= n && 0 < yy && yy <= m)
			if (p[xx][yy] < p[x][y])
				return 1;
	}
	return 0;
}

int tryswap(int x, int y, int ban = 0)
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (i == x && j == y)
				continue;
			if (ban)
				if (abs(i - x) + abs(j - y) == 1)
					continue;
			swap(p[x][y], p[i][j]);
			cnt -= vp[x][y];
			vp[x][y] = check(x, y);
			cnt += vp[x][y];
			cnt -= vp[i][j];
			vp[i][j] = check(i, j);
			cnt += vp[i][j];
			for (int o = 0; o < 4; o++)
			{
				int xx, yy;
				xx = x + dx[o], yy = y + dy[o];
				if (0 < xx && xx <= n && 0 < yy && yy <= m)
				{
					cnt -= vp[xx][yy];
					vp[xx][yy] = check(xx, yy);
					cnt += vp[xx][yy];
				}
				xx = i + dx[o], yy = j + dy[o];
				if (0 < xx && xx <= n && 0 < yy && yy <= m)
				{
					cnt -= vp[xx][yy];
					vp[xx][yy] = check(xx, yy);
					cnt += vp[xx][yy];
				}
			}
			if (cnt == n * m - 1)
				ret++;
			swap(p[x][y], p[i][j]);
			cnt -= vp[x][y];
			vp[x][y] = check(x, y);
			cnt += vp[x][y];
			cnt -= vp[i][j];
			vp[i][j] = check(i, j);
			cnt += vp[i][j];
			for (int o = 0; o < 4; o++)
			{
				int xx, yy;
				xx = x + dx[o], yy = y + dy[o];
				if (0 < xx && xx <= n && 0 < yy && yy <= m)
				{
					cnt -= vp[xx][yy];
					vp[xx][yy] = check(xx, yy);
					cnt += vp[xx][yy];
				}
				xx = i + dx[o], yy = j + dy[o];
				if (0 < xx && xx <= n && 0 < yy && yy <= m)
				{
					cnt -= vp[xx][yy];
					vp[xx][yy] = check(xx, yy);
					cnt += vp[xx][yy];
				}
			}
		}
	return ret;
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		p[i] = &a[(i - 1) * m];
		vp[i] = &v[(i - 1) * m];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			vp[i][j] = check(i, j);
			cnt += vp[i][j];
		}
	if (cnt == n * m - 1)
	{
		printf("0\n");
		return;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (p[i][j] != 1 && !vp[i][j])
			{
				ans += tryswap(i, j, 1);
				for (int o = 0; o < 4; o++)
				{
					int x = i + dx[o], y = j + dy[o];
					if (0 < x && x <= n && 0 < y && y <= m)
						ans += tryswap(x, y);
				}
				if (ans)
					printf("1 %d\n", ans);
				else
					printf("2\n");
				return;
			}
	printf("2\n");
}

int main()
{
	int T;
	T = 1; //scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}