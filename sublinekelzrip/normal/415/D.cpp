#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int dp[2010][2010];
int mod=1000000007;
int main()
{
	int n,m,n1,m1,m2;
	cin>>m>>n;
	for(m1=1;m1<=m;m1++)
		dp[1][m1]=1;
	for(n1=2;n1<=n;n1++)
		for(m1=1;m1<=m;m1++)
			for(m2=1;m2*m2<=m1;m2++)
				if(m1%m2==0)
				{
					dp[n1][m1]=(dp[n1-1][m2]+dp[n1][m1])%mod;
					if(m2*m2!=m1)
						dp[n1][m1]=(dp[n1-1][m1/m2]+dp[n1][m1])%mod;
				}
	int ans=0;
	for(m1=1;m1<=m;m1++)
		ans=(ans+dp[n][m1])%mod;
	cout<<ans;
}