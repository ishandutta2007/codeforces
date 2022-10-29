#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=500005;
const LL INF=1000000000000000000ll;
int n,m,ql,qr,x;
LL y,ans,g[N],a[3][N],s[3][N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

struct seg1
{
	LL t[N<<2];
	
	void build(int l,int r,int rt)
	{
		if(l==r)
		{
			t[rt]=-INF;
			return;
		}
		build(l,mid,lch);
		build(mid+1,r,rch);
		t[rt]=max(t[lch],t[rch]);
	}

	void ins(int l,int r,int rt)
	{
		if(l==r)
		{
			t[rt]=max(t[rt],y);
			return;
		}
		if(x<=mid) ins(l,mid,lch);
		else ins(mid+1,r,rch);
		t[rt]=max(t[lch],t[rch]);
	}

	LL query(int l,int r,int rt)
	{
		if(ql<=l && r<=qr) return t[rt];
		if(qr<=mid) return query(l,mid,lch);
		if(mid<ql) return query(mid+1,r,rch);
		return max(query(l,mid,lch),query(mid+1,r,rch));
	}
} t1;

struct D{int l,k;} v;
vector <D> vt[N];
struct seg{LL x,y,ans;} ;

seg operator + (seg a,seg b)
{
	seg ret={max(a.x,b.x),max(a.y,b.y),max(max(a.ans,b.ans),a.x+b.y)};
	return ret;
}

struct seg2
{
	seg t[N<<2];
	
	void build(int l,int r,int rt)
	{
		if(l==r)
		{
			t[rt].x=max(g[l-1]-s[1][l-1],s[0][l]-s[1][l-1]);
			t[rt].y=s[1][l]+s[2][n]-s[2][l-1];
			t[rt].ans=t[rt].x+t[rt].y;
			ans=max(ans,g[l]-s[1][l]+t[rt].y);
			return;
		}
		build(l,mid,lch);
		build(mid+1,r,rch);
		t[rt]=t[lch]+t[rch];
	}

	seg query(int l,int r,int rt)
	{
		if(ql<=l && r<=qr) return t[rt];
		if(qr<=mid) return query(l,mid,lch);
		if(mid<ql) return query(mid+1,r,rch);
		return query(l,mid,lch)+query(mid+1,r,rch);
	}
} t2;

int main()
{
	n=getint(),m=getint();
	rep(t,0,2) rep(i,1,n) a[t][i]=getint(),s[t][i]=s[t][i-1]+a[t][i];
	rep(i,1,m)
	{
		int l=getint(),r=getint(),k=getint();
		vt[r].pb((D){l,k});
	}
	t1.build(0,n,1);
	rep(i,0,n-1)
	{
		x=i,y=s[0][i+1]-s[1][i];
		t1.ins(0,n,1);
	}

	g[0]=-INF;
	rep(i,1,n)
	{
		int sz=vt[i].size();
		g[i]=-INF;
		rep(j,0,sz-1)
		{
			ql=vt[i][j].l-1,qr=i-1;
			y=t1.query(0,n,1)-vt[i][j].k,g[i]=max(g[i],y+s[1][i]);
			x=i,t1.ins(0,n,1);
		}
	}	

	ans=-INF;
	t2.build(1,n,1);
	rep(i,1,n)
	{
		int sz=vt[i].size();
		rep(j,0,sz-1)
		{
			ql=vt[i][j].l,qr=i;
			ans=max(ans,t2.query(1,n,1).ans-vt[i][j].k);
		}
	}
	printf("%lld\n",ans);
	return 0;
}