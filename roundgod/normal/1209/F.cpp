#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,m;
vector<int> G[MAXN][10];
int ans[MAXN];
int d[MAXN];
bool vis[MAXN];
int tot;
void add_edge_one(int u,int v,int w)
{
    G[u][w].push_back(v);
}
void add_edge(int u,int v,int w)
{
    if(w<10) add_edge_one(u,v,w);
    else
    {
        ++tot;
        add_edge_one(tot,v,w%10);
        if(w/10) add_edge(u,tot,w/10);
    }
}
void bfs(int s)
{
    memset(vis,false,sizeof(vis));
    d[s]=0; vis[s]=true;
    queue<int> que;
    que.push(s);
    while(que.size())
    {
        int p=que.front(); que.pop();
        vector<int> vec; vec.clear(); vec.push_back(p);
        while(que.size()&&d[que.front()]==d[p]) vec.push_back(que.front()),que.pop();
        for(int k=0;k<10;k++)
        {
            for(auto v:vec)
            {
                for(auto to:G[v][k])
                {
                    if(vis[to]) continue;
                    d[to]=(10LL*d[v]+k)%MOD;
                    vis[to]=true;
                    que.push(to);
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    tot=n;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,i); add_edge(v,u,i);
    }
    bfs(1);
    for(int i=2;i<=n;i++) printf("%d\n",d[i]);
    return 0;
}