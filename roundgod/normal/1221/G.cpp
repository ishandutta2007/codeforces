#include<bits/stdc++.h>
#define MAXN 45
#define MAXM 2000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m,x,y,s,c;
int u[MAXN*MAXN],v[MAXN*MAXN];
vector<int> G[MAXN];
vector<int> mask1,mask2;
int dp[MAXM];
int adj1[MAXM];
int color[MAXN];
int deg[MAXN];
ll p[MAXN];
bool vis[MAXN];
ll find_no_zero()
{
    mask1.clear(); mask2.clear();
    for(int mask=0;mask<(1<<x);mask++)
    {
        bool f=true;
        for(int i=0;i<m;i++)
        {
            if(u[i]>=x||v[i]>=x) continue;
            if((!(mask&(1<<u[i])))&&(!(mask&(1<<v[i]))))
            {
                f=false;
                break;
            }
        }
        if(f) mask1.push_back(mask);
    }
    for(int mask=0;mask<(1<<y);mask++)
    {
        bool f=true;
        for(int i=0;i<m;i++)
        {
            if(u[i]<x||v[i]<x) continue;
            if((!(mask&(1<<(u[i]-x))))&&(!(mask&(1<<(v[i]-x)))))
            {
                f=false;
                break;
            }
        }
        if(f) mask2.push_back(mask);
    }
    memset(dp,0,sizeof(dp));
    for(auto mask:mask2) dp[mask]++;
    for(int i=0;i<y;i++)
		for(int mask=0;mask<(1<<y);mask++)
			if(!(mask&(1<<i)))
				dp[mask]+=dp[mask^(1<<i)];
    ll ans=0;
    for(auto mask:mask1)
    {
        int zeromask=(1<<x)-1-mask;
        ans+=dp[adj1[zeromask]];
    }
    return ans;
}
void get_singleton()
{
    s=0;
    for(int i=0;i<n;i++) if(!deg[i]) s++;
}
void dfs1(int v)
{
    vis[v]=true;
    for(auto to:G[v]) if(!vis[to]) dfs1(to);
}
void get_cmp()
{
    memset(vis,false,sizeof(vis));
    c=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            c++;
            dfs1(i);
        }
    }
}
bool dfs2(int v,int c)
{
    color[v]=c;
    for(auto to:G[v])
    {
        if(color[to]==c) return false;
        if(!color[to]&&!dfs2(to,-c)) return false;
    }
    return true;
}
bool is_bipartite()
{
    memset(color,0,sizeof(color));
    for(int i=0;i<n;i++)
    {
        if(!color[i]&&!dfs2(i,1)) return false;
    }
    return true;
}
int main()
{
    p[0]=1;
    for(int i=1;i<=40;i++) p[i]=p[i-1]*2;
    scanf("%d%d",&n,&m); x=n/2; y=n-x;
    memset(adj1,0,sizeof(adj1));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        u[i]--; v[i]--;
        G[u[i]].push_back(v[i]); G[v[i]].push_back(u[i]);
        if(u[i]>v[i]) swap(u[i],v[i]);
        deg[u[i]]++; deg[v[i]]++;
        if(u[i]>=x) continue;
        if(v[i]<x) continue;
        adj1[(1<<u[i])]|=(1<<(v[i]-x));
    }
    for(int i=0;i<x;i++)
		for(int mask=0;mask<(1<<x);mask++)
			if(mask&(1<<i))
				adj1[mask]|=adj1[mask^(1<<i)];
    get_singleton(); get_cmp();
    ll ans=p[n];
    ans-=2LL*find_no_zero();
    ans-=p[c];
    if(is_bipartite()) ans+=p[c];
    ans+=2LL*p[s];
    if(!m) ans-=p[n];
    printf("%lld\n",ans);
    return 0;
}