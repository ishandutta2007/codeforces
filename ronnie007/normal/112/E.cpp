#include<iostream>
#include<stdio.h>
int dp[41][65][65],add[1024];
int main()
    {
    int n,m,i,j,k,l;
    scanf("%d%d",&n,&m);

    if(n<m)n^=m,m^=n,n^=m;
    for(i=0;i<(1<<m);++i)
        {
        int i2=i;
        for(;i2>0;i2>>=1)add[i]+=i2&1;
        }
    for(i=1;i<(1<<m);++i)
        {
        for(j=0;j<(1<<m);++j)
            {
            dp[0][i][j]=100000000;
            }
        }
    for(i=0;i<(1<<m);++i)
        {
        dp[0][0][i]=add[i];
        }
    for(i=1;i<=n;++i)
        {
        for(j=0;j<(1<<m);++j)
            {
            int now=j|((j<<1)&((1<<m)-1))|(j>>1);
            for(k=0;k<(1<<m);++k)
                {
                dp[i][j][k]=100000000;
                for(l=0;l<(1<<m);++l)
                    {
                    if((now|k|l)==((1<<m)-1)&&dp[i-1][l][j]<dp[i][j][k])
                        {
                        dp[i][j][k]=dp[i-1][l][j];
                        }
                    }
                dp[i][j][k]+=add[k];
                }
            }
        }
    int ans=100000000;
    for(i=0;i<(1<<m);++i)
        {
        if(dp[n][i][0]<ans)
            {
            ans=dp[n][i][0];
            }
        }
    printf("%d\n",n*m-ans);
    return 0;
    }