#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> a(n+5);
		vector<int> pos(n+5);
		vector<vector<int>> loc(n+5);
		vector<vector<int>> dp(n+5,vector<int>(n+5));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		n=unique(a.begin()+1,a.begin()+n+1)-a.begin()-1;
		a.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			pos[i]=loc[a[i]].size();
			loc[a[i]].push_back(i);
		}
		for(int len=1;len<=n;len++)
		{
			for(int l=1;l+len-1<=n;l++)
			{
				int r=l+len-1;
				if(len==1)
				{
					dp[l][r]=0;
					continue;
				}
				dp[l][r]=min(dp[l][r-1],dp[l+1][r])+1;
				if(a[l]==a[r])
				{
					dp[l][r]=min(dp[l][r],dp[l+1][r-1]+1);
					int pl=pos[l],pr=pos[r],c=a[l];
					for(int i=pl+1;i<pr;i++)
					{
						dp[l][r]=min(dp[l][r],dp[l][loc[c][i]]+dp[loc[c][i]][r]);
					}
				}
				else
				{
					int pl=pos[l],pr=pos[r],cl=a[l],cr=a[r];
					for(int i=pl;i<(int)loc[cl].size() and loc[cl][i]<r;i++)
					{
						dp[l][r]=min(dp[l][r],dp[l][loc[cl][i]]+dp[loc[cl][i]+1][r]+1);
					}
					for(int i=pr;i>=0 and loc[cr][i]>l;i--)
					{
						dp[l][r]=min(dp[l][r],dp[l][loc[cr][i]-1]+dp[loc[cr][i]][r]+1);
					}
				}
			}
		}
		cout<<dp[1][n]<<endl;
	}
	
	return 0;
}