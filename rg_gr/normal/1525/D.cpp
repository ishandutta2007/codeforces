// Problem: D. Armchairs
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1525/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int a[5005],dp[5005][5005],qwq[5005];
inline int f(int x){return x>0?x:-x;}
signed main()
{
	int n=read(),c=0;
	for(int i=1;i<=n;i++)c+=a[i]=re1d(),a[i]?qwq[c-1]=i:0;
	for(int i=1;i<=c;i++)dp[i][0]=0x3f3f3f3f;
	for(int i=1;i<=c;i++)for(int j=1;j<=n;j++)dp[i][j]=dp[i][j-1],a[j]||(dp[i][j]=min(dp[i][j],dp[i-1][j-1]+f(j-qwq[i-1])));
	odl(dp[c][n]);
	return 0;
}
/*
0 0 1 1 0
*/