#include<bits/stdc++.h>
#define MAXN 505
#define MAXM 20005
#define INF 1000000000
using namespace std;
struct edge{int to,cap,rev;};
int n;
int a[MAXN],prime[MAXM];
bool is_prime[MAXM];
vector<edge> G[MAXN];
int level[MAXN];
int iter[MAXN];
bool vis[MAXN];
void sieve(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(i*prime[j]>n) break;
            is_prime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}
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
int cnt;
vector<int> con[MAXN];
vector<int> ans[MAXN];
void dfs(int v,int p)
{
    ans[cnt].push_back(v);
    vis[v]=true;
    if(con[v][0]!=p&&!vis[con[v][0]]) dfs(con[v][0],v);
    else if(con[v][1]!=p&&!vis[con[v][1]]) dfs(con[v][1],v);
}
int main()
{
    sieve(20000);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int s=n+1,t=n+2;
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1) add_edge(s,i,2);
        else add_edge(i,t,2);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i]%2==0) continue;
            if(is_prime[a[i]+a[j]]) add_edge(i,j,1);
        }

    int f=max_flow(s,t);
    if(f!=n) puts("Impossible");
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]&1)
            {
                for(auto e:G[i])
                {
                    if(e.to==s||e.to==t) continue;
                    if(!e.cap)
                    {
                        con[i].push_back(e.to);
                        con[e.to].push_back(i);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) assert(con[i].size()==2);
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                dfs(i,0);
                cnt++;
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++)
        {
            printf("%d",ans[i].size());
            for(auto x:ans[i]) printf(" %d",x);
            puts("");
        }
    }
    return 0;
}