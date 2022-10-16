// Problem: CF62E World Evil
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF62E
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//lost in rain
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <bitset>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
#define odp(x,y) printf("%d %d\n",x,y)
#define ol(x) puts("")
#define old(x) printf("%lld",x)
#define oldb(x) printf("%lld ",x)
#define oldl(x) printf("%lld\n",x)
#define oldp(x,y) printf("%lld %lld\n",x,y)
#define rg(x) for(int i=1;i<=(x);i++){
#define rj(j,y,x) for(int j=(y);j<=(x);j++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
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
int r[5][100005],c[5][100005],dp[32];
signed main()
{
	int n=read(),m=read();
	rg(m-1)rj(j,1,n)r[j-1][i]=read();gr gr
	rg(m)rj(j,1,n)c[j-1][i]=read();gr gr
	memset(dp,0x3f,sizeof(dp));dp[0]=0;
	rg(m-1)rj(j,0,(1<<n)-1)rj(k,0,n-1)
	dp[j^(1<<k)]=min(dp[j^(1<<k)],dp[j]+r[k][i]);gr gr
	rj(j,0,(1<<n)-1)rj(k,0,n-1)if(((j>>k)&1)^((j>>((k+1)%n))&1))dp[j]+=c[k][i+1];
	gr gr gr oldl(dp[(1<<n)-1]);
	return 0;
}