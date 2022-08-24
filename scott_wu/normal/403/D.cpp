#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 1100;
const int MAXK = 55;
const int MOD = 1000000007;

int N, K;
int nval[MAXN][MAXK];
int tri[2 * MAXN][2 * MAXN];
int rval[MAXN][MAXK];

int main()
{
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXK; j++)
			nval[i][j] = 0;
	nval[0][0] = 1;
	
	for (int i = 1; i < MAXN; i++)
		for (int j = MAXK - 2; j >= 0; j--)
			for (int k = MAXN - i - 1; k >= 0; k--)
				nval[k+i][j+1] = (nval[k+i][j+1] + nval[k][j]) % MOD;
	
	for (int i = 0; i < 2 * MAXN; i++)
		for (int j = 0; j < 2 * MAXN; j++)
			tri[i][j] = 0;
	for (int i = 0; i < 2 * MAXN; i++)
		tri[i][0] = 1;
	
	for (int i = 1; i < 2 * MAXN; i++)
		for (int j = 1; j < 2 * MAXN; j++)
			tri[i][j] = (tri[i-1][j] + tri[i-1][j-1]) % MOD;
	
	for (N = 0; N < MAXN; N++)
		for (K = 0; K < MAXK; K++)
		{
			ll fact = 1;
			for (int i = 1; i <= K; i++)
				fact = (fact * i) % MOD;
	
			ll res = 0;
			for (int i = 0; i <= N; i++)
			{
				if (nval[i][K])
				{
					res = (res + ((nval[i][K] * fact) % MOD) * tri[N-i+K][K]) % MOD;
				}
			}
			rval[N][K] = res;
		}

	ios_base::sync_with_stdio(0);
	int T; cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> N >> K;
	
		if (K >= MAXK)
		{
			cout << "0\n";
			continue;
		}
	
		cout << rval[N][K] << "\n";
	}
	
	return 0;
}