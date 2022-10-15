#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
int cnt=0;
int n,tot,sz[MAXN],dep[MAXN],type[MAXN];
void dfs(int v,int p,int d)
{
    dep[v]=d;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,d+1);
    }
}

P getroot(int v,int p,int t)//search_centroid
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
vector<int> vec;
void dfs2(int v,int p)
{
    ++cnt;
    vec.push_back(v);
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v);
    }
}
int ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int rt=getroot(1,0,n).S;
    dfs(rt,0,0);
    ll res=0;
    for(int i=1;i<=n;i++) res+=2*dep[i];
    printf("%lld\n",res);
    vec.push_back(rt);
    for(auto to:G[rt])
    {
        ++tot;
        cnt=0;
        dfs2(to,rt);
        assert(cnt*2<=n);
    }
    int sz=(int)vec.size();
    for(int i=0;i<sz;i++)
    {
        int x=vec[i],y=vec[(i+sz/2)%sz];
        ans[x]=y;
    }
    for(int i=1;i<=n;i++) assert(ans[i]!=i);
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}