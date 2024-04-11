#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
const int MAXB = 35;

int N, B;
int dir[MAXB][MAXB];
int seen[MAXB][MAXB][4];
int ltime[MAXB][MAXB][4];
int cq;

int xc[4] = {-1, 0, 1, 0};
int yc[4] = {0, -1, 0, 1};
string str = "LDRU";

int x, y, cdir;
int t;
bool bfound;

void sim ()
{
	seen[x][y][cdir] = cq;
	ltime[x][y][cdir] = t;
	
	if (dir[x][y] != -1)
		cdir = dir[x][y];
	
	int nx = x + xc[cdir], ny = y + yc[cdir];
	if (nx < 0 || ny < 0 || nx > B || ny > B)
	{
		bfound = true;
		return;
	}
	x = nx;
	y = ny;
	
}

int main()
{
	for (int i = 0; i < MAXB; i++)
		for (int j = 0; j < MAXB; j++)
		{
			dir[i][j] = -1;
			for (int k = 0; k < 4; k++)
				seen[i][j][k] = -1;
		}
	
	cin >> N >> B;
	for (int i = 0; i < N; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		if (x1 == x2)
		{
			if (y1 < y2)
			{
				for (int j = y1; j <= y2; j++)
					dir[x1][j] = 3;
			}
			else
			{
				for (int j = y2; j <= y1; j++)
					dir[x1][j] = 1;
			}
		}
		else
		{
			if (x1 < x2)
				for (int j = x1; j <= x2; j++)
					dir[j][y1] = 2;
			else
				for (int j = x2; j <= x1; j++)
					dir[j][y1] = 0;
		}
	}
	
	int Q; cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		bfound = false;
		cq = i;
		char ch;
		ll T;
		cin >> x >> y >> ch >> T;
		
		for (int j = 0; j < 4; j++)
			if (ch == str[j])
				cdir = j;
		
		if (T < 4000)
		{
			for (int j = 0; j < T; j++)
			{
				sim();
				if (bfound) break;
			}
			cout << x << " " << y << "\n";
		}
		else
		{
			for (int j = 0; j < 4000; j++)
			{
				t = j;
				sim();
				if (bfound) break;
				
				bool check = false;
				if (seen[x][y][cdir] == cq)
				{
					int cval = j + 1 - ltime[x][y][cdir];
					T %= cval;
					while (T + cval < j + 1)
						T += cval;
					
					for (int k = 0; k <= B; k++)
						for (int l = 0; l <= B; l++)
							for (int m = 0; m < 4; m++)
							{
								if (seen[k][l][m] == cq && ltime[k][l][m] == T)
								{
									cout << k << " " << l << "\n";
									check = true;
									break;
								}
							}
				}
				if (check) break;
			}
			if (bfound) cout << x << " " << y << "\n";
		}
	}
	return 0;
}