#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int sz[MAXN];
double dp[MAXN];
vector<int> G[MAXN];
void dfs1(int v)
{
    sz[v]=1;
    for(auto to:G[v])
    {
        dfs1(to);
        sz[v]+=sz[to];
    }
}
void dfs2(int v)
{
    for(auto to:G[v])
    {
        dp[to]=dp[v]+1+0.5*(sz[v]-1-sz[to]);
        dfs2(to);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        G[p].push_back(i);
    }
    dfs1(1);
    dp[1]=1.0;
    dfs2(1);
    for(int i=1;i<=n;i++) printf("%.10f ",dp[i]);
    return 0;
}