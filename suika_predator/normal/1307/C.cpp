#include<bits/stdc++.h>
using namespace std;
char s[111111];
int sum[111111][33];
long long cnt2[33][33],cnt[33];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<26;j++)
		{
			sum[i][j]=sum[i+1][j];
		}
		sum[i][s[i]-'a']++;
	}
	for(int i=1;i<=n;i++)
	{
		cnt[s[i]-'a']++;
		for(int j=0;j<26;j++)
			cnt2[s[i]-'a'][j]+=sum[i+1][j];
	}
	long long ans=0;
	for(int i=0;i<26;i++)
	{
		ans=max(ans,cnt[i]);
		for(int j=0;j<26;j++)
		{
			ans=max(ans,cnt2[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}