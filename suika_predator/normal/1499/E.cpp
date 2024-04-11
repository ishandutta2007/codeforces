#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long dp[1111][1111][4];
long long ans;
char s[1111],t[1111];
int n,m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>(s+1)>>(t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=0;i<=n;i++)
	{
		for(int j=(i==0);j<=m;j++)
		{
			dp[i][j][0]=1;
			if(i>1&&s[i-1]!=s[i])dp[i][j][0]+=dp[i-1][j][0];
			dp[i][j][0]%=MOD;
			
			dp[i][j][1]=1;
			if(j>1&&t[j-1]!=t[j])dp[i][j][1]+=dp[i][j-1][1];
			dp[i][j][1]%=MOD;
			
			dp[i][j][2]=0;
			if(i>1&&s[i-1]!=s[i])dp[i][j][2]+=dp[i-1][j][2];
			if(i>0&&j>0&&t[j]!=s[i])dp[i][j][2]+=dp[i-1][j][1]+dp[i-1][j][3];
			dp[i][j][2]%=MOD;
			
			dp[i][j][3]=0;
			if(j>1&&t[j-1]!=t[j])dp[i][j][3]+=dp[i][j-1][3];
			if(j>0&&i>0&&s[i]!=t[j])dp[i][j][3]+=dp[i][j-1][0]+dp[i][j-1][2];
			dp[i][j][3]%=MOD;
			
//			cerr<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<' '<<dp[i][j][2]<<' '<<dp[i][j][3]<<endl;
			if(i>0&&j>0)ans+=dp[i][j][2]+dp[i][j][3];
		}
	}
	cout<<ans%MOD<<endl;
	return 0;
}