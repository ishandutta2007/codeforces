#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
vector<int> G[MAXN];
P dp[MAXN];
int ans[MAXN];
void dfs(int v,int p)
{
    dp[v]=P(0,0);
    int mx1=0,mx2=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        dp[v].F+=dp[to].F;
        if(dp[to].S>mx1)
        {
            mx2=mx1;
            mx1=dp[to].S;
        }
        else if(dp[to].S>mx2) mx2=dp[to].S;
    }
    if(mx1+mx2+1>=k) dp[v].F++;
    else dp[v].S=mx1+1;
}
void solve(int l,int r,int vl,int vr)
{
    if(vl==vr||l+1==r)
    {
        for(int i=l;i<r;i++) ans[i]=vl;
        return;
    }
    int mid=(l+r)/2,v;
    k=mid;
    dfs(1,0);
    v=dp[1].F;
    solve(l,mid,vl,v); solve(mid,r,v,vr);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    solve(1,n+1,n,0);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}