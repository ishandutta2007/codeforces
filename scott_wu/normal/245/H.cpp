#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 5100;
const int MOD = 1000000007;

int N;
string str;
ll mpow[MAXN];
ll ps[MAXN];
ll ps2[MAXN];
bool good[MAXN][MAXN];
int partial[MAXN][MAXN];
int val[MAXN][MAXN];

ll hash (int start, int end)
{
	return ps[end] - ps[start] * mpow[end-start];
}

ll hash2 (int start, int end)
{
	return ps2[end] - ps2[start] * mpow[end-start];
}

int main()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
		{
			good[i][j] = false;
			partial[i][j] = val[i][j] = 0;
		}
	mpow[0] = 1;
	for (int i = 1; i < MAXN; i++)
		mpow[i] = mpow[i-1] * MOD;
	
	cin >> str;
	N = str.length();
	
	ps[0] = 0;
	for (int i = 0; i < str.length(); i++)
		ps[i+1] = ps[i] * MOD + (str[i] - 'a' + 1);
	ps2[0] = 0;
	for (int i = str.length() - 1; i >= 0; i--)
		ps2[str.length() - i] = ps2[str.length() - i - 1] * MOD + (str[i] - 'a' + 1);
	
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			if (hash (i, j + 1) == hash2 (N - 1 - j, N - i))
			{
				good[i][j] = true;
				//cout << i << " " << j << "\n";
				
				partial[i][N-1]++;
				if (j > 0)
					partial[i][j-1]--;
			}
	
	for (int i = N - 2; i >= 0; i--)
		partial[N-1][i] += partial[N-1][i+1];
	for (int i = N - 2; i >= 0; i--)
		partial[i][N-1] += partial[i+1][N-1];
	
	for (int i = N - 2; i >= 0; i--)
		for (int j = N - 2; j >= 0; j--)
			partial[i][j] += partial[i+1][j] + partial[i][j+1] - partial[i+1][j+1];
	
	int Q; cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		
		cout << partial[a][b] << "\n";
	}
	return 0;
}