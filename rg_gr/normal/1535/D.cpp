// Problem: D. Playoff Tournament
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/D
// Memory Limit: 256 MB
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
	while(c!='0'&&c!='1'&&c!='?')c=getchar();
	return c;
}
inline int min(int a,int b){return a>b?b:a;}
inline int max(int a,int b){return a<b?b:a;}
int t[1<<20],f[1<<20],id[1<<20];
void addd(int o)
{
	while(o)
	{
		if(f[o]=='1')t[o]=t[o<<1|1];
		else if(f[o]=='0')t[o]=t[o<<1];
		else t[o]=t[o<<1]+t[o<<1|1];
		o>>=1;
	}
}

signed main()
{
	int q;
	int k=read()-1;
	q=1<<k+1;
	int y=k;
	int cur=1<<k;
	int p=0;
	while(1)
	{
		id[++p]=cur;
		f[cur]=re1d();
		if(cur==1)break;
		cur++;
		if(cur&(cur-1))continue;
		else k--,cur=1<<k;
	}
	for(int i=1;i<q+q;i++)t[i]=1;
	for(int i=1;i<q;i++)addd(i);
	int m=read();
	while(m--)
	{
		int x=read(),p=re1d();
		f[id[x]]=p;
		addd(id[x]);
		odl(t[1]);
//		for(int i=1;i<=15;i++)odb(t[i]);
	}
	return 0;
}