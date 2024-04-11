// Problem: A. Stairs and Elevators
// Contest: Codeforces - Codeforces Round #477 (rated, Div. 1, based on VK Cup 2018 Round 3)
// URL: https://codeforces.com/contest/966/problem/A
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
int l[2000005],e[2000005];
inline int abs(int x)
{
	return x>0?x:-x;
}
signed main()
{
	int n=read(),m=read(),cl=read(),ce=read(),v=read();
	for(int i=1;i<=cl;i++)l[i]=read();for(int i=1;i<=ce;i++)e[i]=read();
	l[0]=e[0]=-1000000000000ll;
	l[++cl]=e[++ce]=-l[0];
	cl++,ce++;
	int mm=read();
	while(mm--)
	{
		int l1=read(),r1=read(),l2=read(),r2=read();
		// use stair
		int ans=1e18;
//		oldl(ans);
if(l1==l2)
{
	oldl(abs(r2-r1));
	continue;
}
		{
			int x=std::lower_bound(l,l+cl,r1)-l;
			int qwq=min(abs(r2-l[x])+abs(r1-l[x]),abs(r2-l[x-1])+abs(r1-l[x-1]))+abs(l2-l1);
			ans=min(ans,qwq);
		}
		{
			int x=std::lower_bound(e,e+ce,r1)-e;
			int qwq=min(abs(r2-e[x])+abs(r1-e[x]),abs(r2-e[x-1])+abs(r1-e[x-1]))+(abs(l2-l1)+v-1)/v;
			ans=min(ans,qwq);
		}
		{
			int x=std::lower_bound(l,l+cl,r2)-l;
			int qwq=min(abs(r2-l[x])+abs(r1-l[x]),abs(r2-l[x-1])+abs(r1-l[x-1]))+abs(l2-l1);
			ans=min(ans,qwq);
		}
		{
			int x=std::lower_bound(e,e+ce,r2)-e;
			int qwq=min(abs(r2-e[x])+abs(r1-e[x]),abs(r2-e[x-1])+abs(r1-e[x-1]))+(abs(l2-l1)+v-1)/v;
			ans=min(ans,qwq);
		}
		oldl(ans);
	}
	return 0;
}