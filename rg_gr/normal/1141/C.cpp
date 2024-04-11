#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <unordered_map>
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
int a[200005];
int vis[200005];
signed main()
{
    int n=read();
    a[1]=n;int mn=n;
    for(int i=2;i<=n;i++)a[i]=a[i-1]+read(),mn=min(mn,a[i]);
    for(int i=1;i<=n;i++){a[i]-=mn-1;
    if(a[i]>n){puts("-1");return 0;}vis[a[i]]=1;}
    for(int i=1;i<=n;i++)if(vis[i]==0){puts("-1");return 0;}
    for(int i=1;i<=n;i++)printf("%lld ",a[i]);puts("");
}