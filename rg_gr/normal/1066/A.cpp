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
    int T=read();
    while(T--)
    {
        int c=read(),v=read(),a=read(),b=read();
        printf("%lld\n",c/v-b/v+(a-1)/v);
    }
    //printf("%lld\n",ans);
}