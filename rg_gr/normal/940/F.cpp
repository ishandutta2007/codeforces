// Problem: CF940F Machine Learning
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF940F
// Memory Limit: 500 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
#define register
//char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int num = 0,f=1; char c = getchar();
	while (c<48 || c>57)f=(c=='-'?-1:f),c = getchar();
	while (c >= 48 && c <= 57)num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
	return num*f;
};
inline int re1d()
{
	char c=getchar();
	while(c!='R'&&c!='Q')c=getchar();
	return c=='Q';
}
int ans; 
const int B=2300;
int a[1000005];gp_hash_table<int,int> b;int c[1000005];
struct qaq{
	int l,r,t,i,lB,rB;
	bool operator<(const qaq& b)const
	{
//		return (lB==b.lB)?(((lB)&1)?r<b.r:r>b.r):l<b.l;
		if(lB!=b.lB)return lB<b.lB;
		if(rB!=b.rB)return rB<b.rB;
		return t<b.t;
	}
}q[1000005];
/*
inline void add(int k)
{
	(b[a[k]]++)?0:ans++;
}
inline void rmv(int k)
{
	(--b[a[k]])?0:ans--;
}*/
inline void swap(int &a,int &b)
{
	a^=b^=a^=b;
}
int d[200005];
inline void rmv(int x)
{
	d[b[a[x]]--]--;
	d[b[a[x]]]++;
}
inline void add(int x)
{
	d[b[a[x]]++]--;
	d[b[a[x]]]++;
}
inline int __builtin_mexcount()
{
	int q=1;
	while(d[q])q++;
	return q;
}
int upd[200005],val[200005],e[200005];
signed main()
{
	int n=read(); 
	int m=read();
	for(int i=1;i<=n;i++)a[i]=e[i]=read();
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==1)q[i].l=read(),q[i].lB=q[i].l/B,q[i].r=read(),q[i].i=i,q[i].t=i,q[i].rB=q[i].r/B;
		else upd[i]=read(),val[i]=read(),q[i].i=i,q[i].lB=q[i].rB=q[i].t=q[i].l=q[i].r=0;
	}
	std::sort(q+1,q+1+m);
	int cl=1,cr=0,ct=0;
	for(int i=1;i<=m;i++)
	{
		int &L=q[i].l,&R=q[i].r,&t=q[i].t;
		if(L==0||R==0)
		{
			c[q[i].i]=1919810;
			continue;
		}
		while(cl>L)add(--cl);
		while(cr<R)add(++cr);
		while(cl<L)rmv(cl++);
		while(cr>R)rmv(cr--);
		while(ct>t)
		{
			if(upd[ct]<cl||upd[ct]>cr)
			{
				//a[upd[ct]]=e[upd[ct]];
				swap(a[upd[ct]],val[ct]);
				ct--;
				continue;
			}
			rmv(upd[ct]);
			swap(a[upd[ct]],val[ct]);
			add(upd[ct]);
			ct--;
		}
		while(ct<t)
		{
			ct++;
			if(upd[ct]<cl||upd[ct]>cr)
			{
				swap(a[upd[ct]],val[ct]);
				continue;
			}
			rmv(upd[ct]);
			swap(a[upd[ct]],val[ct]);
			add(upd[ct]);
		}
		c[q[i].i]=__builtin_mexcount();
	}
	for(int i=1;i<=m;i++)if(c[i]!=1919810)printf("%d\n",c[i]);
}