#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[12],dp[12][2],b[12];
const int inf=2e9;
signed main()
{
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while(T--)
	{
		int k;
		string s;
		cin >> s >> k;
		for(int i=0;i<s.size();i++) s[i]-='0';
		s=' '+s;
		for(int i=0;i<=9;i++) a[i]=0;
		for(int i=0;i<k;i++) a[i]=1;
		reverse(a,a+10);
		int ans=inf;
		do
		{
			for(int i=0;i<=s.size();i++) dp[i][0]=dp[i][1]=inf;
			dp[0][1]=0;
			int cnt=0;
			for(int i=0;i<=9;i++) if(a[i]) b[++cnt]=i; 
			for(int i=1;i<s.size();i++)
			{
				for(int j=1;j<=cnt;j++)
				{
					dp[i][0]=min(dp[i][0],dp[i-1][0]*10+b[j]);
					if(b[j]==s[i]) dp[i][1]=min(dp[i][1],dp[i-1][1]*10+b[j]);
					if(b[j]>s[i]) dp[i][0]=min(dp[i][0],dp[i-1][1]*10+b[j]);
				}
			}
			ans=min(ans,min(dp[s.size()-1][0],dp[s.size()-1][1]));
		}while(next_permutation(a,a+10));
		cout << ans << "\n";
	}
	return 0;
}