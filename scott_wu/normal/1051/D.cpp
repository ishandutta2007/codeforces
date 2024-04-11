#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 2100;
const int MOD = 998244353;

ll dp[MAXN][MAXN][2];

void add (int i, int j, int k, int l, int m)
{
    dp[i+1][j+m][l] = (dp[i+1][j+m][l] + dp[i][j][k]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    dp[1][1][0] = 2;
    dp[1][2][1] = 2;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= 2 * i; j++)
        {
            add (i, j, 0, 0, 0);
            add (i, j, 0, 0, 1);
            add (i, j, 0, 1, 1);
            add (i, j, 0, 1, 1);
            add (i, j, 1, 0, 0);
            add (i, j, 1, 0, 0);
            add (i, j, 1, 1, 0);
            add (i, j, 1, 1, 2);
        }
    }
    cout << (dp[N][K][0] + dp[N][K][1]) % MOD << "\n";
}