#include<bits/stdc++.h>
#define MAXN 2005
#define MAXV 3005
#define MAXE 50000
#define INF 1000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,rev;};
int n,m,males,females;
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
int V,source,sink,k;
struct node
{
    int r,c,t;
};
vector<node> a,b;
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
char str[25][25];
int dist[505][505];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void bfs()
{
    for(int i=1;i<=n*m;i++)
        for(int j=1;j<=n*m;j++)
            dist[i][j]=INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='#') continue;
            queue<P> que;
            int x=(i-1)*m+j;
            dist[x][x]=0;
            que.push(P(i,j));
            while(que.size())
            {
                P p=que.front(); que.pop();
                int curid=(p.F-1)*m+p.S;
                for(int k=0;k<4;k++)
                {
                    int nx=p.F+dx[k],ny=p.S+dy[k];
                    int id=(nx-1)*m+ny;
                    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&str[nx][ny]!='#'&&dist[x][id]==INF)
                    {
                        dist[x][id]=dist[x][curid]+1;
                        que.push(P(nx,ny));
                    }
                }
            }
        }
}
vector<ll> times;
bool check(ll t)
{
    for(int i=1;i<=V;i++) G[i].clear();
    for(int i=1;i<=k;i++) add_edge(source,i,1);
    for(int i=k+1;i<=2*k;i++) add_edge(i,sink,1);
    for(int i=1;i<=n*m;i++) add_edge(2*k+i,2*k+n*m+i,1);
    for(int i=1;i<=k;i++)
    {
        int id=(a[i-1].r-1)*m+a[i-1].c;
        for(int j=1;j<=n*m;j++)
        {
            if(dist[id][j]==INF||1LL*a[i-1].t*dist[id][j]>t) continue;
            add_edge(i,2*k+j,1);
        }
    }
    for(int i=1;i<=k;i++)
    {
        int id=(b[i-1].r-1)*m+b[i-1].c;
        for(int j=1;j<=n*m;j++)
        {
            if(dist[id][j]==INF||1LL*b[i-1].t*dist[id][j]>t) continue;
            add_edge(2*k+n*m+j,k+i,1);
        }
    }
    return max_flow(source,sink)==k;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&males,&females);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    int r,c,t;
    scanf("%d%d%d",&r,&c,&t);
    bool f=true;
    if(males==females-1) a.push_back((node){r,c,t});
    else if(males==females+1) b.push_back((node){r,c,t});
    else f=false;
    for(int i=0;i<males;i++)
    {
        scanf("%d%d%d",&r,&c,&t);
        a.push_back((node){r,c,t});
    }
    for(int i=0;i<females;i++)
    {
        scanf("%d%d%d",&r,&c,&t);
        b.push_back((node){r,c,t});
    }
    if(!f) {puts("-1"); return 0;}
    bfs();
    for(auto p:a)
    {
        int id=(p.r-1)*m+p.c;
        for(int i=1;i<=n*m;i++)
        {
            if(dist[id][i]==INF) continue;
            times.push_back(1LL*p.t*dist[id][i]);
        }
    }
    for(auto p:b)
    {
        int id=(p.r-1)*m+p.c;
        for(int i=1;i<=n*m;i++)
        {
            if(dist[id][i]==INF) continue;
            times.push_back(1LL*p.t*dist[id][i]);
        }
    }
    k=(int)a.size();
    sort(times.begin(),times.end());
    times.erase(unique(times.begin(),times.end()),times.end());
    V=2*k+2*n*m+2;
    source=V-1; sink=V;
   // assert(check(1));
    int l=-1; r=(int)times.size()-1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(times[mid])) r=mid; else l=mid;
    }
    if(!check(times[r])) puts("-1"); else printf("%lld\n",times[r]);
    return 0;
}