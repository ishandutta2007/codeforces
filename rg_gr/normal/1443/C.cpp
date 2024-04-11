// Problem: C. The Delivery Dilemma
// Contest: Codeforces - Codeforces Round #681 (Div. 2, based on VK Cup 2019-2020 - Final)
// URL: https://codeforces.com/contest/1443/problem/C
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
int a[200005],b[200005];
inline int check(int t,int n)
{
	int res=0;
	for(int i=0;i<n;i++)if(a[i]>t)res+=b[i];
	return res<=t;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=0;i<n;i++)a[i]=read();
		for(int i=0;i<n;i++)b[i]=read();
		int l=0,r=1000000000ll*n,ans;
		while(l<=r)
		{
			int m=l+r>>1;
			if(check(m,n))r=m-1,ans=m;
			else l=m+1;
		}
		oldl(ans);
	}
	return 0;
}