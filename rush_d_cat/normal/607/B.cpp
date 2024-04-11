#include <iostream>
using namespace std;
int n;
int dp[502][502], a[502];
int f[502][502];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i ++)
    {
        f[i][i] = 1;
    }

    for (int i = 1; i <= n; i ++)
    {
        for (int j = i + 1; j <= n; j ++)
        {
            if (a[i] == a[j] && ( (j - i == 1) || f[i+1][j-1] ) )
                f[i][j] = 1;
        }
    }


    for (int i = n; i >= 1; i --)
    {
        for (int j = i; j <= n; j ++)
        {
            if (f[i][j])
            {
                dp[i][j] = 1;
                continue;
            }

            int mx = 1000;
            for (int k = i; k < j; k ++)
            {

                mx = min(mx, dp[i][k] + dp[k+1][j]);
                
                if (a[i] == a[j] && j - i > 1)
                {
                    mx = min(mx, dp[i+1][j-1]);
                }

            }
            dp[i][j] = mx;
            //printf("%d %d %d\n", i, j, dp[i][j]);
        }
    }

    printf("%d\n", dp[1][n]);


}