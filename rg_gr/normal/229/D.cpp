// Problem: CF229D Towers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF229D
// Memory Limit: 250 MB
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
//#define int long long
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
int dp[5005],a[5005],f[5005];
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++)a[i]=a[i-1]+read();
	memset(dp,0x3f,sizeof(dp));dp[0]=0;
	memset(f,0x3f,sizeof(f));f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			if(a[i]>=f[j]+a[j]&&dp[i]-i+1>=dp[j]-j)f[i]=min(f[i],a[i]-a[j]),dp[i]=dp[j]+i-1-j;
			odl(dp[n]);
	return 0;
}