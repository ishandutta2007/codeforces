#include <stdio.h>
#include <algorithm>

double dp[55][5050];
int main()
{
    int n, r;
    int f[55], s[55];
    double p[55];
    scanf("%d%d", &n, &r);
    for (int i=0; i<n; i++)
    {
        scanf("%d%d%lf", &f[i], &s[i], &p[i]);
        p[i] /= 100;
    }
    double L = 0, R = 1e10;
    while (true)
    {
        double x = (R + L) / 2;
        if ( x - L < 1e-10 || R - x < 1e-10) break;
        for (int i=0; i<=r; i++) dp[n][i] = 0;
        for (int i = n-1; i>=0; i--)
        {
            for (int j=r; j>=0; j--)
            {
                double t = 0;
                if (j + f[i] > r)
                {
                    t += p[i] * (f[i] + x);
                }
                else
                {
                    t += p[i] * (f[i] + dp[i+1][j+f[i]]);
                }
                if (j + s[i] > r)
                {
                    t += (1-p[i]) * (s[i] + x);
                }
                else
                {
                    t += (1-p[i]) * (s[i] + dp[i+1][j+s[i]]);
                }
                dp[i][j] = std::min(t, x);
            }
        }
        if (false)//R== 1e10)
        {
            for (int i=0 ; i<= n; i++)
            {
                for (int j=0; j<=r; j++) printf ("%lf ", dp[i][j]);
                puts("");
            }

        }
        //printf("%lf %lf\n",x, dp[0][0]);
        if (dp[0][0] < x - 1e-12)
        {
            R = x;
        }
        else
        {
            L = x;
        }
    }

    printf ("%.12f\n", (L+R)/2);
    return 0;
}