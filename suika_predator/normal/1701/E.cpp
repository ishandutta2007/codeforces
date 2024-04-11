#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		string s,t;
		cin>>s>>t;
		int j=0;
		for(int i=0;i<n;i++)
			if(j<m and s[i]==t[j])
				j++;
		if(j!=m)
		{
			cout<<-1<<endl;
			continue;
		}
		int tmp=0;
		for(int i=0;i<m;i++)
		{
			if(s[i]==t[i])
				tmp++;
			else
				break;
		}
		int ans=m-tmp+n-m;
//		cerr<<"ans0 "<<ans<<endl;
		vector<vector<int>> dp(n+5,vector<int>(m+5,-1e9));
		dp[0][0]=0;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(i and j and s[i-1]==t[j-1])
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
				if(i and dp[i-1][j]>=0)
					dp[i][j]=max(dp[i][j],0);
				ans=min(ans,i-dp[i][j]+1+m-j+n-m);//[]i-dp[i][j]()i[]
//				cerr<<i<<' '<<j<<' '<<dp[i][j]<<' '<<i-dp[i][j]+1+m-j+n-m<<endl;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}