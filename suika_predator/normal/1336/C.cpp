//xin tai beng le
#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,k;
char s[3333],t[3333];
int dp[3333][3333];
inline void add(int &x,int y){x+=y;x=(x>=MOD?x-MOD:x);}
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int j=1;j<=n;j++)dp[1][j]=(!t[j]||s[1]==t[j])*2;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n;j++)
		{
//			cerr<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			if(s[i+1]==t[j-1])add(dp[i+1][j-1],dp[i][j]);
			if(!t[j+i]||s[i+1]==t[j+i])add(dp[i+1][j],dp[i][j]);
		}
		add(dp[i+1][m+1],dp[i][m+1]);
	}
	long long ans=0;
	for(int i=m;i<=n;i++)
		ans+=dp[i][1];
	cout<<ans%MOD<<endl;
	return 0;
}