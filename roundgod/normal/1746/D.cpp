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
int t,n,k,a[MAXN],p[MAXN];
vector<int> G[MAXN];
int sum[MAXN],maxi[MAXN];
void dfs(int v)
{
    sum[v]=sum[p[v]]+a[v];
    for(auto to:G[v]) dfs(to);
}
pair<ll,int> solve(int v,int k)
{
    if(!G[v].size()) return make_pair(1LL*sum[v]*k,sum[v]);
    int sz=(int)G[v].size();
    ll ans=0;
    vector<int> save;
    for(auto to:G[v])
    {
        auto p=solve(to,k/sz);
        save.push_back(p.S);
        ans+=p.F;
    }
    sort(save.begin(),save.end(),greater<int>());
    for(int i=0;i<k%sz;i++) ans+=save[i];
    return make_pair(ans,save[k%sz]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=2;i<=n;i++) 
        {
            scanf("%d",&p[i]);
            G[p[i]].push_back(i);
        }
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dfs(1);
        printf("%lld\n",solve(1,k).F);
    }
    return 0;
}