#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],cnt[MAXN];
int dp[MAXN][5][5];
void upd(int &a,int b) {a=max(a,b);}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<=4;j++)
            for(int k=0;k<=4;k++)
            {
                if(dp[i][j][k]==-1) continue;
                int minx=min(j,k);
                for(int l=0;l<=minx;l++)
                {
                    if(cnt[i+1]<l) continue;
                    int lef=cnt[i+1]-l,num=lef/3,rem=lef%3;
                    upd(dp[i+1][rem][j-l],dp[i][j][k]+l+num);
                    if(num>0) upd(dp[i+1][min(4,3+rem)][j-l],dp[i][j][k]+l+num-1);
                }
            }
    }
    int ans=0;
    for(int i=0;i<=4;i++)
        for(int j=0;j<=4;j++)
            ans=max(ans,dp[m][i][j]);
    printf("%d\n",ans);
    return 0;
}