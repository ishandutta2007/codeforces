#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,dp[MAXN][MAXN][3],a[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int solve(int l,int r,int flag)
{
    assert(l<r);
    if(r-l<2) return 1;
    if(dp[l][r][flag]!=-1) return dp[l][r][flag];
    int &ans=dp[l][r][flag];
    ans=0;
    if(flag!=0)
    {
        for(int mid=l+1;mid<=r-1;mid++)
        {
            if(!a[mid][l]) continue;
            add(ans,1LL*solve(l,mid,2)*solve(mid,r,flag)%MOD);
        }
    }
    if(flag!=1)
    {
        for(int mid=l+1;mid<=r-1;mid++)
        {
            if(!a[mid][r]) continue;
            add(ans,1LL*solve(l,mid,0)*solve(mid,r,2)%MOD);
        }
    }
    //printf("%d %d %d %d\n",l,r,flag,ans);
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(j==n) a[i][0]=a[i][j];
            if(i==n) a[0][j]=a[i][j];
        }
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=1;i<=n-1;i++) if(a[i][n]) add(ans,1LL*solve(0,i,2)*solve(i,n,1)%MOD);
    printf("%d\n",ans);
    return 0;
}