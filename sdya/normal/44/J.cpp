#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

int n, m;
char s[1100][1100];
int color[1100][1100];
int res[1100][1100];
int d[1100][1100];

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

set < pair < int, int > > S;

bool val(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '.');
}

bool val2(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}


int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d\n", &n, &m);
	int w = 0, b = 0;
	for (int i = 0; i < n; i ++)
	{
		gets(s[i]);
		for (int j = 0; j < m; j ++)
			if (s[i][j] == 'w') w ++; else
				if (s[i][j] == 'b') b ++;
	}
	if (w != b + b)
	{
		printf("NO\n");
		return 0;
	}
	for (int x = 0; x < n; x ++)
		for (int y = 0; y < m; y ++)
			if (s[x][y] == 'w')
			{
				for (int k = 0; k < 4; k ++)
					if (val(x + dx[k], y + dy[k]) && val(x + dx[k] + dx[k], y + dy[k] + dy[k]))
						d[x][y] ++;
				S.insert(make_pair(d[x][y], x * 1100 + y));
			}

	int r = 0;
	while (!S.empty())
	{
		int v = S.begin()->second; S.erase(S.begin());
		int x = v / 1100, y = v % 1100;
		if (d[x][y] == 0)
		{
			printf("NO\n");
			return 0;
		} else
		{
			for (int k = 0; k < 4; k ++)
				if (val(x + dx[k], y + dy[k]) && val(x + dx[k] + dx[k], y + dy[k] + dy[k]))
				{
					r ++;
					int nx = x + dx[k] + dx[k], ny = y + dy[k] + dy[k];
					S.erase(make_pair(d[nx][ny], nx * 1100 + ny));
					color[x][y] = r;
					color[nx][ny] = r;
					color[x + dx[k]][y + dy[k]] = r;
					s[x][y] = '.';
					s[nx][ny] = '.';
					s[x + dx[k]][y + dy[k]] = '.';
					for (int l = 0; l < 4; l ++)
						if (val(nx + dx[l], ny + dy[l]) && val(nx + dx[l] + dx[l], ny + dy[l] + dy[l]))
						{
							int px = nx + dx[l] + dx[l], py = ny + dy[l] + dy[l];
							S.erase(make_pair(d[px][py], px * 1100 + py));
							d[px][py] --;
							S.insert(make_pair(d[px][py], px * 1100 + py));
						}
					break;
				}
		}
	}

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (s[i][j] != '.') {printf("NO\n"); return 0;}

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (color[i][j] != 0)
				for (int k = 0; k < 4; k ++)
					if (val2(i + dx[k], j + dy[k]) && val2(i + dx[k] + dx[k], j + dy[k] + dy[k]) &&
						color[i + dx[k]][j + dy[k]] == color[i][j] && color[i + dx[k] + dx[k]][j + dy[k] + dy[k]] == color[i][j])
					{
						int x = i, y = j;
						set < int > bad;
						int nx = i + dx[k] + dx[k], ny = j + dy[k] + dy[k];
						int px = i + dx[k], py = j + dy[k];
						for (int l = 0; l < 4; l ++)
							if (val2(x + dx[l], y + dy[l]))
								bad.insert(res[x + dx[l]][y + dy[l]]);
						for (int l = 0; l < 4; l ++)
							if (val2(nx + dx[l], ny + dy[l]))
								bad.insert(res[nx + dx[l]][ny + dy[l]]);
						for (int l = 0; l < 4; l ++)
							if (val2(px + dx[l], py + dy[l]))
								bad.insert(res[px + dx[l]][py + dy[l]]);
						for (int l = 1; l <= 4; l ++)
							if (bad.count(l) == 0)
							{
								res[x][y] = res[nx][ny] = res[px][py] = l;
								break;
							}
						if (res[x][y] == 0)
						{
							printf("NO\n");
							return 0;
						}
					}

	printf("YES\n");
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
			if (res[i][j] == 0)
				printf("."); else
				printf("%c", res[i][j] - 1 + 'a');
		printf("\n");
	}

	return 0;
}