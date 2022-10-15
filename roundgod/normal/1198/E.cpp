#include<bits/stdc++.h>
#define MAXN 51
#define MAXV 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 daoskdoa
#define x2 aodksao
#define y1 dksaopdoa
#define y2 dosakdosa
using namespace std;
int n,m;
int x1[MAXN],x2[MAXN],y1[MAXN],y2[MAXN];
vector<int> x,y;
struct edge{int to,cap,rev;};
int V;
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
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
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
        x2[i]++; y2[i]++;
        x.push_back(x1[i]); x.push_back(x2[i]);
        y.push_back(y1[i]); y.push_back(y2[i]);
    }
    sort(x.begin(),x.end()); x.erase(unique(x.begin(),x.end()),x.end());
    sort(y.begin(),y.end()); y.erase(unique(y.begin(),y.end()),y.end());
    V=(int)x.size()+(int)y.size();
    int s=(int)x.size()+(int)y.size()-1,t=(int)x.size()+(int)y.size();
    for(int i=1;i<(int)x.size();i++) add_edge(s,i,x[i]-x[i-1]);
    for(int i=1;i<(int)y.size();i++) add_edge(i+(int)x.size()-1,t,y[i]-y[i-1]);
    for(int i=0;i<m;i++)
    {
        int l1=lower_bound(x.begin(),x.end(),x1[i])-x.begin(),r1=lower_bound(x.begin(),x.end(),x2[i])-x.begin();
        int l2=lower_bound(y.begin(),y.end(),y1[i])-y.begin(),r2=lower_bound(y.begin(),y.end(),y2[i])-y.begin();
        for(int i=l1+1;i<=r1;i++)
            for(int j=l2+1;j<=r2;j++)
                add_edge(i,(int)x.size()-1+j,INF);
    }
    printf("%d\n",max_flow(s,t));
    return 0;
}