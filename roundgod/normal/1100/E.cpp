#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge
{
    int from,to,cost,id;
};
int n,m,ord[MAXN];
vector<edge> G[MAXN];
vector<int> order,ans;
vector<edge> E;
bool f;
int color[MAXN];
void add_edge(int u,int v,int cost,int id)
{
    G[u].push_back((edge){u,v,cost,id});
}
void dfs(int v,int x,int save)
{
    if(!f) return;
    color[v]=1;
    for(auto e:G[v])
    {
        if(e.cost<=x)
        {
            if(save) E.push_back(e);
            continue;
        }
        if(color[e.to]==1)
        {
            f=false;
            return;
        }
        else if(color[e.to]==0) dfs(e.to,x,save);
    }
    color[v]=2;
    if(save)order.push_back(v);
}
bool C(int x,int save=0)
{
    memset(color,0,sizeof(color));
    f=true;
    for(int i=1;i<=n;i++)
    {
        if(!color[i]) dfs(i,x,save);
        if(!f) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        add_edge(u,v,c,i);
    }
    int l=-1,r=INF;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    printf("%d ",r);C(r,1);
    reverse(order.begin(),order.end());
    for(int i=0;i<(int)order.size();i++) ord[order[i]]=i;
    for(auto e:E)
    {
        if(ord[e.from]>ord[e.to]) ans.push_back(e.id);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for(auto v:ans) printf("%d ",v);
    puts("");
    return 0;
}