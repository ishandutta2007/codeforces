#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c;
int p[MAXN],s[MAXN];
ll dp[2][MAXN];
void update(ll &a,ll b) {a=min(a,b);}
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    for(int i=0;i<2;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        int now=i&1,nxt=now^1;
        for(int j=0;j<=n;j++) dp[nxt][j]=INF;
        for(int j=0;j<=i;j++)
        {
            if(dp[now][j]==INF) continue;
            update(dp[nxt][j],dp[now][j]+p[i+1]+1LL*c*j);
            update(dp[nxt][j+1],dp[now][j]+s[i+1]);
        }
    }
    ll ans=INF;
    for(int i=0;i<=n;i++) ans=min(ans,dp[n&1][i]);
    printf("%lld\n",ans);
    return 0;
}