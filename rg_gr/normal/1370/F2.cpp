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
struct Edge{
    int v,nxt;
}e[200005];
int h[200005],cnt=1;
inline void addedge(int u,int v)
{
    e[cnt]=(Edge){v,h[u]};
    h[u]=cnt++;
}
int f[100005][20],dep[100005],sz[100005];
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(int i=h[u];i;i=e[i].nxt)
    {
        if(e[i].v!=fa)dfs(e[i].v,u);
    }
}
int x,d,n;
#define ff puts("");fflush(stdout)
inline void queryln(int q)
{
    //printf("ql %lld\n",q);
    int ans=0;
    for(int i=1;i<=n;i++)if(dep[i]>=q)ans++;
    printf("? %lld ",ans);
    for(int i=1;i<=n;i++)if(dep[i]>=q)printf("%lld ",i);
    ff;
    x=read(),d=read();
}
inline void querydn(int q)
{
 //   printf("ql %lld\n",q);
    int ans=0;
    for(int i=1;i<=n;i++)if(dep[i]==q)ans++;
    printf("? %lld ",ans);
    for(int i=1;i<=n;i++)if(dep[i]==q)printf("%lld ",i);
    ff;
    x=read(),d=read();
}
inline void queryall()
{
    printf("? %lld ",n);
    for(int i=1;i<=n;i++)printf("%lld ",i);
    ff;
    x=read(),d=read();
}
signed main()
{
    int T=read();while(T--){n=read();//int q=read();
    cnt=1;;dep[0]=-1;
    memset(h,0,sizeof(h));
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        addedge(x,y);
        addedge(y,x);
    }
    queryall();
    int rt=x;
    dfs(rt,0);
    int maxn=0,pos=0;
    for(int i=1;i<=n;i++)maxn=max(maxn,dep[i]);
    int qwq=d;
    int l=d/2,r=min(maxn,d),ans;
    while(l<=r)
    {
        //printf("%lld %lld\n",l,r);
        int m=l+r>>1;
        querydn(m);
        if(d>qwq)r=m-1;
        else ans=m,l=m+1,pos=x;
    }
    dfs(pos,0);
    querydn(qwq);
    printf("! %lld %lld",pos,x);ff;}
}