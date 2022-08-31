#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
typedef long long ll;
const int MAXN = 510;
const ll MOD = 998244353;

int N, M;
int arr[MAXN];
ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        //arr[i] = i;
    }

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = 0;
    for (int i = 0; i <= N; i++)
        dp[i][i] = 1;

    for (int len = 1; len <= N; len++)
    {
        for (int i = 0; i + len <= N; i++)
        {
            int j = i + len;
            int mloc = i;
            for (int x = i; x < j; x++)
                if (arr[x] < arr[mloc])
                    mloc = x;
            ll l = 0, r = 0;
            for (int x = i; x <= mloc; x++)
            {
                l += (dp[i][x] * dp[x][mloc]);
                l %= MOD;
            }
            for (int x = mloc + 1; x <= j; x++)
            {
                r += (dp[mloc + 1][x] * dp[x][j]);
                r %= MOD;
            }
            l %= MOD;
            r %= MOD;
            dp[i][j] = (l * r) % MOD;
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }
    cout << dp[0][N] << "\n";
}