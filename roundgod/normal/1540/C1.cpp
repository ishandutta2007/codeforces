#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN],b[MAXN],c[MAXN],x[MAXN];
int dp[MAXN][MAXM];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n-1;i++) scanf("%d",&b[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++) scanf("%d",&x[i]);
    int sb=0;
    ll s=0;
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        if(i>1) {sb+=b[i-1]; s+=sb;}
        for(int j=0;j<=10000;j++)
        {
            if(i>0&&j-s<1LL*x[1]*i) dp[i][j]=0; 
            if(!dp[i][j]) continue;
            if(i<n)
            {
                for(int k=0;k<=c[i+1];k++) add(dp[i+1][j+k],dp[i][j]);
            }
        }
    }
    int ans=0;
    for(int j=0;j<=10000;j++) add(ans,dp[n][j]);
    printf("%d\n",ans);
    return 0;
}