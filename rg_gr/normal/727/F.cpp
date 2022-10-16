#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <bitset>
#include <map>
#include <algorithm>
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
int a[100005],b[1005][1005],c[100005];
signed main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    memset(b,0x3f,sizeof(b));
    b[n+1][0]=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n-i+1;j++)
            b[i][j]=min(b[i+1][j],max(b[i+1][j-1]-a[i],0));
        b[i][0]=0;
    }
    while(m--)
    {
        int q=read();
        for(int i=n;i>=0;i--)if(b[1][i]<=q){printf("%lld ",n-i);break;}
    }
}