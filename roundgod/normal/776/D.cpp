#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 100005
using namespace std;
int n,m;
vector<int> G[2*MAXM];
vector<int> rG[2*MAXM];
vector<int> vs;
bool used[2*MAXM];
int cmp[2*MAXM];
int sw[MAXN][2];
int open[MAXN];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<2*m;v++)
    {
        if(!used[v]) dfs(v);
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&open[i]);
    memset(sw,-1,sizeof(sw));
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d",&x);
        for(int j=0;j<x;j++)
        {
            scanf("%d",&y);
            y--;
            if(sw[y][0]==-1) sw[y][0]=i; else sw[y][1]=i;
        }
    }
    for(int i=0;i<n;i++)
    {
        int a=sw[i][0],b=sw[i][1];
        if(open[i]==0)
        {
            add_edge(2*a+1,2*b);
            add_edge(2*b,2*a+1);
            add_edge(2*a,2*b+1);
            add_edge(2*b+1,2*a);
        }
        else
        {
            add_edge(2*a,2*b);
            add_edge(2*b,2*a);
            add_edge(2*a+1,2*b+1);
            add_edge(2*b+1,2*a+1);
        }
    }
    scc();
    for(int i=0;i<m;i++)
    {
        if(cmp[2*i]==cmp[2*i+1])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}