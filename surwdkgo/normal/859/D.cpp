#include <stdio.h>

int main()
{
    int n;
    double prob[100][100];
    double dp[10][100];
    double ch[10][100];
    scanf ("%d", &n);
    int pow = 1<<n;
    for (int i=0; i<pow; i++)
    {
        for (int j=0; j<pow; j++)
        {
            int x;
            scanf("%d", &x);
            prob[i][j] = x / 100.0;
        }
    }
    for (int i=0; i<pow; i++)
    {
        ch[0][i] = 1;
        dp[0][i] = 0;
    }
    for (int i=1; i<=n; i++)
    {
        int p = 1<<i;
        for (int j=0; j<pow; j++)
        {
            ch[i][j] = 0;
            int st = (j & ~(p/2-1)) ^ (p/2);
            for (int t = st; t < st + p/2; t++)
            {
                ch[i][j] += ch[i-1][t] * prob[j][t];
            }
            ch[i][j] *= ch[i-1][j];

            double best = 0;
            for (int t = st; t < st + p/2; t++)
            {
                if (best < dp[i-1][t])
                {
                    best = dp[i-1][t];
                }
            }

            dp[i][j] = dp[i-1][j] + best + ch[i][j] * (p/2);
        }
    }
    double best = 0;
    for (int i=0; i<pow; i++)
    {
        if (best < dp[n][i])  best = dp[n][i];
    }
    printf("%.12f\n", best);
    return 0;
}