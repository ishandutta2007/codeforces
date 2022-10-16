// Problem: CF877F Ann and Books
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF877F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
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
struct Queries{
	int l,r,lb,rb,i;
	bool operator<(const Queries &b)const
	{
		return lb==b.lb?r<b.r:lb<b.lb;
	}
}q[200005];
int a[200005],c[200005],cmll02[200005];
//std::unordered_map<int,int> L,R,tL,tR;
gp_hash_table<int,int> t;
const int B=450;
int ans=0;
#define printf
#define puts
signed main()
{
	int n=read(),k=read();//,m=read();
	for(int i=1;i<=n;i++)a[i]=-2*read()+3;
	for(int i=1;i<=n;i++)c[i]=c[i-1]+read()*a[i],printf("%d ",c[i]);puts("");
	int m=read();
	for(int i=1;i<=m;i++)q[i].i=i,q[i].l=read()-1,q[i].r=read(),q[i].lb=q[i].l/B,q[i].rb=q[i].r/B;
	std::sort(q+1,q+1+m);q[0].lb=-1;
	int cl=0,cr=-1;
	for(int i=1;i<=m;i++)
	{
		int l=q[i].l,r=q[i].r,lb=q[i].lb,rb=q[i].rb;
		printf("[%d %d] -> [%d %d]\n",cl,cr,l,r);
		while(cr<r)ans+=t[c[++cr]-k],++t[c[cr]];
//		for(int i=-0;i<=4;i++)printf("%d ",t[i]);puts("");
		while(cl>l)ans+=t[c[--cl]+k],++t[c[cl]];
//		for(int i=-0;i<=4;i++)printf("%d ",t[i]);puts("");
		while(cr>r)--t[c[cr]],ans-=t[c[cr--]-k];
//		for(int i=-0;i<=4;i++)printf("%d ",t[i]);puts("");
		while(cl<l)--t[c[cl]],ans-=t[c[cl++]+k];
//		for(int i=-0;i<=4;i++)printf("%d ",t[i]);puts("");
//		puts("wew");
//		for(int i=1;i<=n;i++)printf("%d ",c[i]);puts("\n");
		cmll02[q[i].i]=ans;
	}
#undef printf
	for(int i=1;i<=m;i++)printf("%lld\n",cmll02[i]);
}