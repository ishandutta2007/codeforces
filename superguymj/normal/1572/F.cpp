#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=200005;
typedef long long LL;
int n,m,ql,qr,x,y,cur[N<<2];
struct seg{int mx,se,cnt;} t[N<<2];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

struct bit_tree
{
	LL t1[N],t2[N];

	void ins(LL t[],int x,LL y)
	{
		for(int i=x; i<=n; i+=i&-i) t[i]+=y;
	}

	void insert(int l,int r,LL c)
	{
		ins(t1,l,c),ins(t1,r+1,-c);
		ins(t2,l,l*c),ins(t2,r+1,-(r+1)*c);
	}

	LL query(int x)
	{
		LL ret=0;
		for(int i=x; i; i-=i&-i)
			ret+=t1[i]*(x+1)-t2[i];
		return ret;
	}

	LL query(int l,int r)
	{
		return query(r)-query(l-1);
	}
} bit;

seg operator + (seg x,seg y)
{
    seg ret;
    ret.mx=max(x.mx,y.mx);
    ret.cnt=x.cnt*(x.mx==ret.mx)+y.cnt*(y.mx==ret.mx);
    if(x.mx==y.mx) ret.se=max(x.se,y.se);
    if(x.mx>y.mx) ret.se=max(x.se,y.mx);
    if(x.mx<y.mx) ret.se=max(x.mx,y.se);
    return ret;
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt].mx=l,t[rt].se=0,t[rt].cnt=1;
		return;
	}
	build(l,mid,lch),build(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

void turn(int rt,int x)
{
	if(x<t[rt].mx)
		t[rt].mx=x,cur[rt]=x;
}

void pushdown(int rt)
{
	if(cur[rt])
	{
		turn(lch,cur[rt]);
		turn(rch,cur[rt]);
		cur[rt]=0;
	}
}

void modify(int l,int r,int rt)
{
	if(l==r)
	{
		bit.insert(l,t[rt].mx,-1);
		t[rt].mx=y,bit.insert(l,t[rt].mx,1);
		return;
	}
	pushdown(rt);
	if(x<=mid) modify(l,mid,lch);
	else modify(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

void chkmin(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		if(t[rt].mx<=y) return;
		if(t[rt].se<y)
		{
			bit.insert(y+1,t[rt].mx,-t[rt].cnt);
			turn(rt,y);
			return;
		}
	}
	pushdown(rt);
	if(ql<=mid) chkmin(l,mid,lch);
	if(mid<qr) chkmin(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

int main()
{
	n=getint(),m=getint();
	bit.insert(1,n,1);
	build(1,n,1);
	while(m--)
	{
		int tp=getint();
		if(tp==1)
		{
			x=getint(),y=getint();
			modify(1,n,1);
			ql=1,qr=x-1,y=x-1;
			if(ql<=qr) chkmin(1,n,1);
		}
		else
		{
			ql=getint(),qr=getint();
			printf("%lld\n",bit.query(ql,qr));
		}
	}
	return 0;
}