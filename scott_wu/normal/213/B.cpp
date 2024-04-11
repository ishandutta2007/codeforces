#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 110;
const int MAXD = 12;

int N;
ll ptri[MAXN][MAXN];
ll dp[MAXD][MAXN];
int mdig[MAXD];

ll choose (int n, int k)
{
    return ((n < 0) ? 0 : ptri[n][k]);
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
        {
            if (j == 0)
                ptri[i][j] = 1;
            else if (j > i)
                ptri[i][j] = 0;
            else
                ptri[i][j] = (ptri[i-1][j-1] + ptri[i-1][j]) % MOD;
        }
    for (int i = 0; i < MAXD; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = 0;
    
    cin >> N;
    for (int i = 0; i < 10; i++)
        cin >> mdig[i];
    
    for (int i = 0; i <= N; i++)
        dp[9][i] = ((i >= mdig[9]) ? 1 : 0);
    
    for (int i = 8; i >= 0; i--)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = mdig[i]; k + j <= N; k++)
            {
                if (i == 0)
                    dp[i][k+j] = (dp[i][k+j] + choose (k+j-1, k) * dp[i+1][j]) % MOD;
                else
                    dp[i][k+j] = (dp[i][k+j] + choose (k+j, k) * dp[i+1][j]) % MOD;
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= N; i++)
        ans = (ans + dp[0][i]) % MOD;
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}