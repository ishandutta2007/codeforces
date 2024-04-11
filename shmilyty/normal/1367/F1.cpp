#include<bits/stdc++.h>
using namespace std;
int t,n,ans,dp[3001],a[3001],b[3001];
map<int,int> m;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		m.clear();
		ans=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			dp[i]=0;
			m[b[i]]=i;
		}
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i++)
			a[m[b[i]]]=i;
		for(int i=1;i<=n;i++)
		{
			dp[a[i]]=dp[a[i]-1]+1;
			ans=max(ans,dp[a[i]]);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}