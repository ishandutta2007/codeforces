#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],dp[N],last[N];
int n,ans;
int gcd(int x,int y)
{
	if (y==0) return y;
	return(y,x%y);
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		int tmp=a[i];
		for (int j=2;j*j<=a[i];j++)
		{
			if (tmp%j==0)
			{
				dp[a[i]]=max(dp[a[i]],last[j]);
				while (tmp%j==0) tmp/=j;
			}
		}
		if (tmp>1) dp[a[i]]=max(dp[a[i]],last[tmp]);
		dp[a[i]]++;
		ans=max(ans,dp[a[i]]);
		tmp=a[i];
		for (int j=2;j*j<=a[i];j++)
		{
			if (tmp%j==0)
			{
				last[j]=dp[a[i]];
				while (tmp%j==0) tmp/=j;
			}
		}
		if (tmp>1) last[tmp]=dp[a[i]];
	}
	cout<<ans<<endl;
}