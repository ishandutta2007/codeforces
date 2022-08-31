#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 4100;

string str;
int N;
bool pal[MAXN][MAXN];
int nstart[MAXN];
int nend[MAXN];

int main()
{
	cin >> str;
	N = str.length();
	
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			pal[i][j] = false;
	
	for (int i = 0; i < N; i++)
	{
		pal[i][0] = true;
		pal[i][1] = true;
	}
	
	for (int i = 2; i < N; i++)
		for (int j = 0; j <= N - i; j++)
		{
			if (i + j <= N && str[j] == str[j+i-1] && pal[j+1][i-2])
				pal[j][i] = true;
		}
	
	for (int i = 0; i < N; i++)
	{
		nstart[i] = nend[i] = 0;
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= N; j++)
			if (pal[i][j])
			{
				nstart[i]++;
				nend[i+j-1]++;
			}
	}
	
	ll ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			ans += nend[i] * nstart[j];
			//cout << nend[i] << " " << nstart[j];
		}
	cout << ans << "\n";
	return 0;
}