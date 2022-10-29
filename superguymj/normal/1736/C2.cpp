#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;
typedef long long LL;
const int N=200005;
int n,a[N],b[N],q,x,y,tp;
multiset <int> st[N];
struct seg{LL l,r,ans;} t[N<<2];
LL tmp[N<<2],tot;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;	
	return x;
}

LL calc(int l,int r,int rt,LL x)
{
	if(l==r)
		return min(t[rt].l,x);
	if(t[rch].l<x) return tmp[rt]+calc(mid+1,r,rch,x);
	return calc(l,mid,lch,x)+x*(r-mid);
}

void pushup(int l,int r,int rt)
{
	if(t[rch].l<=t[lch].l)
	{
		t[rt]=t[rch];
		t[rt].ans+=(tmp[rt]=t[rch].l*(mid-l+1));
		return;
	}
	t[rt].l=t[lch].l;
	t[rt].r=t[rch].r;
	t[rt].ans=t[rch].ans+(tmp[rt]=calc(l,mid,lch,t[rch].l));
}

void modify(int l,int r,int rt)
{
	if(l==r)
	{
		if(tp) st[l].insert(y);
		else st[l].erase(st[l].find(y));
		t[rt].ans=t[rt].l=t[rt].r=*st[l].begin();
		return;
	}
	if(x<=mid) modify(l,mid,lch);
	else modify(mid+1,r,rch);
	pushup(l,r,rt);
}

void ins(int _x,int _y)
{
	x=_x,y=_y,tp=1;
	modify(1,n,1);
}

void del(int _x,int _y)
{
	x=_x,y=_y,tp=0;
	modify(1,n,1);
}

int main()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) ins(i,n);
	rep(i,1,n)
	{
		b[i]=i-a[i];
		if(b[i]>0) ins(b[i],i-1);
	}
	rep(i,1,n-1) tot+=i;
	q=getint();
	while(q--)
	{
		int x=getint(),tmp=a[x];
		if(b[x]>0) del(b[x],x-1);
		a[x]=getint(),b[x]=x-a[x];
		if(b[x]>0) ins(b[x],x-1);
		printf("%lld\n",t[1].ans-tot);

		if(b[x]>0) del(b[x],x-1);
		a[x]=tmp,b[x]=x-a[x];
		if(b[x]>0) ins(b[x],x-1);
	}
	return 0;
}