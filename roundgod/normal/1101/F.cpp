#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 402
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int dp[MAXN][MAXN][MAXN],A[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%d",&a[i]);
    for(ll i=0;i<=n;i++)
        for(ll j=i;j<=n;j++)
            dp[1][i][j]=a[j]-a[i];
    for(ll k=2;k<=n+1;k++)
    {
        for(ll i=0;i<=n;i++) {A[i][i]=i; dp[k][i][i]=0;}
        for(ll l=2;l<=n;l++)
        {
            for(ll i=0;i+l-1<=n;i++)
            {
                ll j=i+l-1;dp[k][i][j]=INF;
                for(ll mid=A[i][j-1];mid<=A[i+1][j];mid++)
                {
                    if(max(a[mid]-a[i],dp[k-1][mid][j])<dp[k][i][j])
                    {
                        dp[k][i][j]=max(a[mid]-a[i],dp[k-1][mid][j]);
                        A[i][j]=mid;
                    }
                    //if(k==2&&i==4&&j==5) printf("%lld %lld %lld\n",mid,dp[k][i][j],dp[k-1][mid][j]);
                }
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<m;i++)
    {
        ll s,f,c,r;
        scanf("%lld%lld%lld%lld",&s,&f,&c,&r);
        //printf("%lld %lld %lld %lld\n",s,f,c,r);
        //printf("%lld\n",dp[r+1][s][f]);
        ans=max(ans,1LL*dp[r+1][s][f]*c);
    }
    printf("%lld\n",ans);
    return 0;
}