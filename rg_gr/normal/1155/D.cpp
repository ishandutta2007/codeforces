// Problem: D. Beautiful Array
// Contest: Codeforces - Educational Codeforces Round 63 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1155/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
inline int max(int a,int b,int c){return max(a,max(b,c));}
inline int max(int a,int b,int c,int d){return max(a,max(b,c,d));}
int a[300005],dp[300005][3];
signed main()
{
	int n=read(),x=read(),maxn=-1000000000000000000;
	for(int i=1;i<=n+1;i++)
	{
		if(i<=n)a[i]=read();
		dp[i][0]=max(dp[i-1][0],0)+a[i];
		dp[i][1]=max(dp[i-1][1],dp[i-1][0],0)+a[i]*x;
		dp[i][2]=max(dp[i-1][1],dp[i-1][2],dp[i-1][0],0)+a[i];
		maxn=max(dp[i][0],dp[i][1],dp[i][2],maxn);
	}
	printf("%lld\n",max(maxn,0));
}