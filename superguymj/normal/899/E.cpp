#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=200005;
int n,ql,qr,x,ans;

struct data
{
	int s,l,r,ansl,ansr;
	void init(int id,int x)
	{
		s=1,l=r=x,ansl=ansr=id;
	}
};

data operator + (data a,data b)
{
	return (data){a.s+b.s,a.l,b.r,a.ansl,b.ansr};
}

struct seg
{
	data tot,l,r,ans;
	void init(int id,int x)
	{
		tot.init(id,x);
		l.init(id,x);
		r.init(id,x);
		ans.init(id,x);
	}
} t[N<<2];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

data mx(data a,data b)
{
	return a.s>=b.s?a:b;
}

seg updata(seg x,seg y)
{
	if(!x.tot.s) return y;
	if(!y.tot.s) return x;
	seg rt;
	rt.tot=x.tot+y.tot,rt.l=x.l,rt.r=y.r;
	if(rt.l.s==x.tot.s && x.l.r==y.l.l)
		rt.l=x.l+y.l;
	if(rt.r.s==y.tot.s && x.r.r==y.r.l)
		rt.r=x.r+y.r;
	if(x.r.r==y.l.l) rt.ans=mx(mx(x.ans,x.r+y.l),y.ans);
	else rt.ans=mx(x.ans,y.ans);
	return rt;
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		x=getint(),t[rt].init(l,x);
		return;
	}
	build(l,mid,lch),build(mid+1,r,rch);
	t[rt]=updata(t[lch],t[rch]);
}

void modify(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		t[rt].tot.s=0;
		return;
	}
	if(ql<=mid) modify(l,mid,lch);
	if(mid<qr) modify(mid+1,r,rch);
	t[rt]=updata(t[lch],t[rch]);
}
	
int main()
{
	n=getint();
	build(1,n,1);
	while(t[1].tot.s)
		++ans,ql=t[1].ans.ansl,qr=t[1].ans.ansr,modify(1,n,1);
	printf("%d\n",ans);
	return 0;
}