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
qwq split(int x)
{
	qwq it=s.lower_bound(Node(x,0,0));
	if(it!=s.end()&&it->l==x)return it;
	it--;
	int l=it->l,r=it->r,v=it->v;
	s.erase(it);
	s.insert(Node(l,x-1,v));
	return s.insert(Node(x,r,v)).first;
}
int ans=0;
void setval(int l,int r,int v)
{
	qwq it2=split(r+1);
	qwq it1=split(l),j;
//	return;
	for(qwq i=it1;i!=it2;i++)ans-=i->v*(i->r-i->l+1);
	s.erase(it1,it2);
	ans+=v*(r-l+1);
	s.insert(Node(l,r,v));
}
signed main()
{
	int n=read(),m=read();
	s.insert(Node(n+1,n+1,0));
	s.insert(Node(1,n,0));
	setval(1,n,1);
	while(m--)
	{
		int l=read(),r=read(),v=read()-1;
		setval(l,r,v);
		odl(ans);
	}
	return 0;
}