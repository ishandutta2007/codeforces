// Problem: CF915E Physical Education Lessons
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF915E
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#define CP_EDITOR
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#define int long long
#define odl(x) printf("%lld\n",x)
#define odb(x) printf("%lld ",x)
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
int LL=1,RR=1000000001ll;
#define Mod int
int L,R,v;
class seg{
	public:
	Mod sum[131072<<1|1];
	int tag[131072<<1|1];
	int charm[131072<<1|1];
	seg()
	{
		memset(sum,0,sizeof(sum));
		memset(tag,0,sizeof(sum));
		memset(charm,0,sizeof(sum));
	}
inline void pushdown(int o,int l,int r)
{
	if(l==r)
	{
		sum[o]=sum[o]*tag[o]+charm[o];
		tag[o]=1,charm[o]=0;
		return;
	}
	int lc=o<<1,rc=lc^1;
	tag[lc]*=tag[o],charm[lc]*=tag[o],charm[lc]+=charm[o];
	tag[rc]*=tag[o],charm[rc]*=tag[o],charm[rc]+=charm[o];
	tag[o]=1,charm[o]=0;
	//maintain(lc,l,l+r>>1);
	//maintain(rc,(l+r>>1)+1,r);
	//maintain(o,l,r);
}
int n;
inline void maintain(int o,int l,int r)
{
	if(l==r)
	{
		sum[o]=sum[o]*tag[o]+charm[o];
		charm[o]=0,tag[o]=1;
		return;
	}
	sum[o]=(sum[o<<1]+sum[o<<1|1])*tag[o]+charm[o]*(r-l+1);
	//pushdown(o,l,r);
}
void mul(int o,int l,int r,int L,int R,Mod x)
{
	if(L<=l&&r<=R)
	{
		tag[o]*=x;
		charm[o]*=x;
		maintain(o,l,r);
		return;
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	if(L<=m)mul(o<<1,l,m,L,R,x);else maintain(o<<1,l,m);
	if(m<R)mul(o<<1|1,m+1,r,L,R,x);else maintain(o<<1|1,m+1,r);
	maintain(o,l,r);
}
Mod query(int o,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
	{
		maintain(o,l,r);
		return sum[o];
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	Mod ans=0;
	if(L<=m)ans+=query(o<<1,l,m,L,R);else maintain(o<<1,l,m);
	if(m<R)ans+=query(o<<1|1,m+1,r,L,R);else maintain(o<<1|1,m+1,r);
	maintain(o,l,r);
	return ans;
}
void add(int o,int l,int r,int L,int R,int x)
{
	if(L<=l&&r<=R)
	{
		charm[o]+=x;
		maintain(o,l,r);
		return;
	}
	pushdown(o,l,r);
	int m=l+r>>1;
	if(L<=m)add(o<<1,l,m,L,R,x);else maintain(o<<1,l,m);
	if(m<R)add(o<<1|1,m+1,r,L,R,x);else maintain(o<<1|1,m+1,r);
	maintain(o,l,r);
}
}t[21];
signed main()
{
	int n=read();
	for(int i=0;i<=20;i++)t[i].mul(1,1,131072,1,131072,0);
	for(int i=1;i<=n;i++)
	{
		int u=read(),p=0;
		while(u)
		{
			if(u&1)t[p].add(1,1,131072,i,i,1);
			u>>=1;
			p++;
		}
	}
	int m=read();
	while(m--)
	{
		int op=read(),l=read(),r=read();
		if(op==2)
		{
			int v=read(),p=0;
			while(v)
			{
				if(v&1)t[p].mul(1,1,131072,l,r,-1),t[p].add(1,1,131072,l,r,1);
				v>>=1,p++;
			}
		}
		else
		{
			int sum=0;
			for(int i=0;i<20;i++)sum+=t[i].query(1,1,131072,l,r)<<i;
			odl(sum);
		}
	}
}