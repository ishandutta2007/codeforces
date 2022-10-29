#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
const int N=200005;
int n,m,x,y,ql,qr;
struct seg
{
	int lx,rx,l,r,len;
	LL ans;
} t[N<<2];

seg operator + (seg x,seg y)
{
	seg ret;
	ret.lx=x.lx,ret.rx=y.rx;
	ret.len=x.len+y.len;
	ret.l=x.l+(x.l==x.len && x.rx<=y.lx)*y.l;
	ret.r=y.r+(y.r==y.len && x.rx<=y.lx)*x.r;
	ret.ans=x.ans+y.ans+(LL)x.r*y.l*(x.rx<=y.lx);
	return ret;
}

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;	
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt].lx=t[rt].rx=getint();
		t[rt].l=t[rt].r=t[rt].len=t[rt].ans=1;
		return;
	}
	build(l,mid,lch);
	build(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

void modify(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt].lx=t[rt].rx=y;
		return;
	}
	if(x<=mid) modify(l,mid,lch);
	else modify(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

seg query(int l,int r,int rt)
{
	if(ql<=l && r<=qr) return t[rt];
	if(qr<=mid) return query(l,mid,lch);
	if(ql>mid) return query(mid+1,r,rch);
	return query(l,mid,lch)+query(mid+1,r,rch);
}

int main()
{
	n=getint(),m=getint();
	build(1,n,1);
	while(m--)
	{
		int tp=getint();
		if(tp==1) x=getint(),y=getint(),modify(1,n,1);
		else ql=getint(),qr=getint(),printf("%lld\n",query(1,n,1).ans);
	}
	return 0;
}