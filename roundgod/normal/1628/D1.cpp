#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int dp[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
            for(int j=0;j<=i;j++)
            {
                if(j==i) dp[i][j]=1LL*i*k%MOD;
                else if(j==0) dp[i][j]=0;
                else dp[i][j]=1LL*(dp[i-1][j]+dp[i-1][j-1])*INV%MOD;
            }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}