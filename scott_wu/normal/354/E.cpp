#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

vector <int> lnum;
int dist[100100];
int lval[100100];

int dig[25];
int adig[6][25];

bool solve (int x)
{
	if (dist[x] > 6) return false;
	
	int count = 0;
	while (x)
	{
		int last = lval[x];
		x -= last;
		
		int cdig = 0;
		while (last)
		{
			adig[count][cdig] = last % 10;
			last /= 10;
			cdig++;
		}
		count++;
	}
	return true;
}

void print (int x)
{
	int ldig = 0;
	for (int i = 0; i < 25; i++)
		if (adig[x][i]) ldig = i;
	
	for (int i = ldig; i >= 0; i--)
		cout << adig[x][i];
}

int main()
{
	lnum.push_back (0);
	lnum.push_back (4);
	lnum.push_back (7);
	
	for (int i = 1; i < lnum.size(); i++)
		if (10 * lnum[i] < 40000)
		{
			lnum.push_back (10*lnum[i]);
			lnum.push_back (10*lnum[i] + 4);
			lnum.push_back (10*lnum[i] + 7);
		}
	
	dist[0] = 0;
	for (int i = 1; i < 100000; i++)
	{
		dist[i] = 1000;
		for (int j = 0; j < lnum.size(); j++)
			if (i >= lnum[j])
			{
				if (dist[i] > 1 + dist[i-lnum[j]])
				{
					dist[i] = 1 + dist[i-lnum[j]];
					lval[i] = lnum[j];
				}
			}
		
		//if (i < 41000 && dist[i] > 6)
		//	cout << i << " " << dist[i] << "\n";
	}
	
	int T; cin >> T;
	
	for (int test = 0; test < T; test++)
	{
	
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 6; j++)
			adig[j][i] = dig[i] = 0;
	
	ll N;
	cin >> N;
	
	int ndig = 0;
	while (N)
	{
		dig[ndig] = N % 10;
		N /= 10;
		ndig++;
	}
	
	for (int i = ndig - 1; i >= 4; i--)
	{
		dig[i] += 10 * dig[i+1];
		
		for (int j = 0; j <= 6; j++)
			for (int k = 0; k <= 6 - j; k++)
			{
				if (dig[i] >= 7 * j + 4 * k)
				{
					if ((dig[i-1] == 0 && (dig[i] > 7 * j + 4 * k) && (dig[i] <= 7 * j + 4 * k + 4)) || 
						(dig[i-1] > 0 && (dig[i] < 7 * j + 4 * k + 4)))
					{
						dig[i] -= 7 * j + 4 * k;
						
						for (int x = 0; x < j; x++)
							adig[x][i] = 7;
						for (int x = j; x < j + k; x++)
							adig[x][i] = 4;
						for (int x = j + k; x < 6; x++)
							adig[x][i] = 0;
					}
				}
			}
	}
	
	if (solve (dig[4] * 10000 + dig[3] * 1000 + dig[2] * 100 + dig[1] * 10 + dig[0]))
	{
		for (int i = 0; i < 6; i++)
		{
			if (i) cout << " ";
			print (i);
		}
		cout << "\n";
	}
	else
		cout << "-1\n";
	}
		
	return 0;
}