// Problem: E. Long Permutation
// Contest: Codeforces - Codeforces Round #681 (Div. 2, based on VK Cup 2019-2020 - Final)
// URL: https://codeforces.com/contest/1443/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
int sum[200005],p[21];
int fac[21],vis[21];
namespace std{
inline void next_premutation(int k,int n,int pos=1)
{
	if(pos>n)return;
	int i;
	for(i=1;;i++)
	{
		while(vis[i])i++;
		if(k<fac[n-pos])break;
		k-=fac[n-pos];
	}
	//odb(i);
	p[pos]=i;
	vis[i]=1;
	next_premutation(k,n,pos+1);
}
};
signed main()
{
	int n=read(),m=read(),x=0;fac[0]=1;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+i;
	for(int i=1;i<=20;i++)p[i]=i,fac[i]=fac[i-1]*i;
	while(m--)
	{
		int op=read();
		if(op==1)
		{
			int l=read(),r=read();
			oldl(sum[r]-sum[l-1]);
		}
		else
		{
			x+=read();
			memset(vis,0,sizeof(vis));
			std::next_premutation(x,min(n,20));
			int base=max(0,n-20);
			for(int i=base+1;i<=n;i++)sum[i]=sum[i-1]+p[i-base]+base;
		}
		//for(int i=1;i<=min(n,20);i++)odb(p[i]);puts("");
	}
	return 0;
}