#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,dp[MAXN][MAXN];
P save[MAXN][MAXN];
int solve(int l,int r)
{
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int &res=dp[l][r];
    res=0;
    for(int k=l;k<=r;k++)
    {
        int tmp=solve(l,k-1)+solve(k+1,r);
        int cnt=0;
        for(int j=1;j<=n;j++) if(save[j][k].F>=l&&save[j][k].S<=r) cnt++;
        res=max(res,tmp+cnt*cnt); 
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            for(int jj=l;jj<=r;jj++) save[i][jj]=P(l,r);
        }
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",solve(1,m));
    return 0;
}