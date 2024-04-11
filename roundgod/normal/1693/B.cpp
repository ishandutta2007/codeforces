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
int t,n,k,a[MAXN];
int p[MAXN];
vector<int> G[MAXN];
int l[MAXN],r[MAXN];
P dp[MAXN];
void dfs(int v)
{
    if(!G[v].size())
    {
        dp[v]=P(1,r[v]);
        return;
    }
    int sum=0,ss=0;
    for(auto to:G[v])
    {
        dfs(to);
        sum+=dp[to].F;
        ss=min(INF,ss+dp[to].S);
    }
    dp[v]=P(sum+1,r[v]);
    if(l[v]<=ss) dp[v]=P(sum,min(r[v],ss));
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=2;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            G[x].push_back(i);
        }
        for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
        dfs(1);
        printf("%d\n",dp[1].F);
    }
    return 0;
}