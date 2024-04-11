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
int n,m,q,indeg[MAXN],outdeg[MAXN];
vector<int> G[MAXN];
ll ans=0;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v) swap(u,v);
        G[u].push_back(v); indeg[u]++; outdeg[v]++;
    }
    for(int i=1;i<=n;i++) ans+=1LL*indeg[i]*outdeg[i];
    printf("%lld\n",ans);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int v;
        scanf("%d",&v);
        ans-=1LL*indeg[v]*outdeg[v];
        for(auto to:G[v])
        {
            ans-=1LL*indeg[to]*outdeg[to];
            outdeg[to]--; indeg[to]++;
            ans+=1LL*indeg[to]*outdeg[to];
            G[to].push_back(v);
        }
        G[v].clear();
        outdeg[v]=indeg[v]+outdeg[v]; indeg[v]=0;
        printf("%lld\n",ans);
    }
    return 0;
}