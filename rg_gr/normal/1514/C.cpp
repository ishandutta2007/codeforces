// Problem: C. Product 1 Modulo N
// Contest: Codeforces - Codeforces Round #716 (Div. 2)
// URL: https://codeforces.com/contest/1514/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[300005],q=0;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
signed main()
{
	int n=read(),qwq=1;
	for(int i=1;i<=n;i++)if(gcd(i,n)==1)a[q++]=i,qwq=(long long)qwq*i%n;
	if(qwq!=1)q--;
	printf("%d\n",q);
	for(int i=0;i<q;i++)printf("%d ",a[i]);
}