#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c[2],d[2],dp[1001],q[1001];
int main()
{
	scanf("%d %d %d %d",&m,&n,&c[0],&d[0]);
	for(int i=c[0];i<=m;i++)
		dp[i]=max(dp[i],dp[i-c[0]]+d[0]);
	while(n--)
	{
		scanf("%d %d %d %d",&a,&b,&c[1],&d[1]);
		a/=b;
		int tot=0;
		for(int i=1;i<=a;i*=2)
		{
			q[++tot]=i;
			a-=i;
		}
		if(a)
			q[++tot]=a;
		for(int l=1;l<=tot;l++)
			for(int j=m;j>=c[1]*q[l];j--)
				dp[j]=max(dp[j],dp[j-c[1]*q[l]]+d[1]*q[l]);
	}
	int ans=0;
	for(int i=0;i<=m;i++)
		ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}