#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n, m;
char s[60][60];
bool used[60][60];
vector < pair < int, int > > r[60];

int need[12];
int ans;

int have[60][60];

char a[60][60], b[60][60];

void get(char c, int t)
{
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (s[i][j] == c) r[t].push_back(make_pair(i, j));
}

bool val(int x, int y)
{
	return (0 <= x && x < n && 0 <= y && y < m);
}

bool good()
{
	for (int i = 0; i < 7; i ++)
		for (int j = i; j < 7; j ++)
			have[i][j] = 0;

	for (int i = 0; i < 28; i ++)
	{
		pair < int, int > p = r[i][0], q = r[i][1];
		if (used[p.first][p.second] && used[q.first][q.second])
		{
			int u = a[p.first][p.second] - '0';
			int v = a[q.first][q.second] - '0';
			have[min(u, v)][max(u, v)] ++;
			if (have[min(u, v)][max(u, v)] > 1) return false;
		}
	}
	return true;
}

void rec(int x, int y)
{
	if (x == n)
	{
		if (good())
		{
			cerr << ans << endl;
			ans ++;
			if (ans == 1)
			{
				for (int i = 0; i < n; i ++)
					for (int j = 0; j < m; j ++)
						b[i][j] = a[i][j];
			}
		}
		return ;
	}

	if (y == m) {rec(x + 1, 0); return ;}
	if (used[x][y]) {rec(x, y + 1); return ;}
	if (s[x][y] == '.') {rec(x, y + 1); return ;}
	for (int i = 0; i < 7; i ++)
		if (need[i] == 1)
		{
			used[x][y] = used[x][y + 1] = used[x + 1][y] = used[x + 1][y + 1] = true;
			a[x][y] = a[x][y + 1] = a[x + 1][y] = a[x + 1][y + 1] = '0' + i;
			need[i] ++;
			if (good())
				rec(x, y + 1);
			need[i] --;
			used[x][y] = used[x][y + 1] = used[x + 1][y] = used[x + 1][y + 1] = false;
		} else
			if (need[i] == 0)
			{
				used[x][y] = used[x][y + 1] = used[x + 1][y] = used[x + 1][y + 1] = true;
				a[x][y] = a[x][y + 1] = a[x + 1][y] = a[x + 1][y + 1] = '0' + i;
				need[i] ++;
				if (good())
					rec(x, y + 1);
				need[i] --;
				used[x][y] = used[x][y + 1] = used[x + 1][y] = used[x + 1][y + 1] = false;
				break;
			}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; i ++)
		gets(s[i]);
	for (int i = 0; i < 26; i ++)
		get('a' + i, i);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			a[i][j] = '.';
	get('A', 26);
	get('B', 27);
	rec(0, 0);
	printf("%d\n", ans * 5040);
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < m; j ++)
			printf("%c", b[i][j]);
		printf("\n");
	}
	return 0;
}