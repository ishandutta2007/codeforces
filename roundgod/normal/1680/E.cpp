#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
string str[2];
int dp[MAXN][4];
int cnt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<2;i++) cin>>str[i];
        cnt[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            cnt[i]=(str[0][i]=='*')+(str[1][i]=='*')+cnt[i+1];
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int mask=0;mask<4;mask++)
            {
                dp[i][mask]=INF;
                int state=((str[0][i]=='*')*2+(str[1][i]=='*'))|mask;
                int num=__builtin_popcount(state);
                if(cnt[i+1]==0) dp[i][mask]=max(0,num-1);
                else
                {
                    dp[i][mask]=min(dp[i][mask],dp[i+1][state]+num);
                    if(num==2)
                    {
                        dp[i][mask]=min(dp[i][mask],dp[i+1][2]+2);
                        dp[i][mask]=min(dp[i][mask],dp[i+1][1]+2);
                    }
                    else if(num==1)
                    {
                        dp[i][mask]=min(dp[i][mask],dp[i+1][3^state]+2);
                        dp[i][mask]=min(dp[i][mask],dp[i+1][3^state]+2);
                    }
                }
            }
        }
        printf("%d\n",dp[0][0]);
    }
    return 0;
}