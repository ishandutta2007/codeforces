#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],p[MAXN];
vector<int> G[MAXN];
ll dp[MAXN][2];
void dfs(int v)
{
    ll even=0,odd=-INF;
    for(auto to:G[v])
    {
        dfs(to);
        ll teven=even;
        ll todd=odd;
        even=max(teven+dp[to][0],todd+dp[to][1]);
        odd=max(teven+dp[to][1],todd+dp[to][0]);
    }
    dp[v][1]=max(odd,even+a[v]);
    dp[v][0]=even;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&a[i]);
    for(int i=2;i<=n;i++) G[p[i]].push_back(i);
    dfs(1);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
    return 0;
}