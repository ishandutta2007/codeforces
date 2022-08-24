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
const int MAXB = 1002;
const int MAXD = 25;
const int MAXS = 4020000;

int N, B;
int nloc[MAXS][MAXD]; //powers of 4
int dir[MAXB][MAXB];

int xc[4] = {-1, 0, 1, 0};
int yc[4] = {0, -1, 0, 1};
string str = "LDRU";

int x, y, cdir;
char ch;
ll T;

inline void decode (int c)
{
	printf ("%d %d\n", c % MAXB, (c / MAXB) % MAXB);
	//return make_pair (make_pair (c % MAXB, (c / MAXB) % MAXB), c / MAXB / MAXB);
}

inline int encode (int a, int b, int c)
{
	return a + MAXB * b + MAXB * MAXB * c;
}

int main()
{
	for (int i = 0; i < MAXB; i++)
		for (int j = 0; j < MAXB; j++)
			dir[i][j] = -1;
	
	scanf ("%d %d", &N, &B);
	//cin >> N >> B;
	for (int i = 0; i < N; i++)
	{
		int x1, y1, x2, y2;
		scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
		//cin >> x1 >> y1 >> x2 >> y2;
		
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
	
	for (int i = 0; i < MAXS; i++)
		nloc[i][0] = 0;
	
	for (int i = 0; i <= B; i++)
		for (int j = 0; j <= B; j++)
			for (int k = 0; k < 4; k++)
			{
				int ndir = k;
				if (dir[i][j] != -1)
					ndir = dir[i][j];
				
				int nx = i + xc[ndir], ny = j + yc[ndir];
				
				if (nx < 0 || nx > B || ny < 0 || ny > B)
					nx = i, ny = j;
				
				nloc[encode (i, j, k)][0] = encode (nx, ny, ndir);
			}
	
	for (int d = 1; d < MAXD; d++)
		for (int i = 0; i < MAXS; i++)
		{
			int cloc = i;
			for (int j = 0; j < 4; j++)
				cloc = nloc[cloc][d-1];
			
			nloc[i][d] = cloc;
		}
	
	int Q; //cin >> Q;
	scanf ("%d", &Q);
	for (int i = 0; i < Q; i++)
	{
		scanf ("%d %d %c %I64d", &x, &y, &ch, &T);
		//cin >> x >> y >> ch >> T;
		
		for (int j = 0; j < 4; j++)
			if (ch == str[j])
				cdir = j;
		
		int cloc = encode (x, y, cdir);
		
		int dcur = 0;
		while (T)
		{
            //cout << T << " " << (T & 3) << "\n";
			for (int j = 0; j < (T & 3); j++)
				cloc = nloc[cloc][dcur];
			
			T >>= 2;
			dcur++;
		}
		
		
		decode (cloc);
	}
	
	//system ("Pause");
	return 0;
}