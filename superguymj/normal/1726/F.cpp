#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
#define mid ((l+r)>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
const int N=200005;
const LL INF=10000000000000000ll;
bool cur[N<<3];
int n,k,tot,x,ql,qr;
LL m,g[N],c[N],d[N],h[N],pool[N<<1];
LL t[N<<3],ans,y;

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
		t[rt]=-pool[l];
		return;
	}
	build(l,mid,lch);
	build(mid+1,r,rch);
	t[rt]=min(t[lch],t[rch]);
}

void turn(int rt)
{
	cur[rt]=1;
	t[rt]=INF;
}

void pushdown(int rt)
{
	if(cur[rt])
	{
		turn(lch);
		turn(rch);
		cur[rt]=0;
	}
}

LL query(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
		return t[rt];
	pushdown(rt);
	if(qr<=mid) return query(l,mid,lch);
	if(ql>mid) return query(mid+1,r,rch);
	return min(query(l,mid,lch),query(mid+1,r,rch));
}

void modify(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		turn(rt);
		return;
	}
	pushdown(rt);
	if(ql<=mid) modify(l,mid,lch);
	if(mid<qr) modify(mid+1,r,rch);
	t[rt]=min(t[lch],t[rch]);
}

void insert(int l,int r,int rt)
{
	if(l==r)
	{
		t[rt]=y-pool[l];
		return;
	}
	pushdown(rt);
	if(x<=mid) insert(l,mid,lch);
	else insert(mid+1,r,rch);
	t[rt]=min(t[lch],t[rch]);
}

int find(int x)
{
	int l=1,r=k;
	while(l<=r) pool[mid]<=x?l=mid+1:r=mid-1;
	return l-1;
}

void dfs(int l,int r,int rt)
{
	if(l==r)
	{
		ans=min(ans,t[rt]+pool[l]);
		return;
	}
	pushdown(rt);
	dfs(l,mid,lch);
	dfs(mid+1,r,rch);
}

void modify(int i)
{
	int l=find(h[i])+1;
	if(l>k) l=1;
	int r=find((c[i]-1+m)%m);
	if(r<1) r=k;
	if(l<=r)
	{
		ql=l,qr=r;
		modify(1,k,1);	
	}
	else if(r+1<l)
	{
		ql=l,qr=k;
		modify(1,k,1);
		ql=1,qr=r;
		modify(1,k,1);
	}
}

void update(int i)
{
	x=find(c[i]);
	int l=find(h[i])+1;
	if(l>k) l=1;
	int r=x;
	if(l<=r)
	{
		ql=l,qr=r,y=query(1,k,1)+pool[x];
		insert(1,k,1);
	}
	else
	{
		ql=1,qr=r,y=query(1,k,1)+pool[x];
		ql=l,qr=k,y=min(y,query(1,k,1)+pool[x]+m);
		insert(1,k,1);
	}
}

int main()
{
//	freopen("f.in","r",stdin);
	n=getint(),m=getint();
	rep(i,1,n) g[i]=getint(),c[i]=(m-getint())%m;
	rep(i,1,n-1) d[i]=getint()+d[i-1];
	rep(i,1,n) c[i]=((c[i]-d[i-1])%m+m)%m;
	rep(i,1,n) h[i]=(c[i]+g[i]-1+m)%m;
	rep(i,1,n)
	{
		pool[++tot]=c[i];
		pool[++tot]=h[i];
	}
	sort(pool+1,pool+1+tot);
	rep(i,1,tot) if(i==1 || pool[i]!=pool[i-1]) pool[++k]=pool[i];
	build(1,k,1);
	modify(1);
	rep(i,2,n)
	{
		update(i);
		modify(i);
	}
	ans=INF;
	dfs(1,k,1);
	printf("%lld\n",ans+d[n-1]);
	return 0;
}