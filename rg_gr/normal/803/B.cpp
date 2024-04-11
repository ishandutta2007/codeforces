#include <stdio.h>
#include <stdlib.h>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b)
{
    return a<b?a:b;////////////////
}
int a[200005],l[200005],r[200005];

signed main()
{
    int n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    int pos;
    for(int i=1;i<=n;i++)if(a[i]==0){pos=i;break;}
    for(int i=1;i<pos;i++)l[i]=0x3f3f3f3f;
    for(int i=pos;i<=n;i++)if(a[i]==0)l[i]=0;else l[i]=l[i-1]+1;
    for(int i=n;i>=1;i--)if(a[i]==0){pos=i;break;}
    for(int i=pos+1;i<=n;i++)r[i]=0x3f3f3f3f;
    for(int i=pos;i>=1;i--){if(a[i]==0)r[i]=0;else r[i]=r[i+1]+1;}
    for(int i=1;i<=n;i++)printf("%lld ",min(l[i],r[i]));puts("");
}