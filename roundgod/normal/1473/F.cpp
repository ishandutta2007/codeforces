#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
using namespace std;
struct edge{int to,cap,rev;};
int V,n,a[MAXN],b[MAXN];
vector<edge> G[MAXN];
int level[MAXN];
int iter[MAXN];
map<int,int> last;
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
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    V=n+2;
    int s=n+1,t=n+2;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>=0) {add_edge(s,i,b[i]); ans+=b[i];} else add_edge(i,t,-b[i]);
        for(int j=1;1LL*j*j<=a[i];j++)
        {
            if(a[i]%j) continue;
            if(last[j]) add_edge(i,last[j],INF);
            if(j!=a[i]/j&&last[a[i]/j]) add_edge(i,last[a[i]/j],INF);
        }
        last[a[i]]=i;
    }
    printf("%d\n",ans-max_flow(s,t));
    return 0;
}