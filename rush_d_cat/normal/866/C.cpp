#include <iostream>
using namespace std;
#define N 52

int n, r;
int s[52], f[52], sum[52];

double p[52];

double dp[52][5002];

bool chk(double t)
{
    for (int i = 0; i <= r; i ++)
    {
        dp[n][i] = 0;
    }
    for (int i = r + 1; i <= sum[n]; i ++)
    {
        dp[n][i] = t;
    }

    for (int i = n - 1; i >= 0; i --)
    {
        for (int j = sum[i]; j >= 0; j --)
        {
            dp[i][j] = p[i+1] * ( min( dp[i+1][j+f[i+1]], t ) + f[i+1] )
            + (1 - p[i+1]) * ( min( dp[i+1][j+s[i+1]], t ) + s[i+1] );
        }
    }
    //printf("%.5f\n", dp[0][0]);
    //printf("%.5f %.5f %d\n", t, dp[0][0], dp[0][0] >= t);
    return dp[0][0] >= t; // t is smaller than the answer.
}

int main()
{
    scanf("%d %d", &n, &r);

    for (int i = 1; i <= n; i ++)
    {
        scanf("%d %d %lf", &f[i], &s[i], &p[i]);
        sum[i] = sum[i-1] + s[i];
        p[i] /= 100;
    }

    //chk(3);
    
    double L = 0, R = 1e12, mid;

    for (int i = 1; i <= 200; i ++)
    {
        mid = (L + R) / 2;
        //printf("%.5f %.5f\n", L, R);
        if ( chk(mid) )
        {
            L = mid;
        } else {
            R = mid;
        }
    }

    printf("%.12f\n", L);
    
}