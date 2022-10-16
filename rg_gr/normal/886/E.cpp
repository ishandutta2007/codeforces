// Problem: CF886E Maximum Element
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF886E
// Memory Limit: 250 MB
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
const int mod=1000000007;
inline int qp(int x,int p=mod-2)
{
	int res=1;
	while(p)
	{
		if(p&1)res=res*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return res;
}
int fac[1000005],inv[1000005],qwq[1000005];
inline int C(int n,int m)
{
	return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
signed main()
{
	int n=read(),m=read();fac[0]=inv[0]=1;
	int qaq=0;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	inv[n]=qp(fac[n]);
	for(int i=n-1;i>=1;i--)inv[i]=inv[i+1]*(i+1)%mod;
	int sum=1;qwq[0]=1;
	for(int i=1;i<=n;i++)
	{
		qwq[i]=sum*fac[i-1]%mod;
		if(i>=m)sum-=inv[i-m]*qwq[i-m]%mod-mod,sum%=mod;
		sum+=qwq[i]*inv[i],sum%=mod;
		qaq+=qwq[i-1]*C(n-1,n-i)%mod*fac[n-i]%mod,qaq%=mod;
	}
	oldl((mod+fac[n]-qaq)%mod);
	return 0;
}