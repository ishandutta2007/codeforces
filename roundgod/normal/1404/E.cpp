#include<bits/stdc++.h>
#define MAXN 205
#define MAXV 50005
#define INF 1000000
using namespace std;
struct edge{int to,cap,rev;};
int n,m,V;
char mp[MAXN][MAXN];
int id[MAXN][MAXN];
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
    for(int i=0;i<n;i++) scanf("%s",mp[i]);
    int s=n*m+1,t=n*m+2,tot=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]=='#') 
            {
                ++tot;
                id[i][j]=tot;
                if(j==0||mp[i][j-1]=='.') add_edge(s,tot,1); else add_edge(s,tot,0);
                if(i==0||mp[i-1][j]=='.') add_edge(tot,t,1); else add_edge(tot,t,0);
                if(j>0&&mp[i][j-1]=='#') add_edge(id[i][j-1],tot,1);
                if(i>0&&mp[i-1][j]=='#') add_edge(tot,id[i-1][j],1);
            }
    V=t;
    printf("%d\n",max_flow(s,t));
    return 0;
}