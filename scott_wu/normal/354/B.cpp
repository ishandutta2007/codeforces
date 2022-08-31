#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 22;
const int MAXP = (1 << 20) + 100;

int N;
char ctable[MAXN][MAXN];
int res[2 * MAXN][MAXP];
int nbox[2*MAXN];
int kval[27];

map <pair <int, int>, vector <int> > cmap;
vector <int> v;

int rres[2*MAXN][MAXP];
char cval[2*MAXN][MAXP];

int sval (char ch)
{
	if (ch == 'a') return 1;
	if (ch == 'b') return -1;
	return 0;
}

int main()
{
	for (int i = 0; i < 2 * MAXN; i++)
		for (int j = 0; j < MAXP; j++)
			res[i][j] = rres[i][j] = -10000;
	
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ctable[i][j];
	
	/*for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (i + j < N - 1 || ((i + j == N - 1) && i < j))
				swap (ctable[i][j], ctable[N-1-i][N-1-j]);*/
	
	//for (int i = 0; i < N; i++)
	//	for (int j = 0; j < N; j++)
	//		cout << ctable[i][j] << "\n";
	
	res[0][1] = sval (ctable[0][0]);
	cval[0][1] = ctable[0][0];
	
	for (int i = 0; i < 2 * N; i++)
		nbox[i] = N - abs (N - 1 - i);
	
	for (int i = 0; i < 2 * N - 2; i++)
		for (int j = 1; j < (1 << nbox[i]); j++)
			if (res[i][j] != -10000)
			{
				v.clear();
				
				for (int k = 0; k < 27; k++)
					kval[k] = 0;
				
				for (int k = 0; k < nbox[i+1]; k++)
				{
					if (i < N - 1)
					{
						if ((k && (j & (1 << (k - 1)))) || (j & (1 << k)))
							kval[ctable[i+1-k][k] - 'a'] += (1 << k);
					}
					else
					{
						if ((j & (1 << k)) || (j & (1 << (k + 1))))
							kval[ctable[N-1-k][i+k+2-N] - 'a'] += (1 << k);
					}
				}
				
				for (int k = 0; k < 27; k++)
					if (kval[k])
					{
						v.push_back (kval[k]);
						if (res[i+1][kval[k]] == -10000)
							res[i+1][kval[k]] = res[i][j] + sval ('a' + k);
						else
						{
							if (i % 2)
								res[i+1][kval[k]] = min (res[i+1][kval[k]], res[i][j] + sval ('a' + k));
							else
								res[i+1][kval[k]] = max (res[i+1][kval[k]], res[i][j] + sval ('a' + k));
						}
						
						cval[i+1][kval[k]] = 'a' + k;
					}
				
				cmap[make_pair (i, j)] = v;
			}
	
	rres[2*N-2][1] = sval (ctable[N-1][N-1]);
	for (int i = 2 * N - 3; i >= 0; i--)
	{
		for (int j = 1; j < (1 << nbox[i]); j++)
		{
			if (res[i][j] != -10000)
			{
				rres[i][j] = -10000;
				for (int k = 0; k < cmap[make_pair (i, j)].size(); k++)
				{
					int nval = cmap[make_pair (i, j)][k];
					
					//cout << i << " " << j << " " << nval << "\n";
					
					if (rres[i+1][nval] != -10000)
					{
						if (rres[i][j] == -10000)
							rres[i][j] = rres[i+1][nval] + sval (cval[i][j]);
						else
						{
							if (i % 2)
								rres[i][j] = max (rres[i][j], rres[i+1][nval] + sval (cval[i][j]));
							else
								rres[i][j] = min (rres[i][j], rres[i+1][nval] + sval (cval[i][j]));
						}
					}
				}
			}
		}
	}
	
	//cout << rres[0][1] << "\n";
	if (rres[0][1] > 0)
		cout << "FIRST\n";
	else if (rres[0][1] == 0)
		cout << "DRAW\n";
	else
		cout << "SECOND\n";
	return 0;
}