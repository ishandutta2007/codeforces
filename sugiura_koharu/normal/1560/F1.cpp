#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[12],dp[12][2];
const int inf=2e9;
signed main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int k;
		string s;
		cin >> s >> k;
		s=' '+s;
		for(int i=0;i<=9;i++) a[i]=0;
		for(int i=0;i<k;i++) a[i]=1;
		reverse(a,a+10);
		int ans=inf;
		do
		{
			for(int i=0;i<=s.size();i++) dp[i][0]=dp[i][1]=inf;
			dp[0][1]=0;
			for(int i=1;i<s.size();i++)
			{
				for(int j=0;j<=9;j++)
				{
					if(!a[j]) continue;
					if(dp[i-1][0]!=inf) dp[i][0]=min(dp[i][0],dp[i-1][0]*10+j);
					if(j+'0'==s[i])
						if(dp[i-1][1]!=inf) dp[i][1]=min(dp[i][1],dp[i-1][1]*10+j);
					if(j+'0'>s[i])
						if(dp[i-1][1]!=inf) dp[i][0]=min(dp[i][0],dp[i-1][1]*10+j);
				}
			}
			ans=min(ans,min(dp[s.size()-1][0],dp[s.size()-1][1]));
		}while(next_permutation(a,a+10));
		cout << ans << "\n";
	}
	return 0;
}