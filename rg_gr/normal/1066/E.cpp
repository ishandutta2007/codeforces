#include <stdio.h>
#include <algorithm>
#include <string.h>
#define int long long
inline int read()
{
    int f=1,num=0;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
inline int read1d()
{
    char c=getchar();
    while(c<48||c>49)c=getchar();
    return c&1;
}
int a[200005],v[200005],b[200005];
const int mod=998244353;
signed main()
{
    int n=read(),m=read();
    for(int i=n-1;i>=0;i--)a[i]=read1d();
    for(int i=m-1;i>=0;i--)b[i]=read1d();
    for(int i=m-1;i>=0;i--)v[i]=v[i+1]+b[i];
    int ans=0,qp=1;
    for(int i=0;i<n;i++)
    {
        if(a[i])ans=(ans+(qp*v[i]))%mod;
        qp=(qp*2)%mod;
    }
    printf("%lld\n",ans);
}