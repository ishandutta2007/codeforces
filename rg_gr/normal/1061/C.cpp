// Problem: C. Multiplicity
// Contest: Codeforces - Codeforces Round #523 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1061/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int a[2000004],s[2000005],c,f[2000005];
const int mod=1000000007;
signed main()
{
	int n=read();f[0]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();c=0;
		for(int j=1;j*j<=a[i];j++)
		{
			if(a[i]%j)continue;
			s[c++]=j;
			if(j*j!=a[i])s[c++]=a[i]/j;
		}
		std::sort(s,s+c);
		for(int j=c-1;j>=0;j--)f[s[j]]+=f[s[j]-1],f[s[j]]%=mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=f[i],ans%=mod;
	odl(ans);
	return 0;
}