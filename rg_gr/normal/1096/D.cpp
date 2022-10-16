// Problem: D. Easy Problem
// Contest: Codeforces - Educational Codeforces Round 57 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1096/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
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
inline int min(int a,int b,int c){return max(a,min(b,c));}
int a[300005],dp[300005][4];
char c[300005];
signed main()
{
	int n=read();
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)a[i]=read();//,dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=1e9;
	for(int i=1;i<=n;i++)
	{
		if(c[i]=='h')dp[i][0]=max(dp[i-1][0]+a[i],0);else dp[i][0]=dp[i-1][0];
		if(c[i]=='a')dp[i][1]=min(dp[i-1][1]+a[i],dp[i-1][0]);else dp[i][1]=dp[i-1][1];
		if(c[i]=='r')dp[i][2]=min(dp[i-1][2]+a[i],dp[i-1][1]);else dp[i][2]=dp[i-1][2];
		if(c[i]=='d')dp[i][3]=min(dp[i-1][3]+a[i],dp[i-1][2]);else dp[i][3]=dp[i-1][3];
		//odb(dp[i][0]),odb(dp[i][1]),odp(dp[i][2],dp[i][3]);
	}
	oldl(dp[n][3]);
	return 0;
}