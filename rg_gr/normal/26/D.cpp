// Problem: D. Tickets
// Contest: Codeforces - Codeforces Beta Round #26 (Codeforces format)
// URL: https://codeforces.com/contest/26/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
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
signed main()
{
	int n=read(),m=read(),k=read();
	double ans=1;
	if(m<=k)return puts("1");
	for(int i=0;i<=k;i++)ans=ans*(m+i-k)/(n+i+1);
	printf("%.8lf\n",ans>1?0:1-ans);
}