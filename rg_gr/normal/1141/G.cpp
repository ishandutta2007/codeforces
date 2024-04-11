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
struct Edge{
    int v,w,nxt,i;
}e[2000005];
int h[2000005],cnt=2;
int col[4000005];
inline void addedge(int u,int v,int w=1)
{
    e[cnt]=(Edge){v,w,h[u],cnt};
    h[u]=cnt++;
}
struct D{
    int i,deg=0;
    bool operator<(const D& b)const{
        return deg>b.deg;
    }
}d[2000005];
int maxn=1;
void Forever_Pursuit(int u,int fa,int c,int q)
{
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa)continue;
        c++;
        if(c>q)c=1;
        col[i]=col[i^1]=c;
        Forever_Pursuit(v,u,c,q);
    }
}
signed main()
{
    int n=read(),k=read();
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        addedge(x,y);
        addedge(y,x);
        d[x].deg++,d[y].deg++;
        d[x].i=x,d[y].i=y;
    }
    std::sort(d+1,d+1+n);
    printf("%lld\n",d[k+1].deg);
    Forever_Pursuit(1,0,0,d[k+1].deg);
    /*for(int i=1;i<=k;i++)
    {
        int u=d[i].i;
        vv[u]=1;
        printf("%lld\n",u);
        for(int j=h[u];j;j=e[j].nxt)
        {
            col[e[j].i]=1;
            col[e[j].i^1]=1;
            mp[u][1]=mp[e[j].v][1]=1;
        }
    //puts("?");
    }*/
    /*for(int i=1;i<=k;i++)qaq(d[i].i);
    for(int i=k+1;i<=n;i++)qwq(d[i].i);
    printf("%lld\n",maxn);*/
    for(int i=1;i<n;i++)printf("%lld ",col[i<<1]);puts("");
}