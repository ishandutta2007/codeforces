#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l,k,d[MAXN],a[MAXN];
int dp[MAXN][MAXN];
void upd(int &a,int b) {a=min(a,b);}
int main()
{
    scanf("%d%d%d",&n,&l,&k);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=2*INF;
    dp[1][1]=a[1]*l;
    int ans=2*INF;
    for(int i=1;i<n;i++)
        for(int j=1;j<n;j++)
        {
            if(dp[i][j]==2*INF) continue;
            for(int nxt=i+1;nxt<=n;nxt++)
                upd(dp[nxt][j+1],dp[i][j]+(a[nxt]-a[i])*(l-d[nxt]));
        }
    for(int i=1;i<=n;i++) 
        for(int j=n-k;j<=n;j++)
            upd(ans,dp[i][j]);
    printf("%d\n",ans);
    return 0;
}