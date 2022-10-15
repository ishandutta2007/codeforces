#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int dp[MAXN][2*MAXN];
void upd(int &a,int b) {a=min(a,b);}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=0;i<=200;i++)
            for(int j=0;j<=400;j++)
                dp[i][j]=INF;
        dp[0][0]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<=400;j++)
            {
                if(dp[i][j]==INF) continue;
                upd(dp[i][j+1],dp[i][j]);
                upd(dp[i+1][j+1],dp[i][j]+max(j+1-a[i+1],a[i+1]-j-1));
            }
        int ans=INF;
        for(int j=0;j<=400;j++) ans=min(ans,dp[n][j]);
        printf("%d\n",ans);
    }
    return 0;
}