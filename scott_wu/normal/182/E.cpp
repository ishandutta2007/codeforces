#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 110;
const int MAXL = 3010;
const int MOD = 1000000007;

int N, L;
int dp[MAXL][2*MAXN];
int len[2*MAXN], wid[2*MAXN];

int main()
{
    for (int i = 0; i < 2 * MAXN; i++)
        for (int j = 0; j < MAXL; j++)
            dp[i][j] = 0;
    
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        cin >> len[2*i] >> wid[2*i];
        len[2*i+1] = wid[2*i];
        wid[2*i+1] = len[2*i];
    }
    
    for (int i = 0; i < 2 * N; i++)
        dp[len[i]][i] = 1;
    
    for (int i = 0; i <= L; i++)
    {
        for (int j = 0; j < 2 * N; j++)
        {
            for (int k = 0; k < 2 * N; k++)
            {
                if (j / 2 == k / 2)
                    continue;
                if ((j % 2 == 1) && len[j] == wid[j])
                    continue;
                if ((k % 2 == 1) && len[k] == wid[k])
                    continue;
                if (len[k] != wid[j])
                    continue;
                if (i < len[k])
                    continue;
                dp[i][k] = (dp[i][k] + dp[i-len[k]][j]) % MOD;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 2 * N; i++)
        if (i % 2 == 0 || len[i] != wid[i])
            ans = (ans + dp[L][i]) % MOD;
    cout << ans << "\n";
    //system ("Pause");
}