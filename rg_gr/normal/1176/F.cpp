#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
int dp[200005][10];
int a[4][200005];
signed main()
{
    int T=read();
    //while(T--)
    //memset(dp,-0x3f,sizeof(dp));
    for(int i=0;i<=T;i++)for(int j=0;j<=9;j++)dp[i][j]=-0x3f3f3f3f3f3f3f3fll;
    dp[0][0]=0;
    for(int i=1;i<=T;i++)
    {
        int n=read();
            int c1=0,c2=0,c3=0;
            for(int i=0;i<n;i++)
            {
                int c=read(),d=read();
                if(c==1)a[1][c1++]=-d;
                if(c==2)a[2][c2++]=-d;
                if(c==3)a[3][c3++]=-d;
            }
            std::sort(a[1],a[1]+c1);
            std::sort(a[2],a[2]+c2);
            std::sort(a[3],a[3]+c3);
            for(int ii=0;ii<=9;ii++)dp[i][ii]=dp[i-1][ii];
            if(c3)
            {
                for(int j=0;j<9;j++)dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]-a[3][0]);
                dp[i][0]=max(dp[i][0],dp[i-1][9]-2*a[3][0]);
            }
            if(c2&&c1)
            {
                for(int j=0;j<8;j++)dp[i][j+2]=max(dp[i][j+2],dp[i-1][j]-a[2][0]-a[1][0]);
                dp[i][0]=max(dp[i-1][8]-min(a[2][0],a[1][0])-a[2][0]-a[1][0],dp[i][0]);
                dp[i][1]=max(dp[i-1][9]-min(a[2][0],a[1][0])-a[2][0]-a[1][0],dp[i][1]);
            }
            if(c1>2)
            {
                for(int j=0;j<7;j++)
                    dp[i][j+3]=max(dp[i][j+3],dp[i-1][j]-a[1][0]-a[1][1]-a[1][2]);
                dp[i][0]=max(dp[i-1][7]-a[1][1]-a[1][0]-a[1][0]-a[1][2],dp[i][0]);
                dp[i][1]=max(dp[i-1][8]-a[1][1]-a[1][0]-a[1][0]-a[1][2],dp[i][1]);
                dp[i][2]=max(dp[i-1][9]-a[1][1]-a[1][0]-a[1][0]-a[1][2],dp[i][2]);
            }
            if(c1>=1)
            {
                for(int j=0;j<9;j++)dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]-a[1][0]);
                dp[i][0]=max(dp[i][0],dp[i-1][9]-a[1][0]*2);
            }
            if(c1>=2)
            {
                for(int j=0;j<8;j++)dp[i][j+2]=max(dp[i][j+2],dp[i-1][j]-a[1][1]-a[1][0]);
                dp[i][0]=max(dp[i-1][8]-a[1][1]-a[1][0]*2,dp[i][0]);
                dp[i][1]=max(dp[i-1][9]-a[1][1]-a[1][0]*2,dp[i][1]);
            }

            if(c2>=1)
            {
                for(int j=0;j<9;j++)dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]-a[2][0]);
                dp[i][0]=max(dp[i][0],dp[i-1][9]-a[2][0]*2);
            }
            //puts("");for(int ii=0;ii<=9;ii++)printf("%lld ",dp[i][ii]);
        
    }
    //puts("");
    int ans=0;
    for(int i=0;i<=9;i++)ans=max(ans,dp[T][i]);
    printf("%lld\n",ans);
}