// Problem: C. The Sports Festival
// Contest: Codeforces - Codeforces Round #715 (Div. 2)
// URL: https://codeforces.com/contest/1509/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int re1d()
{
	char c=getchar();
	while(c<48||c>49)c=getchar();
	return c&1;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int a[2005],dp[2005][2005][2];
signed main()
{
	int n=read();
	if(n==1)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<n;i++)a[1+i]=read();
	std::sort(a+1,a+n+1);
	int ans=0x3f3f3f3f3f3f3f3fll;
	memset(dp,0x2f,sizeof(dp));
	for(int i=1;i<=n;i++)dp[i][1][0]=dp[i][1][1]=0;
	const int inf=0x3f3f3f3f3f3f3f3fll;
	for(int l=2;l<=n;l++)
	{
//		for(int i=1;i<=n;i++)dp[i][l]=min(i-l>0?(dp[i-l][l-1]+a[i]-a[i-l]):inf,(dp[i+1][l-1]+a[l]-a[i]));
		for(int i=1;i<=n-l+1;i++)dp[i][l][0]=min(dp[i+1][l-1][0],dp[i+l-1][l-1][1])+a[i+l-1]-a[i];
		for(int i=l;i<=n;i++)dp[i][l][1]=min(dp[i-1][l-1][1],dp[i-l+1][l-1][0])+a[i]-a[i-l+1];
	}
	/*for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		//if(dp[i][j][0]>1e18)dp[i][j][0]=-1;
		//if(dp[i][j][1]>1e18)dp[i][j][1]=-1;
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			printf("(%lld %lld) ",dp[
			j][i][0],dp[j][i][1]);
	
	
	for(int i=0;i<n;i++)
	{
		int l=i,r=i,res=0;
		for(int j=1;j<n;j++)
		{
			int qwq=0x3f3f3f3f3f3f3f3fll;
			if(l>0)qwq=min(qwq,a[r]-a[l-1]);
			if(r<n-1)qwq=min(qwq,a[r+1]-a[l]);
			if(l>0&&qwq==a[r]-a[l-1])l--;
			else r++;
			res+=qwq;
		}
		ans=min(ans,res);
	}*/
	printf("%lld\n",min(dp[1][n][0],dp[n][n][1]));
}