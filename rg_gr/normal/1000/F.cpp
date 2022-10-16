#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <bits/extc++.h>
#include <set>
//__gnu_pbds::gp_hash_table<int,int> awa;
std::set<int> awa;
inline int read()
{
	int num = 0,f=1; char c = getchar();
	while (c<48 || c>57)f=(c=='-'?-1:f),c = getchar();
	while (c >= 48 && c <= 57)num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
	return num*f;
};
int ans; 
const int B=1700;
int a[1000005],b[1000005],c[1000005],pos[1000005],s[1000005],cc;
struct qaq{
	int l,r,i,lB;
	bool operator<(const qaq& b)const
	{
		return (lB==b.lB)?(((lB)&1)?r<b.r:r>b.r):l<b.l;
	}
}q[1000005];
inline void insert(int x)
{
	pos[x]=cc;
	s[cc++]=x;
}
inline void erase(int x)
{
	s[pos[x]]=s[--cc];
	pos[s[pos[x]]]=pos[x];
	pos[x]=0;
}
inline void rmv(int k)
{
	if(b[a[k]]==1)erase(a[k]);
	b[a[k]]--;
	if(b[a[k]]==1)insert(a[k]);
}
inline void add(int k)
{
	if(b[a[k]]==1)erase(a[k]);
	b[a[k]]++;
	if(b[a[k]]==1)insert(a[k]);
}
signed main()
{
	int n=read();//awa.insert(0);
	for(int i=1;i<=n;i++)a[i]=read();
	int m=read();
	for(int i=1;i<=m;i++)q[i].l=read(),q[i].lB=q[i].l/B,q[i].r=read(),q[i].i=i;
	std::sort(q+1,q+1+m);
	register int cl=1,cr=0;
	for(register int i=1;i<=m;i++)
	{
		int &L=q[i].l,&R=q[i].r;
		while(cr<R)add(++cr);
		while(cl>L)add(--cl);
		while(cr>R)rmv(cr--);
		while(cl<L)rmv(cl++);
		if(cc)c[q[i].i]=s[cc-1];
	}
	for(int i=1;i<=m;i++)printf("%d\n",c[i]);
}