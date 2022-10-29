#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef __int128 LL;
const int N=1005;
int n,m;
LL a[N],b[N];

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

LL gcd(LL a,LL b)
{
	return !b?a:gcd(b,a%b);
}

void prt(LL a)
{
	if(a>9) prt(a/10);
	putchar('0'+a%10);
}

struct segment_tree
{
	int x;
	LL t[N<<2];

	void build(int l,int r,int rt,LL a[],LL x)
	{
		if(l==r)
		{
			t[rt]=x/gcd(a[l],x);
			return;
		}
		build(l,mid,lch,a,x);
		build(mid+1,r,rch,a,x);
		t[rt]=gcd(t[lch],t[rch]);
	}
	
	void del(int l,int r,int rt)
	{
		if(l==r)
		{
			t[rt]=0;
			return;
		}
		if(x<=mid) del(l,mid,lch);
		else del(mid+1,r,rch);
		t[rt]=gcd(t[lch],t[rch]);
	}

	void del(int _x,int n)
	{
		x=_x;
		del(1,n,1);
	}
} A[N],B[N];

void solve()	
{
	n=getint(),m=getint();
	rep(i,1,n) a[i]=getLL();
	rep(i,1,m) b[i]=getLL();
	rep(i,1,n) A[i].build(1,m,1,b,a[i]);
	rep(i,1,m) B[i].build(1,n,1,a,b[i]);
	rep(i,1,n+m)
	{
		bool jdg=0;
		rep(j,1,n) if(A[j].t[1]>1 && a[j])
		{
			rep(k,1,m) if(b[k]) B[k].del(j,n);
			a[j]=0,jdg=1;
			break;
		}
		if(jdg) continue;
		rep(j,1,m) if(B[j].t[1]>1 && b[j])
		{
			rep(k,1,n) if(a[k]) A[k].del(j,m);
			b[j]=0,jdg=1;
			break;
		}
		if(jdg) continue;
		break;
	}
	*a=*b=0;
	rep(i,1,n) if(a[i]) a[++*a]=a[i];
	rep(i,1,m) if(b[i]) b[++*b]=b[i];
	if(!(*a) || !(*b)) puts("NO");
	else
	{
		puts("YES");
		prt(*a),putchar(' '),prt(*b),puts("");
		rep(i,1,*a) prt(a[i]),putchar(' ');
		puts("");
		rep(i,1,*b) prt(b[i]),putchar(' ');
		puts("");
	}
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}