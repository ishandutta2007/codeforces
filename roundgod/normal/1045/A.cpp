#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 30005
#define MAXV 30005
#define MAXE 50000
#define INF 1000000
using namespace std;
struct edge{int to,cap,rev;};
int V,maxi;
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
int lb[MAXN],rb[MAXN];
int type[MAXN],x[MAXN],y[MAXN],z[MAXN];
int n,m;
vector<int> v[MAXN];
int where[MAXN];
int id[MAXN],rev[MAXE];
void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front(); que.pop();
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v,int t,int f)
{
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0)
          flow+=f;
    }
}
void build(int k,int l,int r)
{
    lb[k]=l; rb[k]=r;
    if(l==r)
    {
        id[l]=n+k; maxi=max(maxi,id[l]);
        rev[n+k]=l;
        return;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid); build(k*2+1,mid+1,r);
    add_edge(n+k,n+k*2,INF); add_edge(n+k,n+k*2+1,INF);
}
void add_range_edge(int v,int k,int l,int r,int x,int y)
{
    if(l>y||x>r) return;
    if(l>=x&&r<=y)
    {
        add_edge(v,n+k,1);
        return;
    }
    int mid=(l+r)/2;
    add_range_edge(v,k*2,l,mid,x,y); add_range_edge(v,k*2+1,mid+1,r,x,y);
}
int get_ans(int k,int l,int r)
{
   // printf("%d %d %d\n",k,l,r);

    if(l==r) return l;
    int mid=(l+r)/2;
    for(auto &e:G[n+k])
    {
        if(e.to!=n+k*2&&e.to!=n+k*2+1) continue;
        if(e.cap==INF) continue;
        e.cap++;
        if(e.to==n+k*2) return get_ans(k*2,l,mid);
        else return get_ans(k*2+1,mid+1,r);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    maxi=0; build(1,1,m);
    V=maxi;
    int s=V+1,t=V+2;
    for(int i=1;i<=m;i++) add_edge(id[i],t,1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&type[i]);
        if(type[i]==0)
        {
            add_edge(s,i,1);
            int k;
            scanf("%d",&k);
            for(int j=0;j<k;j++)
            {
                int x;
                scanf("%d",&x);
                add_edge(i,id[x],1);
            }
        }
        else if(type[i]==1)
        {
            add_edge(s,i,1);
            int l,r;
            scanf("%d%d",&l,&r);
            add_range_edge(i,1,1,m,l,r);
        }
        else
        {
            add_edge(s,i,2);
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
            add_edge(i,id[x[i]],1); add_edge(i,id[y[i]],1); add_edge(i,id[z[i]],1);
        }
    }
    printf("%d\n",max_flow(s,t));
    for(int i=1;i<=n;i++)
    {
        if(type[i]==1) continue;
        for(auto e:G[i])
        {
            if(e.to<n+1||e.to>V) continue;
            if(e.cap!=0) continue;
            v[i].push_back(rev[e.to]);
            where[rev[e.to]]=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(type[i]!=1) continue;
        for(auto e:G[i])
        {
            if(e.to<n+1||e.to>V) continue;
            if(e.cap!=0) continue;
            int val=get_ans(e.to-n,lb[e.to-n],rb[e.to-n]);
            v[i].push_back(val);
            where[val]=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(type[i]==2&&(int)v[i].size()==1)
        {
            if(v[i][0]!=x[i]&&where[x[i]])
            {
                int u=where[x[i]];
                v[u].clear();
                where[x[i]]=i;
                v[i].push_back(x[i]);
            }
            else if(v[i][0]!=y[i]&&where[y[i]])
            {
                int u=where[y[i]];
                v[u].clear();
                where[y[i]]=i;
                v[i].push_back(y[i]);
            }
            else
            {
                int u=where[z[i]];
                v[u].clear();
                where[z[i]]=i;
                v[i].push_back(z[i]);
            }
        }
    }
    for(int i=1;i<=m;i++) if(where[i]) printf("%d %d\n",where[i],i);
    return 0;
}