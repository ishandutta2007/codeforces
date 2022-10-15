#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 100005
#define MAXK 100005
#define MAXM 305
#define MAXLOGV 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXV];
vector<int> vt[MAXV];
int parent[MAXLOGV][MAXV];
int depth[MAXV],dfn[MAXV],st[MAXV],cnt;
int fact[MAXM],invf[MAXM];
int dp[MAXK];
bool special[MAXV];
int n,q,tot,k,m,r;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
void add_edge(int from,int to)
{
    vt[from].push_back(to);
    vt[to].push_back(from);
}
bool cmp(int x,int y)
{
    return dfn[x]<dfn[y];
}
void dfs(int v,int p,int d)
{
    dfn[v]=++tot;
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGV;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    for(int k=0;k<MAXLOGV;k++)
    {
        if((depth[v]-depth[u])>>k&1)
            v=parent[k][v];
    }
    if(u==v) return u;
    for(int k=MAXLOGV-1;k>=0;k--)
    {
        if(parent[k][u]!=parent[k][v])
        {
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
int build_vtree(vector<int> &a)
{
    sort(a.begin(),a.end(),cmp);
    a.erase(unique(a.begin(),a.end()),a.end());
    assert(a.size()>0);
    int t=0;
    st[t++]=a[0];
    vector<int> newly;newly.clear();
    for(int i=1;i<(int)a.size();i++)
    {
        if(t==0) {st[t++]=a[i]; continue;}
        int l=lca(a[i],st[t-1]);
        while(t>1&&dfn[st[t-2]]>=dfn[l]) add_edge(st[t-2],st[t-1]),t--;
        if(l!=st[t-1]) {add_edge(l,st[t-1]),st[t-1]=l; newly.push_back(l);}
        st[t++]=a[i];
    }
    while(t>1) add_edge(st[t-2],st[t-1]),t--;
    for(auto it:newly) a.push_back(it);
    return st[0];
}
void dfs2(int v,int pa,int cnt=0)
{
    //printf("%d\n",v);
    if(special[v]) 
    {
        for(int i=m;i>=1;i--)
        {
            if(i>cnt) dp[i]=1LL*dp[i]*(i-cnt)%MOD; else dp[i]=0;
            add(dp[i],dp[i-1]);
        }
        dp[0]=0;
        cnt++;
    }
    for(auto to:vt[v])
    {
        if(to==pa) continue;
        dfs2(to,v,cnt);
    }
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=300;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[300]=pow_mod(fact[300],MOD-2);
    for(int i=299;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&n,&q);
    memset(special,false,sizeof(special));
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    init(n);
    for(int i=0;i<q;i++)
    {
        scanf("%d%d%d",&k,&m,&r);
        vector<int> nodes; nodes.clear();
        for(int i=0;i<k;i++)
        {
            int x;scanf("%d",&x);special[x]=true;
            nodes.push_back(x);
        }
        nodes.push_back(r);
        build_vtree(nodes);
        int root=r;
        memset(dp,0,sizeof(dp));dp[0]=1;
        dfs2(root,-1);
        int ans=0;
        for(int i=0;i<=m;i++) add(ans,dp[i]);
        printf("%d\n",ans);
        for(auto v:nodes) vt[v].clear();
        for(auto v:nodes) special[v]=false;
    }
    return 0;
}