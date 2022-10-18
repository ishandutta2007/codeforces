#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[111111][18];
int b[111111];
int dp[111111];
main()
{
	int n,c ;
	scanf("%lld %lld",&n,&c);
	if (c==1)
	{
		printf("0\n");
		return 0;
	}
	int sum = 0;
	for(int i = 0;i<n;i++)
	{
		scanf("%lld",&a[i][0]);
		sum += a[i][0];
	}
	int d = 1;
	while (0==0)
	{
		if ((1<<d)>n) break;
		for(int i = 0;i+(1<<d)<=n;i++)
		{
			a[i][d]=min (a[i][d-1],a[i+(1<<(d-1))][d-1]);
		}
		d++;
	}
	int z = (int)log2(c);
	for(int i = 0;i<=n-c;i++)
	{
		b[i]=min(a[i][z],a[i+c-(1<<z)][z]);
	}
	dp[0] = b[0];
	int mx = 0;
	int ans = 0;
	for (int i = 0;i<n;i++)
	{
		if (i>=c) mx = max(mx,dp[i-c]);
		dp[i]=mx + b[i]; 
		ans = max(ans,dp[i]);
	}
	printf("%lld\n",sum-ans);
	return 0;
}