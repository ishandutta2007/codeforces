#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
typedef __int64 ll;
int n, m, b, mod;
int dp[502][502], a[502];
int main()
{
    int i, j, k;
    cin >> n >> m >> b >> mod;
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    memset(dp, 0, sizeof(dp));
    for(i = 0; i <= b; i++)
    {
        dp[0][i] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            for(k = a[i]; k <= b; k++)
            {
                dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % mod;
            }
        }
    }
    cout << dp[m][b];
    return 0;
}