#include<iostream>
#include<stdio.h>
using namespace std;


int dp[150][150][15][15];
#define MOD 100000000



int main()
    {
    int n1;
    int n2;
    int k1;
    int k2;
    int i,j,t,x,y;
    scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
    dp[1][0][1][0]=1;
    dp[0][1][0][1]=1;
    int sm=0;
    for(i=0;i<=n1;i++)
        {
        for(j=0;j<=n2;j++)
            {
            for(t=0;t<=k1;t++)
                {
                for(x=0;x<=k2;x++)
                    {
                    if(i<=n1-1 && t<=k1-1)
                        {
                        dp[i+1][j][t+1][0]=(dp[i][j][t][x]%MOD+dp[i+1][j][t+1][0]%MOD)%MOD;
                        }
                    if(j<=n2-1 && x<=k2-1)
                        {
                        dp[i][j+1][0][x+1]=(dp[i][j][t][x]%MOD+dp[i][j+1][0][x+1]%MOD)%MOD;
                        }
                    }
                }
            }
        }
    for(i=0;i<=k1;i++)
        {
        sm=(sm%MOD+dp[n1][n2][i][0]%MOD)%MOD;
        }
    for(i=0;i<=k2;i++)
        {
        sm=(sm%MOD+dp[n1][n2][0][i]%MOD)%MOD;
        }
    printf("%d\n",sm);
    return 0;
    }