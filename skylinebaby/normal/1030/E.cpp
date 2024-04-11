#include<bits/stdc++.h>
using namespace std;
#define int long long
int need[312345];
int sum [312345];
int big [310000][20];
int popc(int x)
{
	int a = 0;
	while(x!=0)
	{
		if(x%2==1) a++;
		x = x/2;
	}
	return a;
}
main()
{
	int n;
	scanf("%lld",&n);
	int a = 0;
	int b = 1; 
	sum[0] = 0;
	for(int i = 1;i<=n;i++)
	{
		int x;
		scanf("%lld",&x);
		int y = popc(x);
		need[i] = y; 
		big[i][0] = y;
		sum [i] = sum[i-1] + y;
		if(sum[i]%2==1) a++;
		else b++;
	}
	int d=1;
	while(0==0)
	{
		if ((1<<d)>n) break; 
		for(int i=1;i-1+(1<<d)<=n;i++)
		{
			big[i][d]=max(big[i][d-1],big[i+(1<<(d-1))][d-1]);
		}
		d++;
	}
	/*
	for(int i = 1;i<=n;i++) printf("%lld ",need[i]);
	printf("\n");
	for(int j=0;j<10;j++)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",big[i][j]);
		}
		printf("\n");
	}*/
	int ans = a*(a-1)/2 + b*(b-1)/2;
	for(int i = 1;i<63;i++)
	{
		for(int j = 0;j<=n-i;j++)
		{
			int t = (int)log2(i+0.5);
			int q = max(big[j+1][t],big[j+i+1-(1<<t)][t]);
			//printf("%d %d %d\n",j+1,j+i,q);
			//printf("%d %d %d\n",j+1,j+i,t);
			if((sum[j+i]-sum[j])%2==0&&sum[j+i]-sum[j]<2*q) ans--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}