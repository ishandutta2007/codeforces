// Problem: C. Alarm Clocks Everywhere
// Contest: Codeforces - Educational Codeforces Round 63 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1155/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
signed main()
{
	int n=read(),m=read();
	int	x=read(),q=x,g=0,y;
	for(int i=1;i<n;i++)y=read(),g=gcd(g,y-q),q=y;
	for(int i=1;i<=m;i++)
	{
		int qwq=read();
		if(g%qwq==0){printf("YES\n%lld %lld\n",x,i);return 0;}
	}
	puts("NO");
}