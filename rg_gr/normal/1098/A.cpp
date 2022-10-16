#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int f[100005],a[100005];
signed main()
{
    int n=read(),ans=0;
    for(int i=2;i<=n;i++)f[i]=read();
    for(int i=1;i<=n;i++)a[i]=read(),a[i]=a[i]==-1?0x3f3f3f3f:a[i];
    for(int i=2;i<=n;i++)a[f[i]]=min(a[f[i]],a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[f[i]])return puts("-1")&0;
        ans+=a[i]<0x3f3f3f3f?a[i]-a[f[i]]:0;
    }
    printf("%lld\n",ans);
}