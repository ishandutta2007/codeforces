#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to; ll cost;};
int n,m,ans;
vector<edge> G[MAXN];
int vis[MAXN];
int p2[MAXN],dep[MAXN],sz[MAXN];
int sum[MAXN];
ll w[MAXN],bas[60];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void add_edge(int u,int v,ll w)
{
    G[u].push_back((edge){v,w});
    G[v].push_back((edge){u,w});
}
int r;
int ccnt[60],cnt[2][60];
void add_basis(ll x)
{
    for(int j=59;j>=0;j--)
    {
        if(x&(1LL<<j))
        {
            if(!bas[j])
            {
                bas[j]=x;
                r++;
                for(int k=0;k<60;k++) if(x&(1LL<<k)) ccnt[k]++;
                return;
            }
            x^=bas[j];
        }
    }
}
void dfs(int v,int p)
{
    vis[v]++;
    sz[v]=1;
    for(auto e:G[v])
    {
        int to=e.to;
        ll cost=e.cost;
        if(to==p) continue;
        if(vis[to])
        {
            if(dep[to]<dep[v])
            {
                ll res=w[v]^w[to]^cost;
                add_basis(res);
            }
            continue;
        }
        dep[to]=dep[v]+1; w[to]=w[v]^cost;
        dfs(to,v);
        sz[v]+=sz[to];
    }
    for(int i=0;i<60;i++) if(w[v]&(1LL<<i)) cnt[1][i]++; else cnt[0][i]++;
}
void solve(int v)
{
    memset(cnt,0,sizeof(cnt));
    memset(ccnt,0,sizeof(ccnt));
    memset(bas,0,sizeof(bas));
    r=0;
    dfs(v,0);
    int s=sz[v];
    for(int i=0;i<60;i++)
    {
        if(!ccnt[i]) add(ans,1LL*p2[r]%MOD*cnt[0][i]%MOD*cnt[1][i]%MOD*p2[i]%MOD);
        else add(ans,1LL*p2[r-1]*sum[s]%MOD*p2[i]%MOD);
    }
}
int main()
{
    p2[0]=1;
    for(int i=1;i<=100000;i++) p2[i]=2LL*p2[i-1]%MOD;
    for(int i=1;i<=100000;i++) sum[i]=(1LL*i*(i-1)/2)%MOD;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v; ll w;
        scanf("%d%d%lld",&u,&v,&w);
        add_edge(u,v,w);
    }
    ans=0;
    for(int i=1;i<=n;i++) if(!vis[i]) solve(i);
    printf("%d\n",ans);
    return 0;
}