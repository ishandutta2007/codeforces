#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

string s[6000];
int n, m;

vector < pair < int, int > > up[6000], dn[6000], lt[6000], rt[6000];
vector < int > d[6000];

int calc(int x, int y)
{
	for (int i = 0; i < n; i ++)
		lt[i][0] = make_pair(-1, -1);
	for (int i = 0; i < n; i ++)
		for (int j = 1; j < m; j ++)
			if (s[i][j - 1] != '.') lt[i][j] = make_pair(i, j - 1); else lt[i][j] = lt[i][j - 1];

	for (int i = 0; i < n; i ++)
		rt[i][m - 1] = make_pair(-1, -1);
	for (int i = 0; i < n; i ++)
		for (int j = m - 2; j >= 0; j --)
			if (s[i][j + 1] != '.') rt[i][j] = make_pair(i, j + 1); else rt[i][j] = rt[i][j + 1];

	for (int i = 0; i < m; i ++)
		up[0][i] = make_pair(-1, -1);
	for (int i = 0; i < m; i ++)
		for (int j = 1; j < n; j ++)
			if (s[j - 1][i] != '.') up[j][i] = make_pair(j - 1, i); else up[j][i] = up[j - 1][i];

	for (int i = 0; i < m; i ++)
		dn[n - 1][i] = make_pair(-1, -1);
	for (int i = 0; i < m; i ++)
		for (int j = n - 2; j >= 0; j --)
			if (s[j + 1][i] != '.') dn[j][i] = make_pair(j + 1, i); else dn[j][i] = dn[j + 1][i];

	int res = 0;
	while (true)
	{
		res ++;
		if (s[x][y] == 'L')
		{
			pair < int, int > p = lt[x][y];
			if (p == make_pair(-1, -1)) return res;
			if (rt[x][y] != make_pair(-1, -1)) lt[rt[x][y].first][rt[x][y].second] = lt[x][y];
			if (lt[x][y] != make_pair(-1, -1)) rt[lt[x][y].first][lt[x][y].second] = rt[x][y];
			if (dn[x][y] != make_pair(-1, -1)) up[dn[x][y].first][dn[x][y].second] = up[x][y];
			if (up[x][y] != make_pair(-1, -1)) dn[up[x][y].first][up[x][y].second] = dn[x][y];
			x = p.first, y = p.second;
		} else
		if (s[x][y] == 'R')
		{
			pair < int, int > p = rt[x][y];
			if (p == make_pair(-1, -1)) return res;
			if (rt[x][y] != make_pair(-1, -1)) lt[rt[x][y].first][rt[x][y].second] = lt[x][y];
			if (lt[x][y] != make_pair(-1, -1)) rt[lt[x][y].first][lt[x][y].second] = rt[x][y];
			if (dn[x][y] != make_pair(-1, -1)) up[dn[x][y].first][dn[x][y].second] = up[x][y];
			if (up[x][y] != make_pair(-1, -1)) dn[up[x][y].first][up[x][y].second] = dn[x][y];
			x = p.first, y = p.second;
		} else
		if (s[x][y] == 'U')
		{
			pair < int, int > p = up[x][y];
			if (p == make_pair(-1, -1)) return res;
			if (rt[x][y] != make_pair(-1, -1)) lt[rt[x][y].first][rt[x][y].second] = lt[x][y];
			if (lt[x][y] != make_pair(-1, -1)) rt[lt[x][y].first][lt[x][y].second] = rt[x][y];
			if (dn[x][y] != make_pair(-1, -1)) up[dn[x][y].first][dn[x][y].second] = up[x][y];
			if (up[x][y] != make_pair(-1, -1)) dn[up[x][y].first][up[x][y].second] = dn[x][y];
			x = p.first, y = p.second;
		} else
		if (s[x][y] == 'D')
		{
			pair < int, int > p = dn[x][y];
			if (p == make_pair(-1, -1)) return res;
			if (rt[x][y] != make_pair(-1, -1)) lt[rt[x][y].first][rt[x][y].second] = lt[x][y];
			if (lt[x][y] != make_pair(-1, -1)) rt[lt[x][y].first][lt[x][y].second] = rt[x][y];
			if (dn[x][y] != make_pair(-1, -1)) up[dn[x][y].first][dn[x][y].second] = up[x][y];
			if (up[x][y] != make_pair(-1, -1)) dn[up[x][y].first][up[x][y].second] = dn[x][y];
			x = p.first, y = p.second;
		}
	}

	return res;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		cin >> s[i];
	for (int i = 0; i < n; i ++)
		up[i].resize(m), dn[i].resize(m), lt[i].resize(m), rt[i].resize(m), d[i].resize(m);
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (s[i][j] != '.') d[i][j] = calc(i, j);

	int best = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (s[i][j] != '.' && d[i][j] > best) best = d[i][j];

	int ans = 0;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (s[i][j] != '.' && d[i][j] == best) ans ++;

	printf("%d %d\n", best, ans);

	return 0;
}