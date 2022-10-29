#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=100005;
typedef long long LL;
bool cur[N<<3],cur0[N<<3],cur1[N<<3];
int m,tot,ql,qr;
LL pool[N<<1];
struct data{int tp; LL l,r;} dat[N];
struct seg{int l,r,p0,p1;} t[N<<3];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL getLL()
{
	char ch;
	while(!isdigit(ch=getchar()));
	LL x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int find(LL x)
{
	int l=1,r=tot;
	while(l<=r) pool[mid]<=x?l=mid+1:r=mid-1;
	return l-1;
}

void build(int l,int r,int rt)
{
	t[rt].p0=l,t[rt].l=l,t[rt].r=r;
	if(l==r) return;
	build(l,mid,lch),build(mid+1,r,rch);
}

void turn1(int rt)
{
	t[rt].p0=0,t[rt].p1=t[rt].l;
	cur1[rt]=1,cur0[rt]=0,cur[rt]=0;
}

void turn0(int rt)
{
	t[rt].p0=t[rt].l,t[rt].p1=0;
	cur0[rt]=1,cur1[rt]=0,cur[rt]=0;
}

void turnr(int rt)
{
	swap(t[rt].p0,t[rt].p1);
	if(cur0[rt] || cur1[rt]) swap(cur0[rt],cur1[rt]);
	else cur[rt]^=1;
}

void pushdown(int rt)
{
	if(cur[rt]) turnr(lch),turnr(rch),cur[rt]=0;
	if(cur0[rt]) turn0(lch),turn0(rch),cur0[rt]=0;
	if(cur1[rt]) turn1(lch),turn1(rch),cur1[rt]=0;
}

void modify1(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turn1(rt);
		return;
	}
	pushdown(rt);
	if(ql<=mid) modify1(l,mid,lch);
	if(mid<qr) modify1(mid+1,r,rch);
	t[rt].p0=t[lch].p0?t[lch].p0:t[rch].p0;
	t[rt].p1=t[lch].p1?t[lch].p1:t[rch].p1;
}

void modify0(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turn0(rt);
		return;
	}
	pushdown(rt);
	if(ql<=mid) modify0(l,mid,lch);
	if(mid<qr) modify0(mid+1,r,rch);
	t[rt].p0=t[lch].p0?t[lch].p0:t[rch].p0;
	t[rt].p1=t[lch].p1?t[lch].p1:t[rch].p1;
}

void rever(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turnr(rt);
		return;
	}
	pushdown(rt);
	if(ql<=mid) rever(l,mid,lch);
	if(mid<qr) rever(mid+1,r,rch);
	t[rt].p0=t[lch].p0?t[lch].p0:t[rch].p0;
	t[rt].p1=t[lch].p1?t[lch].p1:t[rch].p1;
}	

int main()
{
	m=getint(),pool[*pool=1]=1;
	rep(i,1,m)
	{
		dat[i].tp=getint();
		dat[i].l=getLL(),dat[i].r=getLL();
		pool[++*pool]=dat[i].l,pool[++*pool]=dat[i].r+1;
	}
	sort(pool+1,pool+1+*pool);
	rep(i,1,*pool) if(i==1 || pool[i]!=pool[i-1]) pool[++tot]=pool[i];
	rep(i,1,m) dat[i].l=find(dat[i].l),dat[i].r=find(dat[i].r+1)-1;
	build(1,tot,1);
	rep(i,1,m)
	{
		ql=dat[i].l,qr=dat[i].r;
		if(dat[i].tp==1) modify1(1,tot,1);
		if(dat[i].tp==2) modify0(1,tot,1);
		if(dat[i].tp==3) rever(1,tot,1);
		printf("%lld\n",pool[t[1].p0]);
	}
	return 0;
}