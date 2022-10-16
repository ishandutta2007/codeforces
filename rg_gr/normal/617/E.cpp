#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#define int long long
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int num = 0,f=1; char c = getchar();
	while (c<48 || c>57)f=(c=='-'?-1:f),c = getchar();
	while (c >= 48 && c <= 57)num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
	return num*f;
};
inline int re1c()
{
	int c=getchar();
	while(c<'a'||c>'z')c=getchar();
	return c-97;
}
int ans; 
const int B=300;
int a[100005],b[2000005],c[100005];
struct qaq{
	int l,r,i,lB;
	bool operator<(const qaq& b)const
	{
		return (lB==b.lB)?(((lB)&1)?r<b.r:r>b.r):l<b.l;
	}
}q[100005];
int k;
inline void add(int x)
{
	ans+=b[a[x]^k];
	b[a[x]]++;
}
inline void rmv(int x)
{
	--b[a[x]];
	ans-=b[a[x]^k];
}
signed main()
{
	int n=read();
	int m=read();
	k=read();
	for(int i=1;i<=n;i++)a[i]=read(),a[i]^=a[i-1];
	for(int i=1;i<=m;i++)q[i].l=read()-1,q[i].lB=q[i].l/B,q[i].r=read(),q[i].i=i;
	std::sort(q+1,q+1+m);
	register int cl=1,cr=0;
	for(register int i=1;i<=m;i++)
	{
		int &L=q[i].l,&R=q[i].r;
		while(cr<R)add(++cr);
		while(cl>L)add(--cl);
		while(cr>R)rmv(cr--);
		while(cl<L)rmv(cl++);
		c[q[i].i]=ans;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",c[i]);
}