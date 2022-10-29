#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
const int N=100005;
int n,m,a[N],mod,ql,qr,x,p;
int tot,prm[10],c[10],pw[10][17*N];
LL inv[N],t[N<<2],cur1[N<<2];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(!b) return x=1,y=0,a;
    int d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}

struct num
{
	int x,c[10];

	void init(int t=0)
	{
		x=1,memset(c,0,sizeof(c));
		if(!t) return;
		rep(i,1,tot) while(t%prm[i]==0) t/=prm[i],++c[i];
		x=t;
	}

	void operator *= (num t)
	{
		x=(LL)x*t.x%mod;
		rep(i,1,tot) c[i]+=t.c[i];
	}

	void operator /= (num t)
	{
		x=(LL)x*inv[t.x]%mod;
		rep(i,1,tot) c[i]-=t.c[i];
	}

	LL cnt()
	{
		LL rt=x;
		rep(i,1,tot) rt=rt*pw[i][c[i]]%mod;
		return rt;
	}
} b[N],y,cur2[N<<2];;

void pre()
{
	int x=mod,P=sqrt(mod);
	rep(i,2,P)
		if(x%i==0)
		{
			prm[++tot]=i;
			while(x%i==0) x/=i,++c[tot];
		}
	if(x>1) prm[++tot]=x,c[tot]=1;
	rep(i,1,tot)
	{
		pw[i][0]=1;
		rep(j,1,17*(m+1)) pw[i][j]=(LL)pw[i][j-1]*prm[i]%mod;
	}
}

void build(int l,int r,int rt)
{
	cur1[rt]=1;
	cur2[rt].init();
	if(l==r)
	{
		t[rt]=a[l]%mod,b[l].init(a[l]);
		return;
	}
	build(l,mid,lch);
	build(mid+1,r,rch);
	t[rt]=(t[lch]+t[rch])%mod;
}

void turn(int rt,int x,num y)
{
	cur1[rt]=cur1[rt]*x%mod;
	t[rt]=t[rt]*x%mod,cur2[rt]*=y;
	
}

void pushdown(int rt)
{
	if(cur1[rt]!=1)
	{
		turn(lch,cur1[rt],cur2[rt]);
		turn(rch,cur1[rt],cur2[rt]);
		cur1[rt]=1,cur2[rt].init();
	}
}

void modify(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turn(rt,x,y);
		return;
	}
	pushdown(rt);
	if(ql<=mid) modify(l,mid,lch);
	if(mid<qr) modify(mid+1,r,rch);
	t[rt]=(t[lch]+t[rch])%mod;
}

void modify()
{
	ql=getint(),qr=getint(),x=getint(),y.init(x);
	modify(1,n,1);
}

void div(int l,int r,int rt)
{
	if(l==r)
	{
		b[l]*=cur2[rt];
		cur2[rt].init();
		b[l]/=y,t[rt]=b[l].cnt();
		return;
	}
	pushdown(rt);
	if(p<=mid) div(l,mid,lch);
	else div(mid+1,r,rch);
	t[rt]=(t[lch]+t[rch])%mod;
}

void div()
{
	p=getint(),x=getint(),y.init(x);
	div(1,n,1);
}

LL query(int l,int r,int rt)
{
	if(ql<=l && r<=qr) return t[rt];
	pushdown(rt);
	if(qr<=mid) return query(l,mid,lch);
	if(mid<ql) return query(mid+1,r,rch);
	return (query(l,mid,lch)+query(mid+1,r,rch))%mod;
}

void query()
{
	ql=getint(),qr=getint();
	printf("%lld\n",query(1,n,1));
}

int main()
{
	n=getint(),mod=getint();
	rep(i,1,100000)
	{
		LL a,b;
		exgcd(i,mod,a,b);
		inv[i]=(a%mod+mod)%mod;
	}
	rep(i,1,n) a[i]=getint();
	m=getint();
	pre();
	build(1,n,1);
	while(m--)
	{
		int tp=getint();
		if(tp==1) modify();
		if(tp==2) div();
		if(tp==3) query();
	}
	return 0;
}