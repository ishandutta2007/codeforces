// Problem: D. Extreme Subtraction
// Contest: Codeforces - Codeforces Round #681 (Div. 2, based on VK Cup 2019-2020 - Final)
// URL: https://codeforces.com/contest/1443/problem/D
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
int a[30005];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();a[0]=0x3f3f3f3f;
		for(int i=1;i<=n;i++)a[i]=read();
		int pos=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[i-1])
			{
				pos=i-1;
				break;
			}
		}
		if(pos==0)
		{
			puts("YES");
			continue;
		}
		a[pos+1]-=a[pos];int lst=a[pos];
		for(int i=pos+2;i<=n;i++)
		{
//			if(a[i]>=a[pos]&&a[i]-lst>=a[i-1])lst=a[i]-a[i-1],a[i]=a[i-1];
//			else break;
			if(a[i]<a[i-1])goto ng;
			if(a[i]-lst>=a[i-1])a[i]-=lst;
			else lst=a[i]-a[i-1],i[a]=a[i-1];
		}
		for(int i=n;i>pos+1;i--)
		{
			if(a[i]<a[i-1])goto ng;
		}
		puts("YES");
		continue;
		ng:;
		puts("NO");
	}
	return 0;
}