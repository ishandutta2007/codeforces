// Problem: D. Binary Literature
// Contest: Codeforces - Codeforces Round #715 (Div. 2)
// URL: https://codeforces.com/contest/1509/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
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
int a[200005],b[200005],c[200005];
int res[300005],ans[300005],p[300005];
void solve(int* a,int* b,int n,int d)
{
	int A=0;
	for(int i=0;i<n+n;i++)if(a[i]==d)p[A++]=1;else res[A]++;
	int q=A;
	A=0;
	for(int i=0;i<n+n;i++)if(b[i]==d)p[A++]=1;else res[A]++;
	for(int i=0;;i++)
	{
		for(int j=0;j<res[i];j++)putchar(49^d);
		if(p[i])putchar(48^d);
		else break;
	}
	puts("");
}
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read(),A=0,B=0,C=0;
		for(int i=0;i<n+n;i++)A+=a[i]=re1d();
		for(int i=0;i<n+n;i++)B+=b[i]=re1d();
		for(int i=0;i<n+n;i++)C+=c[i]=re1d();
		memset(res,0,sizeof(int)*(n+n+3));
		memset(p,0,sizeof(int)*(n+n+3));
		bool x=(A>=n),y=(B>=n),z=(C>=n);
		if(x&&y)solve(a,b,n,1);
		else if(y&&z)solve(b,c,n,1);
		else if(x&&z)solve(a,c,n,1);
		else if(x)solve(b,c,n,0);
		else if(y)solve(a,c,n,0);
		else solve(a,b,n,0);
	}
}