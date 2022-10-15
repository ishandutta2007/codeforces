#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
vector<int> pos[MAXN];
int dp[MAXN][MAXN];
int solve(int l,int r)
{
    if(l>r) return -1;
    if(l==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    dp[l][r]=min(solve(l+1,r),solve(l,r-1))+1;
    if(a[l]==a[r]) dp[l][r]=min(dp[l][r],solve(l+1,r-1)+1);
    for(auto x:pos[a[l]])
        if(x>l&&x<r) 
            dp[l][r]=min(dp[l][r],solve(l,x)+solve(x+1,r)+(a[l]==a[r]?0:1));
    for(auto x:pos[a[r]])
        if(x>l&&x<r) 
            dp[l][r]=min(dp[l][r],solve(x,r)+solve(l,x-1)+(a[l]==a[r]?0:1));
    return dp[l][r];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) pos[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]].push_back(i);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=-1;
        printf("%d\n",solve(1,n));
    }
    return 0;
}