#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,b,a) for(int (i)=(b)-1;(i)>=(a);--(i))
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back

typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAX = 407;

const int MOD = 1000000007;

Int dp[MAX][MAX];
Int C[MAX][MAX];

int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	cin >> n;

	FOR(i, 0, MAX)
	{
		C[i][0] = C[i][i] = 1;
		FOR(j, 1, i)
		{
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}


	FOR(i, 1, MAX)
	{
		dp[i][0] = 1;
	}

	dp[1][1] = 1;

	FOR(i, 2, MAX - 2)
	{
		FOR(j, 1, n - i + 2)
		{
			FOR(k, 0, j + 1)
			{
				dp[i][j] += dp[i - 1][k] * dp[i - 1][j - k] % MOD * C[j][k] % MOD * (2 * j + 1) % MOD;
				if (dp[i][j] >= MOD) dp[i][j] -= MOD;
			}

			FOR(k, 0, j)
			{
				dp[i][j] += dp[i - 1][k] * dp[i - 1][j - 1 - k] % MOD * C[j - 1][k] % MOD * j % MOD;
				if (dp[i][j] >= MOD) dp[i][j] -= MOD;
			}

			FOR(k, 0, j + 2)
			{
				Int cc = 0;
				if (k >= 2) cc += C[j - 1][k - 2];
				if (k >= 1 && j + 1 - k >= 1) cc += C[j - 1][k - 1];


				dp[i][j] += 2 * dp[i - 1][k] * dp[i - 1][j + 1 - k] % MOD * cc % MOD * j % MOD;
				if (dp[i][j] >= MOD) dp[i][j] -= MOD;

			}


		}
	}


	cout << dp[n][1] << endl;



	return 0;
}