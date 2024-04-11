#include "iostream"
#include "cstdio"
#include "cstring"
#include "cmath"
#include "stdlib.h"
#include "algorithm"
using namespace std;

#define MAXN 5010
long long str[MAXN];
int B[MAXN],dp[MAXN];
int n;

bool ok(int j,int i)
{
    if(str[j]%str[i]!=0)
        return false;
    if(B[i]==0)
        return true;
    else
    {
        if(i-j==B[i]-B[j])
            return true;
        if(B[i]<i-j)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d",&n);
    memset(B,0,sizeof(B));
    for(int i=0; i<n; i++)
    {
        scanf("%I64d",&str[i]);
        while(str[i]%2==0)
        {
            B[i]++;
            str[i]/=2;
        }
    }
    str[n]=1;
    dp[0]=0;
    for(int i=1; i<=n; i++)
    {
        dp[i]=i;
        for(int j=0; j<i; j++)
            if(ok(j,i))
                dp[i]=min(dp[i],dp[j]+i-j-1);
    }
    printf("%d\n",dp[n]);
    return 0;
}