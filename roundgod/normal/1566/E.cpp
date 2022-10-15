#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
vector<int> G[MAXN];
P dp[MAXN];
void dfs(int v,int p)
{
    bool is_bud=false;
    int sons=0,sum=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        if(dp[to].S==1) sons++;
        sum+=dp[to].F;
    }
    if(sons) 
    {
        dp[v]=P(sum-1,0);
    }
    else 
    {
        dp[v]=P(sum+1,1);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        int ans=0;
        dfs(1,0);
        bool has_leaf=false;
        for(auto to:G[1]) 
        {
            if(dp[to].S==1) has_leaf=true;
            ans+=dp[to].F;
        }
        if(!has_leaf) ans++;
        printf("%d\n",ans);
    }
    return 0;
}