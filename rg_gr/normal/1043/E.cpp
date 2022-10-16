// Problem: E. Train Hard, Win Easy
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: http://codeforces.com/contest/1043/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
struct p{
	int a,b,c,i;
	bool operator<(const p&b)const
	{
		return c<b.c;
	}
}a[300005];
int prea[300005],sufa[300005],preb[300005],sufb[300005],qwq[300005],ans[300005];
signed main()
{
	int n=read();int m=read();
	for(int i=1;i<=n;i++)a[i].a=read(),a[i].b=read(),a[i].c=a[i].a-a[i].b,a[i].i=i;
	
	while(m--)
	{
		int u=read(),v=read();
		int res=min(a[u].a+a[v].b,a[u].b+a[v].a);
		qwq[u]-=res,qwq[v]-=res;
	}
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)prea[i]=prea[i-1]+a[i].a;
	for(int i=1;i<=n;i++)preb[i]=preb[i-1]+a[i].b;
	for(int i=n;i>=1;i--)sufa[i]=sufa[i+1]+a[i].a;
	for(int i=n;i>=1;i--)sufb[i]=sufb[i+1]+a[i].b;
	for(int i=1;i<=n;i++)
	{
		ans[a[i].i] = prea[i-1]+a[i].b*(i-1) + sufb[i+1] + a[i].a*(n-i) ;
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]+qwq[i]);
}