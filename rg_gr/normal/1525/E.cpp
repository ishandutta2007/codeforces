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
const int mod=998244353;
inline int qp(int x,int p)
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
int a[50005][25];
signed main()
{
	int n=read(),m=read(),f=1,ans=0;
	for(int i=0;i<n;i++,f*=i,f%=mod)for(int j=0;j<m;j++)a[j][read()]++;
	f=qp(f,mod-2);
	for(int i=0;i<m;i++)
	{
		int s=0,qwq=1;
		for(int j=n;j;j--)s+=a[i][j+1],qwq*=s,qwq%=mod,s--;
		ans-=qwq*f%mod-mod-1,ans%=mod;
	}
	oldl(ans);
	return 0;
}