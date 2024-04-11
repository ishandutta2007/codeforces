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
    int d,i;
    bool operator<(const Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy &b)const
    {
        return d>b.d;
    }
};
std::priority_queue<Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy> q;
int dis[100005],vis[100005],qwq[100005];
void dij(int s,int k)
{
    memset(dis,0x3f,sizeof(dis));
    //memset(dis[0],0,sizeof(dis[0]));
    dis[s]=0;
    q.push((Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy){0,s});
    while(!q.empty())
    {
        Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy x=q.top();q.pop();
        int u=x.i;
        if(vis[u])continue;
        vis[u]=1;
        for(int i=h[u];i;i=e[i].nxt)
        {
            int v=e[i].v,w=e[i].w;
            if(vis[v])continue;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                qwq[v]=1;
                q.push((Thisisaverylongstructnamesoithinkyoushouldusesomethingyoulikebutnottypeitifyoulikezhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdyzhoukangyangtxdy){dis[v],v});
            }
            else if(dis[u]+w==dis[v])qwq[v]++;
        }
    }
}
int c[100005],W[100005];
signed main()
{
    int n=read(),ans=0,m=read(),k=read();
    //for(int i=1;i<=n;i++)h[i]=read();
    while(m--)
    {
        //int x=h[read()],y=h[read()];
        //ans+=x<y?x:y;
        int x=read(),y=read(),w=read();
        addedge(x,y,w);
        addedge(y,x,w);
    }
    for(int i=0;i<k;i++)
    {
        c[i]=read();W[i]=read();
        addedge(1,c[i],W[i]);
    }
    dij(1,0);
    for(int i=0;i<k;i++)
    {
        if(W[i]==dis[c[i]]&&qwq[c[i]]>1)qwq[c[i]]--,ans++;
        else if(W[i]>dis[c[i]])ans++;
    }
    printf("%lld\n",ans);//zhoukangyang baoyouwo buyao uke
}