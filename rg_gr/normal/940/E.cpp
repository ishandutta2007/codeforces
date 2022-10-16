#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57){c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num;
}
int pre[1000005],suf[1000005],a[1000005],logg[1000005];
int Max[22][1000005];
inline int max(int a,int b)
{
    return a<b?a:b;
}
inline int Query(int l,int r)
{
    int k=logg[r-l+1]; 
    return max(Max[k][l],Max[k][r-(1<<k)+1]);
}
int sum;
int dp[1000005],dq[1000005];
inline int min(int a,int b)
{
    return a>b?a:b;
}
signed main()
{
    int n=read(),c=read();logg[1]=0;
    for(int i=1;i<=n;i++)sum+=a[i]=read();
    for(int i=1;i<=n;i++)Max[0][i]=a[i];
    for(int i=2;i<=n+1;i++)logg[i]=logg[i>>1]+1;
    for(int j=1;j<=21;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            Max[j][i]=max(Max[j-1][i],Max[j-1][i+(1<<(j-1))]);
    int ans=0x3f3f3f3f3f3f3f3fll;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(i>=c)dp[i]=min(dp[i],dp[i-c]+Query(i-c+1,i));
    }
    printf("%lld\n",sum-dp[n]);
}