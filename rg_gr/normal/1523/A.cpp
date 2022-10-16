// Problem: A. Game of Life
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[10005],pre[10005],suf[10005];
signed main()
{
	int T=read();
	pre[0]=-2000000000;
	while(T--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=re1d();
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				pre[i]=i;
			}
			else pre[i]=pre[i-1];
		}
		suf[n+1]=2000000000;
		for(int i=n;i>=1;i--)
		{
			if(a[i])suf[i]=i;else suf[i]=suf[i+1];
		}
		for(int i=1;i<=n;i++)if(a[i])putchar(49);
		else
		{
			int x=i-pre[i],y=suf[i]-i;
			if(x==y)putchar(48);
			else if(x<=m||y<=m)putchar(49);
			else putchar(48);
		}
		puts("");
	}
	return 0;
}