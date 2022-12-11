#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cmath>

using namespace std;

#define ll long long
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for (int a = 0; (a) < (b); ++a)
#define iter(a) typeof(a.begin())
#define foreach(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define sqr(a) (a)*(a)
#define PI 2.0*acos(0.0)

const int INF = 1000000001;
const double EPS = 1e-8;
const int mv[9][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 0}};

char m[9][9];
char wm[9][9];

bool use[9][9][2000];

struct st{
	int x, y;
	int t;
};

st q[1000000];


int main()
{
//	freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	FOR(i, 8)
		FOR(j, 8)
			scanf(" %c", &m[7 - i][j]);


	clr(use);
	use[0][0][0] = true;
	int p1 = 0;
	int p2 = 1;
	q[0].x = 0;
	q[0].y = 0;
	q[0].t = 0;
	while (p1 < p2)
	{
		FOR(i, 9)
		{
			int x = q[p1].x + mv[i][0];
			int y = q[p1].y + mv[i][1];
			if (x < 0 || y < 0 || x >= 8 || y >= 8)
				continue;
			if (m[x][y] == 'S' || (x < 7 && m[x + 1][y] == 'S'))
				continue;
			if (use[x][y][q[p1].t + 1])
				continue;
			q[p2].x = x;
			q[p2].y = y;
			q[p2].t = q[p1].t + 1;
			use[x][y][q[p2].t] = true;
			if (x == 7 && y == 7)
			{
				printf("WIN");
				return 0;
			}
			p2++;
		}
		if (p1 + 1 != p2 && q[p1].t < q[p1 + 1].t)
		{
			clr(wm);
			FOR(i, 8)
				FOR(j, 8)
					if (m[i][j] == 'S' && i > 0)
						wm[i - 1][j] = 'S';
			FOR(i, 8)
				FOR(j, 8)
					m[i][j] = wm[i][j];
		}
		p1++;
	}
	printf("LOSE");


	return 0;
}