#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<P> G[MAXN];
int color[MAXN],fa[MAXN],faid[MAXN],depth[MAXN];
struct edge
{
    int u,v,id;
};
vector<edge> edges;
void dfs(int v,int p,int d)
{
    color[v]=1; fa[v]=p; depth[v]=d;
    for(auto e:G[v])
    {
        int to=e.F,id=e.S;
        if(to==p) continue;
        if(color[to]==0) {faid[to]=id; dfs(to,v,d+1);}
        else if(color[to]==1)
        {
            edges.push_back((edge){v,to,id});
        }
    }
    color[v]=2;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(P(v,i)); G[v].push_back(P(u,i));
        }
        for(int i=1;i<=n;i++) color[i]=0;
        edges.clear();
        dfs(1,0,0);
        set<int> s;
        for(auto p:edges) {s.insert(p.u),s.insert(p.v);}
        if(m==n+2&&s.size()==3)
        {
            int u=edges[2].u,v=edges[2].v;
            if(depth[u]<depth[v]) swap(u,v);
            edges.pop_back();
            edges.push_back((edge){u,fa[u],faid[u]});
        }
        string str="";
        for(int i=0;i<m;i++) str+='1';
        for(auto p:edges) str[p.id]='0';
        cout<<str<<endl;
    }
    return 0;
}