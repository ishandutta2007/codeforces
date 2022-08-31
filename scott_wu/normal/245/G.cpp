#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXM = 5100;
const int MAXN = 10100;

int N, M;
string edge[MAXM], edge2[MAXM];
int val[MAXM], val2[MAXM];
string plist[MAXN];
string pposs[MAXN];
short res[MAXN][MAXN];

int main()
{
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> edge[i] >> edge2[i];
		plist[2*i] = edge[i];
		plist[2*i+1] = edge2[i];
	}
	
	sort (plist, plist + 2 * M);
	
	N = 1;
	pposs[0] = plist[0];
	for (int i = 1; i < 2 * M; i++)
		if (plist[i] != plist[i-1])
		{
			pposs[N] = plist[i];
			N++;
		}
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (edge[i] == pposs[j])
				val[i] = j;
			if (edge2[i] == pposs[j])
				val2[i] = j;
		}
	}
	
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
		{
			res[i][j] = 0;
		}
	
	for (int i = 0; i < M; i++)
	{
		res[max (val[i], val2[i])][min (val[i], val2[i])] = 1;
		for (int j = i + 1; j < M; j++)
		{
			if (val[i] == val[j])
			{
				int m = min (val2[i], val2[j]), m2 = max (val2[i], val2[j]);
				res[m][m2]++;
			}
			if (val[i] == val2[j])
			{
				int m = min (val2[i], val[j]), m2 = max (val2[i], val[j]);
				res[m][m2]++;
			}
			if (val2[i] == val[j])
			{
				int m = min (val[i], val2[j]), m2 = max (val[i], val2[j]);
				res[m][m2]++;
			}
			if (val2[i] == val2[j])
			{
				int m = min (val[i], val[j]), m2 = max (val[i], val[j]);
				res[m][m2]++;
			}
		}
	}
	
	cout << N << "\n";
	for (int i = 0; i < N; i++)
	{
		int best = -1, np = 0;
		for (int j = 0; j < N; j++)
		{
			if (j != i && !res[max (i, j)][min (i, j)])
			{
				int nf = res[min (i, j)][max (i, j)];
				if (nf == best)
					np++;
				else if (nf > best)
				{
					best = nf;
					np = 1;
				}
			}
		}
		cout << pposs[i] << " " << np << "\n";
	}
	return 0;
}