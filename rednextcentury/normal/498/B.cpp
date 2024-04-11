#include <bits/stdc++.h>
using namespace std;
double dp[2][5001];
int n,T;
double a[10000];
int    s[10000];
void DP()
{
    double ret=0;
    dp[0][0]=1;
    a[0]=1;
    bool P=1;
    for (int i=1;i<=n;i++)
    {
        double p=1;
        for (int j=1;j<=s[i]-1;j++)
            p=p*(1-a[i]);
        double sum = 0;
        dp[P][0]=0;
        for (int j=1;j<=T;j++)
        {
            sum *= (1-a[i]);
            sum+=(dp[!P][j-1])*a[i];
            if (j-s[i]>=0)
            {
                sum -= p*a[i]*dp[!P][j-s[i]];
            }
            dp[P][j]=sum;
            if (j-s[i]>=0)
                dp[P][j]+=p*dp[!P][j-s[i]];
        }
        p=1;
        for (int j=T-1;j>=T-s[i]+1;j--)
            p*=(1-a[i]),ret+=(i-1)*dp[!P][j]*p;
        if (i!=n)
            ret+=i*(dp[P][T]);
        else
        {
            for (int j=1;j<=T;j++)
                ret+=i*(dp[P][j]);
        }
        P=!P;
    }
    printf("%.8f",ret);
}
int main()
{

    scanf("%d%d",&n,&T);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf%d",&a[i],&s[i]);
        a[i]/=100.0;
    }
    DP();
}