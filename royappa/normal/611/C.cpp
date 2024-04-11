#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include <string.h>

using namespace std;


typedef long long LL;

int hcount[500][500], wcount[500][500];

void preprocess(vector<string>& grid)
{
	int h = grid.size(), w = grid[0].size();

	memset(hcount, 0, sizeof(hcount));
	memset(wcount, 0, sizeof(wcount));

	for (int i = 0; i < h; i++)
	{
		for (int j = w-2; j >= 0; j--)
		{
			hcount[i][j] = hcount[i][j+1];
			if (grid[i][j] == '.' && grid[i][j+1] == '.')
			{
				hcount[i][j]++;
			}
		}
	}

	for (int j = 0; j < w; j++)
	{
		for (int i = h-2; i >= 0; i--)
		{
			wcount[i][j] = wcount[i+1][j];
			if (grid[i][j] == '.' && grid[i+1][j] == '.')
			{
				wcount[i][j]++;
			}
		}
	}
}

int f(int r1, int c1, int r2, int c2, int h, int w)
{
	int tot = 0;
	for (int i = r1; i <= r2; i++)
	{
		tot += hcount[i][c1]-hcount[i][c2];
	}
	for (int j = c1; j <= c2; j++)
	{
		tot += wcount[r1][j]-wcount[r2][j];
	}
	return tot;
}

int main()
{
	int h, w;
	cin >> h >> w;

	vector<string> grid(h);
	for (int i = 0; i < h; i++)
	{
		cin >> grid[i];
	}

	preprocess(grid);

	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		cout << f(r1, c1, r2, c2, h, w) << endl;
	}
}