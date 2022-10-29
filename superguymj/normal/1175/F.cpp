#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define pb push_back

using namespace std;
const int N=300005;
typedef long long LL;
int vis[N];
int n,m,a[N],top1,top2,stk1[N],stk2[N],ql,qr,x;
struct seg{int tot,mn; LL s;} t[N<<2];
LL cur[N<<2],add[N<<2],ans;
struct Q{int id,x;};
vector <Q> vt[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

seg operator + (seg x,seg y)
{
	seg ret;
	ret.mn=min(x.mn,y.mn);
	ret.s=x.s+y.s;
	ret.tot=(x.mn==ret.mn)*x.tot+(y.mn==ret.mn)*y.tot;
	return ret;
}

void build(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt].mn=l;
		t[rt].tot=1;
		return;
	}
	build(l,mid,lch),build(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

void turn_add(int rt,int x)
{
	t[rt].mn+=x,add[rt]+=x;
}

void turn_cur(int rt,int x)
{
	t[rt].s+=(LL)t[rt].tot*x,cur[rt]+=x;
}

void pushdown(int rt)
{
	if(add[rt]) turn_add(lch,add[rt]),turn_add(rch,add[rt]),add[rt]=0;
	if(cur[rt])
	{
		if(t[lch].mn==t[rt].mn)
			turn_cur(lch,cur[rt]);
		if(t[rch].mn==t[rt].mn)
			turn_cur(rch,cur[rt]);
		cur[rt]=0;
	}
}

void modify(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turn_add(rt,x);
		return;
	}
	pushdown(rt);
	if(ql<=mid) modify(l,mid,lch);
	if(mid<qr) modify(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

void reset(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		if(t[rt].mn==x)
			turn_cur(rt,1);
		return;
	}
	pushdown(rt);
	if(ql<=mid) reset(l,mid,lch);
	if(mid<qr) reset(mid+1,r,rch);
	t[rt]=t[lch]+t[rch];
}

LL query(int l,int r,int rt)
{
	if(ql<=l && r<=qr) return t[rt].s;
	pushdown(rt);
	if(qr<=mid) return query(l,mid,lch);
	if(mid<ql) return query(mid+1,r,rch);
	return query(l,mid,lch)+query(mid+1,r,rch);
}

int main()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	build(1,n,1);
	int lst=0,nxt=1;
	rep(i,1,n)
	{
		if(a[i]==1) lst=i;
		nxt=max(nxt,vis[a[i]]+1),vis[a[i]]=i;
		while(top1 && a[stk1[top1]]>=a[i])
		{
			ql=stk1[top1-1]+1,qr=stk1[top1];
			x=a[stk1[top1]],modify(1,n,1),--top1;
		}
		stk1[++top1]=i,ql=stk1[top1-1]+1,qr=i,x=-a[i],modify(1,n,1);
		
		while(top2 && a[stk2[top2]]<=a[i])
		{
			ql=stk2[top2-1]+1,qr=stk2[top2];
			x=-a[stk2[top2]],modify(1,n,1),--top2;
		}
		stk2[++top2]=i,ql=stk2[top2-1]+1,qr=i,x=a[i],modify(1,n,1);
	
		ql=nxt,qr=lst,x=i;
		if(ql<=qr) reset(1,n,1);
	}
	printf("%lld\n",t[1].s);
	return 0;
}