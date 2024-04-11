#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXM 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
vector<int> G[MAXN];
int fa[MAXN];
double pr[MAXN],sumpr[MAXN];
void dfs(int v,int p)
{
    fa[v]=p;
    for(auto to:G[v])
    {
        if(to==p) continue;
        sumpr[v]+=(1.0-pr[to]);
        dfs(to,v);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf",&pr[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u++; v++;
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    double ans=0;
    for(int i=1;i<=n;i++) ans+=pr[i]*sumpr[i];
    ans+=(1.0-pr[1]);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int v; double d;
        scanf("%d%lf",&v,&d);
        v++;
        ans-=(1.0-pr[1]);
        if(fa[v])
        {
            ans-=pr[fa[v]]*sumpr[fa[v]];
            sumpr[fa[v]]-=(d-pr[v]);
            ans+=pr[fa[v]]*sumpr[fa[v]];
        }
        ans-=pr[v]*sumpr[v];
        pr[v]=d;
        ans+=pr[v]*sumpr[v];
        ans+=(1.0-pr[1]);
        printf("%.10f\n",ans);
    }
    return 0;
}