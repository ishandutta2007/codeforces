#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string.h>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
#define Egde Edge
struct Edge{
    int v,w,nxt,q;
}e[2000005];
int a[505],h[1000005],cnt=1;
void addedge(int u,int v,int w,int q)
{
    e[cnt]=(Egde){v,w,h[u],q};
    h[u]=cnt++;
};
struct Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy{
    int d,i;
    bool operator<(const Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy &b)const
    {
        return d>b.d;
    }
};
std::priority_queue<Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy> q;
int dis[1000005],vis[1000005],ans=0;
void dij(int s,int k)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    //memset(dis[0],0,sizeof(dis[0]));
    dis[s]=0;
    q.push((Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy){0,s});
    while(!q.empty())
    {
        Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy x=q.top();q.pop();
        int u=x.i;
        if(vis[u])continue;
        vis[u]=1;
        ans+=dis[u];
        for(int i=h[u];i;i=e[i].nxt)
        {
            if(e[i].q!=k)continue;
            int v=e[i].v,w=e[i].w;
            if(vis[v])continue;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                q.push((Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy){dis[v],v});
            }
        }
    }
}
int G[505][505],D[505][505],pvp[505];
inline int min(int a,int b)
{
    return a<b?a:b;
}
signed main()
{
    int n=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)G[i][j]=read();
    for(int i=1;i<=n;i++)a[i]=read();
    memset(D,0x3f,sizeof(D));
    for(int i=1;i<=n;i++)D[i][i]=0;
    for(int p=n;p>=1;p--)
    {
        int ans=0,k=a[p];
        vis[k]=1;
        for(int i=1;i<=n;i++)D[k][i]=min(D[k][i],G[k][i]),D[i][k]=min(D[i][k],G[i][k]);;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
                if(vis[i]&&vis[j])ans+=D[i][j];
                //printf("%lld ",D[i][j]);
            }
        pvp[p]=ans;
    }
    for(int i=1;i<=n;i++)printf("%lld ",pvp[i]);puts("");
}