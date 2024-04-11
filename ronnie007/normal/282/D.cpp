#include<iostream>
#include<stdio.h>
using namespace std;


#define WIN 1
#define LOSE 0

int main()
    {
    int a[5];
    int dp[350][350];
    int n;
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
    if(n==1)
        {
        if(a[0]!=0)printf("BitLGM\n");
        else printf("BitAryo\n");
        }
    if(n==2)
        {
        int mx = max(a[0],a[1]);
        for(i=1;i<=mx;i++)
            {
            dp[i][0]=1;
            dp[0][i]=1;
            }
        for(i=1;i<=a[0];i++)
            {
            for(j=1;j<=a[1];j++)
                {
                for(k=1;k<i;k++)
                    {
                    if(dp[i-k][j]==LOSE)
                        {
                        dp[i][j]=WIN;
                        break;
                        }
                    }
                for(k=1;k<j;k++)
                    {
                    if(dp[i][j-k]==LOSE)
                        {
                        dp[i][j]=WIN;
                        break;
                        }
                    }
                for(k=1;k<=min(i,j);k++)
                    {
                    if(dp[i-k][j-k]==LOSE)
                        {
                        dp[i][j]=WIN;
                        break;
                        }
                    }
                }
            }

        if(dp[a[0]][a[1]]==WIN)printf("BitLGM\n");
        else printf("BitAryo\n");
        }
    if(n==3)
        {
        int g=0;
        g=g^a[0];
        g=g^a[1];
        g=g^a[2];
        if(g!=0)printf("BitLGM\n");
        else printf("BitAryo\n");
        }
    return 0;
    }