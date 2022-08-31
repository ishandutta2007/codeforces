#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 510;
const int MOD = 998244353;

int N, K;
int dp[MAXN][MAXN];
int ndp[MAXN][MAXN];
ll ntot[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> K;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
            for (int k = 1; k <= j; k++)
            {
                if (k == j)
                    ndp[j+1][j+1] = (ndp[j+1][j+1] + dp[j][k]) % MOD;
                else
                    ndp[j][k+1] = (ndp[j][k+1] + dp[j][k]) % MOD;
                ndp[j][1] = (ndp[j][1] + dp[j][k]) % MOD;
            }

        for (int j = 0; j <= N; j++)
            for (int k = 0; k <= N; k++)
            {
                dp[j][k] = ndp[j][k];
                ndp[j][k] = 0;
            }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            ntot[i] += dp[i][j];
        ntot[i] %= MOD;
    }

    ll res = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i * j < K)
                res = (res + ntot[i] * ntot[j]) % MOD;
    cout << (2 * res) % MOD << "\n";
}