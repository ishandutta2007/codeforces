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
    int v,w,nxt;
}e[1000005];
int h[100005],cnt=1;
void addedge(int u,int v,int w)
{
    e[cnt]=(Egde){v,w,h[u]};
    h[u]=cnt++;
};
struct Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy{
    int d,i,dep;
    bool operator<(const Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy &b)const
    {
        return d>b.d;
    }
};
std::priority_queue<Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy> q;
int dis[100005][11],vis[100005][11];
void dij(int s,int k)
{
    memset(dis,0x3f,sizeof(dis));
    //memset(dis[0],0,sizeof(dis[0]));
    dis[s][0]=0;
    q.push((Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy){0,s,0});
    while(!q.empty())
    {
        Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy x=q.top();q.pop();
        int u=x.i,p=x.dep;
        if(vis[u][p])continue;
        vis[u][p]=1;
        if(p<k)for(int i=h[u];i;i=e[i].nxt)
        {
            int v=e[i].v;
            if(!vis[v][p+1])
            {
                if(dis[v][p+1]>=dis[u][p])
                {
                    q.push((Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy){dis[u][p],v,p+1});
                    dis[v][p+1]=dis[u][p];
                }
            }
        }
        for(int i=h[u];i;i=e[i].nxt)
        {
            int v=e[i].v,w=e[i].w;
            if(vis[v][p])continue;
            if(dis[u][p]+w<dis[v][p])
            {
                //'//dis[v][p]////=dis[u][p]+w;
                q.push((Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy){dis[v][p],v,p});
            }
        }
    }
}
signed main()
{
    int n=read(),ans=0,m=read();
    for(int i=1;i<=n;i++)h[i]=read();
    while(m--)
    {
        int x=h[read()],y=h[read()];
        ans+=x<y?x:y;
    }
    printf("%lld\n",ans);
}