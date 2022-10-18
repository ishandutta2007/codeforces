#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define MAXN 400005
struct eric
{
    int to,next,v;
}edge[MAXN<<1];
int head[MAXN],soze=1;
void add(int x,int y,int z)
{
    edge[++soze].to=y;
    edge[soze].v=z;
    edge[soze].next=head[x];
    head[x]=soze;
}
int n,m;
ll dis[MAXN][2];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > bob;
#define INF (1ll<<60)
void spfa()
{
    for(int i=1;i<=n;i++)
    dis[i][0]=dis[i][1]=INF;
    dis[1][0]=0;
    bob.push({0,1});
    while(!bob.empty())
    {
        ll dist=bob.top().fi;int u=bob.top().se,tp=0;
        bob.pop();
        if(u>n)
        u-=n,tp^=1;
        if(dist!=dis[u][tp])
        continue;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(i&1)
            {
                if(dis[v][1]>dis[u][tp]+edge[i].v)
                {
                    dis[v][1]=dis[u][tp]+edge[i].v;
                    bob.push({dis[v][1],v+n});
                }
            }
            else
            {
                if(tp==0&&dis[v][0]>dis[u][tp]+edge[i].v)
                {
                    dis[v][0]=dis[u][tp]+edge[i].v;
                    bob.push({dis[v][0],v});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    spfa();
    for(int i=2;i<=n;i++)
    {
        ll out=min(dis[i][0],dis[i][1]);
        if(out==INF)
        cout<<"-1 ";
        else
        cout<<out<<' ';
    }
    cout<<'\n';
    // cerr<<dis[2][1]<<endl;
}