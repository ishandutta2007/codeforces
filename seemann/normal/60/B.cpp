#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;
const int mv[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

int n, m, k;
bool use[10][10][10];

bool in_s(int x, int y, int z)
{
	if (x < 0 || x >=k) return false;
	if (y < 0 || y >=n) return false;
	if (z < 0 || z >=m) return false;
	return true;
}

int dfs(int x, int y, int z)
{
	use[x][y][z] = true;
	int ans = 1;
	FOR(i, 6)
	{
		int x1, y1, z1;
		x1 = x + mv[i][0];
		y1 = y + mv[i][1];
		z1 = z + mv[i][2];
		if (in_s(x1, y1, z1) && !use[x1][y1][z1])
			ans += dfs(x1, y1, z1);
	}
	return ans;
}

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	cin >> k >> n >> m;
	clr(use);
	FOR(i, k)
		FOR(j, n)
			FOR(g, m)
			{
				char c;
				scanf(" %c ", &c);
				if (c == '#') use[i][j][g] = true;
			}
	int x, y;
	cin >> x >>y;
	cout << dfs(0, x - 1, y - 1);

	return 0;
}