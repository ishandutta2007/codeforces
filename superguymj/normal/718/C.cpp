#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=100005,mod=1000000007;
int n,m,x,ql,qr,tp;
typedef long long LL;
LL ret[2][2],mxt[2][2],f[2][2],cur[N<<2][2][2];
struct seg{LL a[2];} t[N<<2];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

seg updata(seg x,seg y)
{
	seg rt;
	rt.a[0]=(x.a[0]+y.a[0])%mod;
	rt.a[1]=(x.a[1]+y.a[1])%mod;
	return rt;
}

void change(int x)
{
	ret[0][0]=ret[0][1]=ret[1][0]=1,ret[1][1]=0;
	mxt[0][0]=mxt[1][1]=1,mxt[0][1]=mxt[1][0]=0;
	while(x)
	{
		if(x&1)
		{
			memset(f,0,sizeof(f));
			rep(i,0,1)
				rep(j,0,1)
					rep(k,0,1)
						f[i][j]=(f[i][j]+ret[i][k]*mxt[k][j])%mod;
			rep(i,0,1) rep(j,0,1) mxt[i][j]=f[i][j];
		}
		memset(f,0,sizeof(f));
		rep(i,0,1)
			rep(j,0,1)
				rep(k,0,1)
					f[i][j]=(f[i][j]+ret[i][k]*ret[k][j])%mod;
		rep(i,0,1) rep(j,0,1) ret[i][j]=f[i][j];
		x>>=1;
	}
}

int get(int x)
{
	if(x==0) return 0;
	if(x==1) return 1;
	x-=1,change(x);
	return mxt[0][0];
}

void build(int l,int r,int rt)
{
	cur[rt][0][0]=cur[rt][1][1]=1;
	if(l==r)
	{
		t[rt].a[0]=get(x=getint());
		t[rt].a[1]=get(x-1);
		return;
	}
	build(l,mid,lch);
	build(mid+1,r,rch);
	t[rt]=updata(t[lch],t[rch]);
}

void turn(int rt)
{
	memset(f,0,sizeof(f));
	rep(i,0,1) rep(j,0,1) rep(k,0,1) f[i][j]=(f[i][j]+cur[rt][i][k]*ret[k][j])%mod;
	rep(i,0,1) rep(j,0,1) cur[rt][i][j]=f[i][j];
	memset(f,0,sizeof(f));
	rep(i,0,1) rep(j,0,1) f[i][0]=(f[i][0]+t[rt].a[j]*ret[i][j])%mod;
	rep(i,0,1) t[rt].a[i]=f[i][0];
}

void pushdown(int rt)
{
	if(cur[rt][0][0]==1 && cur[rt][1][1]==1 && cur[rt][0][1]==0 && cur[rt][1][0]==0) return;
	ret[0][0]=cur[rt][0][0],ret[1][1]=cur[rt][1][1];
	ret[0][1]=cur[rt][0][1],ret[1][0]=cur[rt][1][0];
	turn(lch),turn(rch),cur[rt][0][0]=cur[rt][1][1]=1,cur[rt][1][0]=cur[rt][0][1]=0;
}

void modify(int l,int r,int rt)
{
	if(ql<=l && r<=qr)
	{
		ret[0][0]=mxt[0][0],ret[1][1]=mxt[1][1];
		ret[0][1]=mxt[0][1],ret[1][0]=mxt[1][0];
		turn(rt);
		return;
	}
	pushdown(rt);
	if(ql<=mid) modify(l,mid,lch);
	if(mid<qr) modify(mid+1,r,rch);
	t[rt]=updata(t[lch],t[rch]);
}

int query(int l,int r,int rt)
{
	if(ql<=l && r<=qr) return t[rt].a[0];
	pushdown(rt);
	if(qr<=mid) return query(l,mid,lch);
	if(ql>mid) return query(mid+1,r,rch);
	return (query(l,mid,lch)+query(mid+1,r,rch))%mod;
}

int main()
{
	n=getint(),m=getint();
	build(1,n,1);
	while(m--)
	{
		tp=getint(),ql=getint(),qr=getint();
		if(tp==1)
		{
			x=getint(),change(x);
			modify(1,n,1);
		}
		else printf("%d\n",query(1,n,1));
	}
	return 0;
}