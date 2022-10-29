#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=300005;
typedef long long LL;
int n,a[N],mx,p[100],id[N],P;
LL t0[N],t1[N],ans,tt0[N],tt1[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void ins(LL t[],LL tt[],int x,int y)
{
	rep(i,id[x],id[mx]) t[i]+=y;
	rep(i,x,mx)
	{
		if(id[i]!=id[x]) break;
		tt[i]+=y;
	}
}

LL query(LL t[],LL tt[],int x)
{
	x=max(1,x);
	x=min(x,mx);
	return t[id[x]-1]+tt[x];
}

void solve1(int x)
{
	LL c0l=0,c1l=0,c0r,c1r;
	for(int i=0; i<=mx; i+=x)
	{
		c0r=query(t0,tt0,i+x-1);
		c1r=query(t1,tt1,i+x-1);
		ans+=(c1r-c1l)-i*(c0r-c0l);
		c0l=c0r,c1l=c1r;
	}
}

void solve2(int x)
{
	int i=1,j;
	LL c0l=0,c1l=0,c0r,c1r;
	for(; i<=x; i=j+1)
	{
		j=x/(x/i);
		c0r=query(t0,tt0,j);
		c1r=query(t1,tt1,j);
		ans+=x*(c0r-c0l)-(x/i)*(c1r-c1l);
		c0l=c0r,c1l=c1r;
	}
	ans+=(query(t0,tt0,mx)-c0l)*x;
}

void PRT(LL x)
{
	if(!x) {putchar('0'); return;}
	int c=0;
	while(x) p[++c]=x%10,x/=10;
	repd(i,c,1) putchar('0'+p[i]);
}

void pre()
{
	P=sqrt(mx);
	rep(i,1,mx) id[i]=(i-1)/P+1;
}

int main()
{
	n=getint();
	rep(i,1,n) mx=max(mx,a[i]=getint());
	pre();
	rep(i,1,n)
	{
		solve1(a[i]);
		solve2(a[i]);
		PRT(ans),putchar(' ');
		ins(t0,tt0,a[i],1);
		ins(t1,tt1,a[i],a[i]);
	}
	puts("");
	return 0;
}