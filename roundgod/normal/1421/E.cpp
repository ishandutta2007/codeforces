#include<bits/stdc++.h>
#define MAXN 200005
#define INF 4000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
ll dp[MAXN][3][2];
void upd(ll &a,ll b) {a=max(a,b);}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(n==1)
    {
        printf("%d\n",a[1]);
        return 0;
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<3;j++)
            dp[i][j][0]=dp[i][j][1]=-INF;
    dp[0][0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<2;k++)
            {
                if(dp[i][j][k]!=-INF)
                {
                    upd(dp[i+1][(j+1)%3][k|((j+1)%3==2)],dp[i][j][k]+a[i+1]);
                    upd(dp[i+1][(j+2)%3][k|((j+2)%3==2)],dp[i][j][k]-a[i+1]);
                }
            }
    printf("%lld\n",dp[n][1][1]);
    return 0;
}