#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <queue>
#include <set>
#define od(x) printf("%d",x)
#define odb(x) printf("%d ",x)
#define odl(x) printf("%d\n",x)
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
struct Node{
	int l,r;
	mutable int v;
	bool operator<(const Node& b)const
	{
		return l<b.l;
	}
	Node(int l,int r,int v):l(l),r(r),v(v){}
};
std::set<Node> s;
typedef std::set<Node>::iterator qwq;
inline qwq split(int x)
{
	qwq it=s.lower_bound(Node(x,0,0));
	if(it!=s.end()&&it->l==x)return it;
	it--;
	int l=it->l,r=it->r,v=it->v;
	s.erase(it);
	s.insert(Node(l,x-1,v));
	return s.insert(Node(x,r,v)).first;
}
inline void setval(int l,int r,int v)
{
	qwq it2=split(r+1);
	qwq it1=split(l),j;
	s.erase(it1,it2);
	s.insert(Node(l,r,v));
}
inline void add(int l,int r,int v)
{
	qwq it2=split(r+1),it1=split(l);
	for(;it1!=it2;it1++)it1->v+=v;
}
struct hydrooj{
	int v,k;
	bool operator<(const hydrooj&b)const
	{
		return v<b.v;
	}
}st[200005];
int c;
inline int kth(int l,int r,int k)
{
	c=0;
	qwq R=split(r+1),L=split(l);
	for(;L!=R;L++)st[c++]=(hydrooj){L->v,L->r-L->l+1};
	std::sort(st,st+c);
	for(int i=0;i<c;i++)
	{
		if(k>st[i].k)k-=st[i].k;
		else return st[i].v;
	}
	return 114514;
}
inline long long qp(long long x,int p,int mod)
{
	long long res=1;
	x%=mod;
	while(p)
	{
		if(p&1)res=res*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return res;
}
inline long long sum(int l,int r,int k,int mod)
{
	qwq R=split(r+1),L=split(l);
	long long res=0;
	for(;L!=R;L++)
	{
		res+=qp(L->v,k,mod)*(L->r-L->l+1)%mod;
		res%=mod;
	}
	return res;
}
int ret,seed;
inline int rd()
{
	ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
}
signed main()
{
	int n=read(),m=read();seed=read();int V=read();
	for(int i=1;i<=n;i++)s.insert(Node(i,i,rd()%V+1));s.insert(Node(n+1,n+1,0));
	while(m--)
	{
		int op=rd()%4+1,l=rd()%n+1,r=rd()%n+1;
		if(l>r)l^=r^=l^=r;
		int x;
		if(op==3)x=rd()%(r-l+1)+1;
		else x=rd()%V+1;
		int y;
		if(op==4)y=rd()%V+1;
		if(op==1)add(l,r,x);
		else if(op==2)setval(l,r,x);
		else if(op==3)oldl(kth(l,r,x));
		else oldl(sum(l,r,x,y));
	}
	return 0;
}