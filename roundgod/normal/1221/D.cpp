#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n;
int a[MAXN],b[MAXN];
ll dp[MAXN][3];
void upd(ll &a,ll b) {a=min(a,b);}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        a[0]=-MOD;
        for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=dp[i][2]=INF;
        dp[0][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(dp[i][j]==INF) continue;
                for(int k=0;k<3;k++) if(a[i]+j!=a[i+1]+k) upd(dp[i+1][k],dp[i][j]+1LL*k*b[i+1]);
            }
        }
        printf("%lld\n",min(dp[n][0],min(dp[n][1],dp[n][2])));
    }
    return 0;
}