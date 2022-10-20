#include<iostream>
#include<stdio.h>
using namespace std;


#define NESHTOMNOGOGOLIAMO (1<<20)
#define MOD 1000000007

int br0=0;
int br1=0;


long long dp[NESHTOMNOGOGOLIAMO];

int main()
    {
    int i;
    int n;
    int x;
    long long ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {
        scanf("%d",&x);
        if(x==1)br0++;
        else br1++;
        }
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(i=4;i<=n;i++)
        {
        dp[i]=(dp[i-1]+((i-1)*dp[i-2])%MOD)%MOD;
        }

    if(br0==0)
        {
        ans=1;
        for(i=1;i<=n;i++)
            {
            ans=((ans%MOD)*(i%MOD))%MOD;
            }
        printf("%I64d\n",ans);
        return 0;
        }
    if(br1==0)
        {
        printf("%I64d\n",dp[n]);
        return 0;
        }

    ans=dp[br0];
    br0++;
    for(i=1;i<=br1;i++)
        {
        ans=((ans%MOD)*(br0%MOD))% MOD;
        br0++;
        }
    printf("%I64d\n",ans);
    return 0;
    }