// Problem: E. Devu and Flowers
// Contest: Codeforces - Codeforces Round #258 (Div. 2)
// URL: https://codeforces.com/problemset/problem/451/E
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
#define rg(x) for(int i=0;i<(x);i++){
#define rg_(i,x) for(int i=0;i<(x);i++){
#define gr }
#define rrg(x) for(int i=0;i<(x);i++)
#define rdln(a) a[i]=read();
#define rdln0(a,x) rrg(x) rdln(a) gr
#define rdln1(a,x) rg(x) rdln(a) gr
#define int long long
#define newe(n) struct Edge{int v,w,nxt;}e[n*2+5];\
typedef int arr[n+5];\
arr h;\
int cnt=1;\
inline void addedge(int u,int v,int w){e[cnt]=(Edge){v,w,h[u]};h[u]=cnt++;}

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
int a[20],b[20];
const int mod=1000000007;
inline int inv(int x)
{
	int ans=1,p=mod-2;
	while(p)
	{
		if(p&1)ans=ans*x%mod;
		x=x*x%mod;
		p>>=1;
	}
//	e r e r e e e e e e e r e e r e e e r e r e e r e e r e r e e e r e r e r e e r e r 
//	e r e r e r r e r e r e r r r e r e r r e r r e r e r r r e r r e r r r r r r r e r e r
	return ans;
}
inline int C(int n,int m)
{
	if(m>n)return 0;
	if(m==n||m==0)return 1;
	int ans=1;
	for(int i=n-m+1;i<=n;i++)(ans*=i%mod)%=mod;
	rg(m)(ans*=inv(i+1))%=mod;gr
	return ans;
}
signed main()
{
	int n=read(),m=read();
	rg(n)a[i]=read();gr
	int ans=0;
	rg(1<<n)int k=0,qwq=0;
	rg_(j,n)if((i>>j)&1)k++,qwq+=a[j];gr
	ans+=((k&1)?-1:1)*C(n+m-1-qwq-k,n-1);
	((ans%=mod)+=mod)%=mod;
	gr
	oldl(ans);
	return 0;
}