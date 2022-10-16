// Problem: B. Saving the City
// Contest: Codeforces - Codeforces Round #681 (Div. 2, based on VK Cup 2019-2020 - Final)
// URL: https://codeforces.com/contest/1443/problem/B
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
char a[200005];
int f[200005],pre[200005];
signed main()
{
	int T=read();
	while(T--)
	{
		int c=read(),b=read();
		scanf("%s",a+1);
		int n=strlen(a+1);
		int cur=0;
		for(int i=1;i<=n;i++)
		{
			a[i]&=1;
			pre[i]=cur;
			if(a[i])cur=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i])
			{
				if(a[i-1])f[i]=f[i-1];
				else f[i]=min(c,b*(i-pre[i]-1))+f[pre[i]];
				if(pre[i]==0)f[i]=c;
			}
			else f[i]=f[i-1];
		}
		oldl(f[n]);
	}
	return 0;
}