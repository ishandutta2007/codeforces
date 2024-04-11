#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 2100;
const int MOD = 998244353;

int N, M, K;
ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M >> K;
    dp[1][0] = M;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            dp[i+1][j+1] += (M - 1) * dp[i][j];
            dp[i+1][j+1] %= MOD;
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
        }
    }

    cout << dp[N][K] << "\n";
}