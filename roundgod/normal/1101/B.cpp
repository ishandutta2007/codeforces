#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN];
int dp[MAXN][5];
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(dp[i][j]==-1) continue;
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j==0&&str[i+1]=='[') dp[i+1][1]=max(dp[i+1][1],1);
            if(j==1&&str[i+1]==':') dp[i+1][2]=max(dp[i+1][2],2);
            if(j==2&&str[i+1]=='|') dp[i+1][2]=max(dp[i+1][2],dp[i][2]+1);
            if(j==2&&str[i+1]==':') dp[i+1][3]=max(dp[i+1][3],dp[i][2]+1);
            if(j==3&&str[i+1]==']') dp[i+1][4]=max(dp[i+1][4],dp[i][3]+1);
        }
    }
    printf("%d\n",dp[n][4]);
    return 0;
}