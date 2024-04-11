#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n, m;
char s[1100][1100];
bool good[26];
int k;
int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};
int inv[] = {3, 2, 1, 0};
int p[110000], q[110000];
char c;

int d[1100][1100][4];

bool val(int x, int y)
{
	return (0 <= x && x < n && 0 <= y && y < m && s[x][y] != '#');
}

int solve(int x, int y, int dir)
{
	if (!val(x, y)) return 0;
	if (d[x][y][dir] != -1) return d[x][y][dir];
	d[x][y][dir] = 1 + solve(x + dx[dir], y + dy[dir], dir);
	return d[x][y][dir];
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i ++)
		gets(s[i]);

	memset(d, -1, sizeof(d));

	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < n; j ++)
			for (int k = 0; k < m; k ++)
				solve(j, k, i);


	scanf("%d\n", &k);
	for (int i = 1; i <= k; i ++)
	{
		int u;
		scanf("%c %d\n", &c, &u);
		if (c == 'N') p[i] = 0; else
			if (c == 'W') p[i] = 1; else
				if (c == 'E') p[i] = 2; else
					if (c == 'S') p[i] = 3;
		q[i] = u;
	}

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (s[i][j] >= 'A' && s[i][j] <= 'Z')
			{
				bool gd = true;
				int x = i, y = j;
				for (int l = 1; l <= k; l ++)
					if (d[x][y][p[l]] >= q[l] + 1) x += dx[p[l]] * q[l], y += dy[p[l]] * q[l]; else {gd = false; break;}
				if (gd)
					good[s[i][j] - 'A'] = true;
			}

	int res = 0;
	for (int i = 0; i < 26; i ++)
		if (good[i])
			res ++, printf("%c", 'A' + i);
	if (res == 0)
		printf("no solution\n"); else
		printf("\n");
	return 0;
}