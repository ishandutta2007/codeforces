#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 32765
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
char s[MAXN],t[MAXN];
short dp[3][MAXN][MAXN];
void upd(short &x,short y) {x=min(x,y);}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",s+1); scanf("%s",t+1);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[0][i][j]=dp[1][i][j]=dp[2][i][j]=INF;
        dp[0][n][m]=dp[1][n][m]=dp[2][n][m]=0;
        for(int type=0;type<3;type++)
            for(int i=n;i>=1;i--)
                for(int j=m;j>=0;j--)
                {
                    if(dp[type][i][j]==INF) continue;
                    int cur=dp[type][i][j];
                    //match
                    if(j&&s[i]==t[j])
                    {
                        if(type==0)
                        {
                            upd(dp[0][i-1][j-1],cur+1);
                            upd(dp[1][i-1][j-1],cur);
                        }
                        else if(type==1)
                        {
                            upd(dp[1][i-1][j-1],cur);
                        }
                        else upd(dp[2][i-1][j-1],cur+1);
                    }
                    //not match
                    if(type==0)
                    {
                        upd(dp[0][i-1][j],cur+1);
                    }
                    else if(type==1)
                    {
                        upd(dp[2][i-1][j],cur+3);
                    }
                    else
                    {
                        upd(dp[2][i-1][j],cur+2);
                    }
                }
        int ans=min(min(dp[0][0][0],dp[1][0][0]),dp[2][0][0]);
        printf("%d\n",(ans==INF?-1:ans));
    }
    return 0;
}