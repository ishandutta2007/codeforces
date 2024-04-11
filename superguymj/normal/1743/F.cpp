#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid ((l+r)>>1)
#define pb push_back
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
const int N=300005,mod=998244353;
int n,m,s[N],tp;
LL ans;
vector <int> a[N];

struct seg
{
	LL a[2][2];
	
	void turn(int t)
	{
		if(t==0)
		{
			a[0][0]=3,a[0][1]=0;
			a[1][0]=1,a[1][1]=2;
		}
		else
		{
			a[0][0]=1,a[0][1]=2;
			a[1][0]=1,a[1][1]=2;
		}
	}
} t[N<<2];

seg operator * (seg a,seg b)
{
	seg c;
	rep(i,0,1) rep(j,0,1) c.a[i][j]=0;
	rep(i,0,1) rep(j,0,1) rep(k,0,1)
		c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
	return c;
}

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
		t[rt].turn(0);
		return;
	}
	build(l,mid,lch);
	build(mid+1,r,rch);
	t[rt]=t[lch]*t[rch];
}

void modify(int l,int r,int rt,int x)
{
	if(x==1) {tp^=1; return;}
	if(l==r)
	{
		s[l]^=1;
		t[rt].turn(s[l]);
		return;
	}
	if(x<=mid) modify(l,mid,lch,x);
	else modify(mid+1,r,rch,x);
	t[rt]=t[lch]*t[rch];
}

int main()
{
	n=getint();
	rep(i,1,n)
	{
		int l=getint(),r=getint();
		a[l].pb(i),a[r+1].pb(i);
		m=max(m,r);
	}
	build(2,n,1);
	rep(i,0,m)
	{
		for(auto x:a[i]) modify(2,n,1,x);
		ans=(ans+t[1].a[tp][1])%mod;
	}
	printf("%lld\n",ans);	
	return 0;
}