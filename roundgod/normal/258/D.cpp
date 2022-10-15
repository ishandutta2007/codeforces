#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN],b[MAXN];
int p[MAXN];
double dp[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=m;i>=1;i--) scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            dp[i][j]=1.0;
    for(int i=1;i<=m;i++)
    {
        int x=a[i],y=b[i];
        dp[x][y]=dp[y][x]=0.5;
        for(int j=1;j<=n;j++)
        {
            if(j==y||j==x) continue;
            dp[x][j]=dp[y][j]=0.5*(dp[x][j]+dp[y][j]);
            dp[j][x]=dp[j][y]=0.5*(dp[j][x]+dp[j][y]);
        }
    }
    double ans=0.0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(p[i]>p[j]) ans+=dp[i][j]; else ans+=dp[j][i];
    printf("%.10f\n",ans);
    return 0;
}