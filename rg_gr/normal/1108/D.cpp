#include <stdio.h>
#define int long long
inline int read()
{
    int f=1,num=0;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
char a[200005];
int dp[200005][3];
int pre[200005][3];
#define min(a,b) (a<b?a:b)
inline int print(int x,int u)
{
    if(x)print(x-1,pre[x][u]);
    if(u==2)putchar('B');
    else if(u==1)putchar('G');
    else putchar('R');
    return 0;
}
signed main()
{
    int T=1;
    while(T--)
    {
        int n=read();
        scanf("%s",a);
        for(int i=0;i<n;i++)if(a[i]=='R')a[i]=0;else if(a[i]=='G')a[i]=1;else a[i]=2;
        dp[0][a[0]]=0,dp[0][(a[0]+1)%3]=dp[0][(a[0]+2)%3]=1;
        for(int i=1;i<n;i++)
        {
            if(dp[i-1][1]<dp[i-1][2])
            {
                pre[i][0]=1;
            }
            else pre[i][0]=2;
            if(dp[i-1][0]<dp[i-1][2])
            {
                pre[i][1]=0;
            }
            else pre[i][1]=2;
            if(dp[i-1][0]<dp[i-1][1])
            {
                pre[i][2]=0;
            }
            else pre[i][2]=1;
            dp[i][0]=min(dp[i-1][1],dp[i-1][2])+(a[i]!=0);
            dp[i][1]=min(dp[i-1][0],dp[i-1][2])+(a[i]!=1);
            dp[i][2]=min(dp[i-1][1],dp[i-1][0])+(a[i]!=2);
        }
        printf("%lld\n",min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2])));
        if(dp[n-1][0]<dp[n-1][1]&&dp[n-1][0]<dp[n-1][2])print(n-1,0);
        else if(dp[n-1][1]<dp[n-1][2])print(n-1,1);
        else print(n-1,2);
        puts("");
    }
}