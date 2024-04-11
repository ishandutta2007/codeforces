#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m;
struct edge
{
    ll to,cost;
};
vector<edge> GG[MAXN];
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
ll cmp[MAXN];
ll x[MAXN],y[MAXN],w[MAXN],cost[MAXN],val[MAXN],s,dp[MAXN];
ll save[20001],sum[20001];
ll find_ans(ll x)
{
    if(x==0) return 0;
    ll l=1,r=20000;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(x-save[mid]>=0) l=mid; else r=mid;
    }
    return (l+1)*x-sum[l];
}
void add_edge(ll from,ll to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(ll v)
{
    used[v]=true;
    for(ll i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(ll v,ll k)
{
    used[v]=true;
    cmp[v]=k;
    for(ll i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
ll scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(ll v=0;v<n;v++)
    {
        if(!used[v]) dfs(v);
    }
    ll k=0;
    memset(used,0,sizeof(used));
    for(ll i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
ll color[MAXN];
deque<int> order;
void dfs_visit(ll v)
{
    color[v]=1;
    for(ll i=0;i<GG[v].size();i++)
    {
        ll to=GG[v][i].to;
        if(color[to]==0) dfs_visit(to);
    }
    color[v]=2;
    order.push_front(v);
}
int main()
{
    scanf("%I64d%I64d",&n,&m);
    save[0]=0;
    for(ll i=1;i<=20000;i++)
        save[i]=i*(i+1)/2;
    sum[0]=0;
    for(ll i=1;i<=20000;i++)
        sum[i]=sum[i-1]+save[i];
    for(ll i=0;i<m;i++)
    {
        scanf("%I64d%I64d%I64d",&x[i],&y[i],&w[i]);
        x[i]--;
        y[i]--;
        add_edge(x[i],y[i]);
        cost[i]=find_ans(w[i]);
    }
    ll p=scc();
    memset(val,0,sizeof(val));
    for(ll i=0;i<m;i++)
    {
        if(cmp[x[i]]==cmp[y[i]]) val[cmp[x[i]]]+=cost[i];
        else GG[cmp[x[i]]].push_back((edge){cmp[y[i]],w[i]});
    }
    scanf("%I64d",&s);
    s--;
    ll now=cmp[s];
    memset(color,0,sizeof(color));
    dfs_visit(now);
    bool f=false;
    memset(dp,0,sizeof(dp));
    dp[now]=val[now];
    for(ll i=0;i<order.size();i++)
    {
        if(order[i]==now) f=true;
        if(!f) continue;
        for(ll j=0;j<GG[order[i]].size();j++)
        {
            ll to=GG[order[i]][j].to,cost=GG[order[i]][j].cost;
            dp[to]=max(dp[to],dp[order[i]]+cost+val[to]);
        }
    }
    ll ans=0;
    for(ll i=0;i<p;i++)
        ans=max(ans,dp[i]);
    printf("%I64d\n",ans);
    return 0;
}