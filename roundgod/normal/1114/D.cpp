#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c[MAXN];
int dp[MAXN][MAXN];
vector<int> v;
int solve(int l,int r)
{
    if(l>=r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    if(v[l]==v[r]) return dp[l][r]=1+solve(l+1,r-1);
    return dp[l][r]=max(solve(l+1,r),solve(l,r-1));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    int now=c[1];
    for(int i=2;i<=n;i++)
    {
        if(c[i]!=now)
        {
            v.push_back(now);
            now=c[i];
        }
    }
    v.push_back(now);
    int sz=(int)v.size();
    memset(dp,-1,sizeof(dp));
    printf("%d\n",sz-1-solve(0,sz-1));
    return 0;
}