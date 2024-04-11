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
bool cur[N<<2];
int n,m,ql,qr,tp,tot,k,x,y,top;
struct pos{int l,r;} stk[N];
struct data{int l,r,x;};
struct seg{data len,lmx,lmn,rmx,rmn,mx,mn;} t[N<<2],ans;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void st(seg &x,int a,int c)
{
	x.len=x.mx=x.mn=x.lmx=x.rmx=x.lmn=x.rmn=(data){a,a,c};
}

data mx(data x,data y)
{
	return x.x>y.x?x:y;
}

data mn(data x,data y)
{
	return x.x<y.x?x:y;
}

data operator + (data a,data b)
{
	return (data){a.l,b.r,a.x+b.x};
}

seg updata(seg x,seg y)
{
	seg rt;
	rt.len=x.len+y.len;
	rt.lmx=mx(x.len+y.lmx,x.lmx);
	rt.rmx=mx(x.rmx+y.len,y.rmx);
	rt.lmn=mn(x.len+y.lmn,x.lmn);
	rt.rmn=mn(x.rmn+y.len,y.rmn);
	rt.mx=mx(x.rmx+y.lmx,mx(x.mx,y.mx));
	rt.mn=mn(x.rmn+y.lmn,mn(x.mn,y.mn));
	return rt;
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		st(t[rt],l,getint());
		return;
	}
	build(l,mid,lch),build(mid+1,r,rch);
	t[rt]=updata(t[lch],t[rch]);
}

void modify(int l,int r,int rt)
{
	if(l==r)
	{
		st(t[rt],l,y);
		return;
	}
	if(x<=mid) modify(l,mid,lch);
	else modify(mid+1,r,rch);
	t[rt]=updata(t[lch],t[rch]);
}

void turn(int l,int r,int rt,bool tp)
{
	if(!tp) cur[rt]^=1,stk[++top]=(pos){l,r};
	else cur[rt]=0;
	swap(t[rt].mx,t[rt].mn);
	swap(t[rt].lmx,t[rt].lmn);
	swap(t[rt].rmx,t[rt].rmn);
	t[rt].mx.x*=-1,t[rt].mn.x*=-1;
	t[rt].lmx.x*=-1,t[rt].lmn.x*=-1;
	t[rt].rmx.x*=-1,t[rt].rmn.x*=-1;
	t[rt].len.x*=-1;
}

void pushdown(int l,int r,int rt,bool tp)
{
	if(cur[rt] && !tp) turn(l,mid,lch,tp),turn(mid+1,r,rch,tp),cur[rt]=0;
}

seg query(int l,int r,int rt)
{
	if(ql<=l && r<=qr) return t[rt];
	pushdown(l,r,rt,0);
	if(qr<=mid) return query(l,mid,lch);
	if(mid<ql) return query(mid+1,r,rch);
	return updata(query(l,mid,lch),query(mid+1,r,rch));
}

void rever(int l,int r,int rt,int ql,int qr,bool tp)
{
	if(ql<=l && r<=qr)
	{
		turn(l,r,rt,tp);
		return;
	}
	pushdown(l,r,rt,tp);
	if(ql<=mid) rever(l,mid,lch,ql,qr,tp);
	if(mid<qr) rever(mid+1,r,rch,ql,qr,tp);
	t[rt]=updata(t[lch],t[rch]);
}

int main()
{
	n=getint(),build(1,n,1);
	m=getint();
	while(m--)
	{
		tp=getint();
		if(tp==1)
		{
			tot=0,ql=getint(),qr=getint(),k=getint();
			while(k--)
			{
				if((ans=query(1,n,1)).mx.x<0) break;
				tot+=ans.mx.x,rever(1,n,1,ans.mx.l,ans.mx.r,0);
			}
			rep(i,1,top) rever(1,n,1,stk[i].l,stk[i].r,1);
			top=0,printf("%d\n",tot);
		}
		else x=getint(),y=getint(),modify(1,n,1);
	}
	return 0;
}