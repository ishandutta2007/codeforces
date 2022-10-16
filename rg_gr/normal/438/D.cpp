#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%lld\n",x)
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
int a[1000005],m[1000005],s[1000005];
void E(int o,int l,int r,int L,int R,int p)
{
	if(m[o]<p)return;
	if(l==r)
	{
		s[o]=m[o]=s[o]%p;
		return;
	}
	int mm=l+r>>1;
	if(L<=mm)E(o<<1,l,mm,L,R,p);
	if(mm<R)E(o<<1|1,mm+1,r,L,R,p);
	m[o]=max(m[o<<1],m[o<<1|1]);
	s[o]=s[o<<1]+s[o<<1|1];
}
void S(int o,int l,int r,int p,int v)
{
//	if(m[o]==2||m[o]==1)return;
//	if(m[o]<p)return;
	if(l==r)
	{
		s[o]=m[o]=v;
		return;
	}
	int mm=l+r>>1;
	if(p<=mm)S(o<<1,l,mm,p,v);
	else S(o<<1|1,mm+1,r,p,v);
	m[o]=max(m[o<<1],m[o<<1|1]);
	s[o]=s[o<<1]+s[o<<1|1];
}
int T(int o,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)return s[o];
	int m=l+r>>1,q=0;
	if(L<=m)q+=T(o<<1,l,m,L,R);
	if(m<R)q+=T(o<<1|1,m+1,r,L,R);
	return q;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++)S(1,1,n,i,read());
	while(m--)
	{
		int op=read(),l=read(),r=read();
		if(op==1)odl(T(1,1,n,l,r));
		else if(op==2)E(1,1,n,l,r,read());
		else S(1,1,n,l,r);
	}
	return 0;
}