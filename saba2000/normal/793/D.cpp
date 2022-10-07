#include<bits/stdc++.h>
using namespace std;
int dp[109][109][109];
int c[109][109];
int m,n,k;
main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
    {c[i][j] = 10000000;
    for (int p =1; p <= k; p ++)
        dp[i][j][p] = 10000000;
        dp[i][j][0] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b, C;
        cin >> a >> b >> C;
        c[a][b] = min (c[a][b],C);
    }
    for (int i = 1; i <= k-1; i++)
        for (int  x =1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            int L,R;
            int l = min(x,y), r =max(x,y);
            if ( l == x) L=l+1,R=r;
            else L=l,R=r-1;
            for (int z = L ; z <= R; z++)
            {
                dp[x][y][i] = min(dp[x][y][i],dp[z][L][i-1] + c[x][z]);
                dp[x][y][i] = min(dp[x][y][i],dp[z][R][i-1] + c[x][z]);
            }
        }
    }
    int ans  = 1000000000;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[i][1][k-1]);
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[i][n][k-1]);
    if (ans >= 1000000) cout << -1 << endl;
    else cout << ans << endl;
}