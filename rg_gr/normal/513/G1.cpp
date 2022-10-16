// Problem: CF513G2 Inversions problem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF513G2
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#define rj(x,y) for(int j=(x);j<=(y);j++){
#define rn(a) for(int a=1;a<=(n);a++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
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
double dp[305][305][305];
int a[305];
signed main()
{
	int n=read(),k=read();
	rdln1(a,n);
	double qwq=2.0/(n+1)/n;
	rg(n)rj(1,n)dp[0][i][j]=(a[i]>a[j]);gr gr
	rg(k)rn(l)rn(r)rn(ll)for(int rr=ll;rr<=n;rr++)
	{int x,y;
	if(l<ll||l>rr)x=l;else x=ll+rr-l;
	if(r<ll||r>rr)y=r;else y=ll+rr-r;
	dp[i][l][r]+=qwq*dp[i-1][x][y];
	gr gr gr gr gr
	qwq=0;
	rg(n)rj(i,n)qwq+=dp[k][i][j];gr gr
	printf("%.10lf\n",qwq);
	return 0;
}