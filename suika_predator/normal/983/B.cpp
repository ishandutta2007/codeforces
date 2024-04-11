#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,q,a[5555];
int val[5555][5555],dp[5555][5555];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),dp[i][i]=val[i][i]=a[i];
	for(int d=1;d<n;d++)
	{
		for(int s=1;s+d<=n;s++)
		{
			val[s][s+d]=val[s][s+d-1]^val[s+1][s+d];
			dp[s][s+d]=max(dp[s][s+d-1],dp[s+1][s+d]);
			dp[s][s+d]=max(dp[s][s+d],val[s][s+d]);
		}
	}
	scanf("%d",&q);
	int l,r;
	while(q--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",dp[l][r]);
	}
	return 0;
}