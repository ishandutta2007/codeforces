#include<bits/stdc++.h>
using namespace std;
string s;
long long dp[111][111],gg[2][111][111];
int a[111];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)dp[i][i]=a[1];
	for(int len=2;len<=n;len++)
	{
		for(int l=0;l+len-1<n;l++)
		{
			int r=l+len-1;
			//l~r
			gg[0][0][0]=gg[1][0][0]=0;
			for(int t=1;t<=len;t++)gg[0][0][t]=gg[1][0][t]=-0x3f3f3f3f3f3f3f3fll;
			for(int i=1;i<=len;i++)
			{
				for(int t=1;t<=i;t++)
				{
					//pos: l+i-1
					gg[0][i][t]=gg[1][i][t]=-0x3f3f3f3f3f3f3f3fll;
					for(int j=0;j<i;j++)
					{
						if(s[l+i-1]=='0' and (j==0 or s[l+j-1]=='0') and j>=t-1)
						{
							gg[0][i][t]=max(gg[0][i][t],gg[0][j][t-1]+dp[l+j+1-1][l+i-1-1]);
						}
						if(s[l+i-1]=='1' and (j==0 or s[l+j-1]=='1') and j>=t-1)
						{
							gg[1][i][t]=max(gg[1][i][t],gg[1][j][t-1]+dp[l+j+1-1][l+i-1-1]);
						}
					}
				}
			}
			dp[l][r]=0;
			for(int i=1;i<=len;i++)
			{
				for(int t=1;t<=i;t++)
				{
//					if(gg[0][i][t]>=0)cerr<<l<<' '<<r<<' '<<"gg"<<' '<<0<<' '<<i<<' '<<t<<' '<<gg[0][i][t]<<endl;
//					if(gg[1][i][t]>=0)cerr<<l<<' '<<r<<' '<<"gg"<<' '<<1<<' '<<i<<' '<<t<<' '<<gg[1][i][t]<<endl;
					dp[l][r]=max(dp[l][r],gg[0][i][t]+a[t]+dp[l+i][r]);
					dp[l][r]=max(dp[l][r],gg[1][i][t]+a[t]+dp[l+i][r]);
				}
			}
//			cerr<<l<<' '<<r<<' '<<dp[l][r]<<endl;
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}