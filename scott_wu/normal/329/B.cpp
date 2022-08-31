#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int R, C;
int grid[MAXN][MAXN];
int xstart, ystart;
int xend, yend;

int bdist[7][MAXN][MAXN];
bool bseen[7][MAXN][MAXN];

int xc[4] = {-1, 0, 1, 0};
int yc[4] = {0, -1, 0, 1};

vector <pair <int, int> > q;

void solve (int cloc, int cstart, int cend)
{
	q.clear();
	
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
		{
			bdist[cloc][i][j] = 1e9;
			bseen[cloc][i][j] = false;
		}
	bdist[cloc][cstart][cend] = 0;
	bseen[cloc][cstart][cend] = true;
	
	q.push_back (make_pair (cstart, cend));
	
	for (int i = 0; i < q.size(); i++)
	{
		int xcur = q[i].first, ycur = q[i].second;
		
		for (int j = 0; j < 4; j++)
		{
			int nx = xcur + xc[j], ny = ycur + yc[j];
			if (grid[nx][ny] >= 0 && !bseen[cloc][nx][ny])
			{
				bseen[cloc][nx][ny] = true;
				bdist[cloc][nx][ny] = bdist[cloc][xcur][ycur] + 1;
				q.push_back (make_pair (nx, ny));
			}
		}
	}
}

int main()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			grid[i][j] = -1;
	
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			char ch; cin >> ch;
			
			if (ch == 'T')
				grid[i][j] = -1;
			else if (ch == 'S')
			{
				xstart = i;
				ystart = j;
				grid[i][j] = 0;
			}
			else if (ch == 'E')
			{
				xend = i;
				yend = j;
				grid[i][j] = 0;
			}
			else
				grid[i][j] = (int) ch - '0';
		}
	
	solve (4, xend, yend);
	int ans = 0;
	for (int j = 1; j <= R; j++)
		for (int k = 1; k <= C; k++)
			if (grid[j][k] > 0)
				if (bdist[4][j][k] <= bdist[4][xstart][ystart])
					ans += grid[j][k];

	
	cout << ans << "\n";
	return 0;
}