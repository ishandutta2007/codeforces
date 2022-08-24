#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 2700;

string str;
int N;

int lcount[27];

int dp[MAXN][MAXN];
pair <int, int> last[MAXN][MAXN]; //prev val for pal
pair <int, int> bloc[MAXN][MAXN]; //best prev val for range inclusive

string res;
string nres;

pair <int, int> best (pair <int, int> lval, pair <int, int> rval)
{
	if (lval.first == -1)
		return rval;
	if (rval.first == -1)
		return lval;
	
	if (dp[lval.first][lval.second] > dp[rval.first][rval.second])
		return lval;
	return rval;
}

int main()
{
	cin >> str;
	N = str.length();
	
	if (N > 2600)
	{
		for (int i = 0; i < 27; i++)
			lcount[i] = 0;
	
		for (int i = 0; i < N; i++)
			lcount[(int)str[i] - 'a']++;
		
		for (int i = 0; i < 26; i++)
			if (lcount[i] >= 100)
			{
				for (int j = 0; j < 100; j++)
					cout << (char) (i + 'a');
				cout << "\n";
				return 0;
			}
		return 0;
	}
	
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
		{
			dp[i][j] = -1e9;
			bloc[i][j] = make_pair (-1, -1);
		}
	
	for (int i = 0; i < N; i++)
	{
		dp[i][i] = 1;
		bloc[i][i] = make_pair (i, i);
		last[i][i] = make_pair (-1, -1);
	}
	
	for (int d = 1; d < N; d++)
	{
		for (int i = 0; i < N - d; i++) // range i to i+d
		{
			/*if (bloc[i][i+d-1].first == -1)
				bloc[i][i+d] = bloc[i+1][i+d];
			else if (bloc[i+1][i+d].first == -1)
				bloc[i][i+d] = bloc[i][i+d-1];
			else
			{
				int lval = dp[bloc[i][i+d-1].first][bloc[i][i+d-1].second];
				int rval = dp[bloc[i+1][i+d].first][bloc[i+1][i+d].second];
				
				if (lval > rval)
					bloc[i][i+d] = bloc[i][i+d-1];
				else
					bloc[i][i+d] = bloc[i+1][i+d];
			}*/
			
			bloc[i][i+d] = bloc[i+1][i+d-1];
			
			if (str[i] == str[i+d])
			{
				if (bloc[i][i+d].first == -1)
				{
					dp[i][i+d] = 2;
					last[i][i+d] = bloc[i][i+d];
					bloc[i][i+d] = make_pair (i, i + d);
				}
				else
				{
					dp[i][i+d] = 2 + dp[bloc[i][i+d].first][bloc[i][i+d].second];
					last[i][i+d] = bloc[i][i+d];
					bloc[i][i+d] = make_pair (i, i + d);
				}
			}
			else
			{
				bloc[i][i+d] = best (bloc[i][i+d], bloc[i][i+d-1]);
				bloc[i][i+d] = best (bloc[i][i+d], bloc[i+1][i+d]);
			}
		}
	}
	
	int bx = 0, by = 0;
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			if (dp[i][j] > dp[bx][by])
			{
				bx = i;
				by = j;
			}
	
	int ans = dp[bx][by];
	res = "";
	nres = "";
	while (bx != -1)
	{
		res += str[bx];
		if (bx != by)
			nres += str[by];
		
		int nx = last[bx][by].first, ny = last[bx][by].second;
		bx = nx, by = ny;
	}
	
	if (ans >= 100)
	{
		for (int i = 0; i < 50; i++)
			cout << res[i];
		for (int i = 49; i >= 0; i--)
			cout << res[i];
		cout << "\n";
		return 0;
	}
	else
	{
		cout << res;
		for (int i = nres.length() - 1; i >= 0; i--)
			cout << nres[i];
		cout << "\n";
		return 0;
	}
	
	/*for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}*/
	
	return 0;
}