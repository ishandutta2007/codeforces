#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
        int n,h,i,j,k,x;
        LL dp[55][55];
        
        scanf("%d %d",&n,&h);
        dp[0][0]=1;
        
        for(i=1;i<=n;i++) for(j=1;j<=i;j++)
        {
                for(x=1;x<=i;x++)
                {
                        for(k=0;k<=j-1;k++) dp[i][j]+=dp[x-1][j-1]*dp[i-x][k];
                        for(k=0;k<=j-2;k++) dp[i][j]+=dp[x-1][k]*dp[i-x][j-1];          
                }       
        }
        
        LL ans = 0;
        for(i=h;i<=n;i++) ans+=dp[n][i];
        
        cout<<ans;
        
        return 0;
}