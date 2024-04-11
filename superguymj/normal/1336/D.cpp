#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=105;
bool vis[N];
int n,a[N],s[N],tmp[N];
struct data{int t,c;} x,y;

data query(int x)
{
	data ret;

	printf("+ %d\n",x),fflush(stdout);
	scanf("%d%d",&ret.t,&ret.c);
	return ret;
}

int calc(int x)
{
	rep(i,2,n+2) if(s[i]-s[i-1]==x) return i;
}

void PRT()
{
	--a[1],++a[n];
	printf("!");
	rep(i,1,n) printf(" %d",a[i]-1);
	puts(""),fflush(stdout);
}

void solve1()
{
	x=y,y=query(1),a[1]=calc(y.t-x.t);
	x=y,y=query(2),a[2]=calc(y.t-x.t);
	x=y,y=query(3),a[3]=calc(y.t-x.t);
	if(y.c-x.c-a[2]*a[1]==0) vis[4]=1;
}

void solve(int p)
{
	x=y,y=query(p);
	if(vis[p]) a[p]=1;
	else a[p]=calc(y.t-x.t);
	if(y.c-x.c-a[p-1]*a[p-2]==0) vis[p+1]=1;
}

void solve2()
{
	x=y,y=query(2);
	if(!(y.c-x.c))
	{
		data z=query(3),w=query(1);
		a[3]=1,a[2]=(w.c-z.c),a[1]=calc(w.t-z.t);
		if(z.c-y.c-(a[1]-1)*a[2]==0) vis[4]=1;
		x=z,y=w;
	}
	else
	{
		a[2]=1,x=y,y=query(1);
		a[1]=calc(y.t-x.t);
		solve(3);
	}
}

void solven()
{
	a[n]=y.c;
	rep(i,1,n-3) a[n]-=a[i]*a[i+1]*a[i+2];
	a[n]/=a[n-1]*a[n-2];
}

int main()
{
	scanf("%d",&n);
	rep(i,0,n+2) s[i]=i*(i-1)*(i-2)/6;
	scanf("%d%d",&x.t,&x.c);
	y=query(1);
	if(y.c-x.c) solve1();
	else solve2();
	rep(i,4,n-1) solve(i);
	solven();
	PRT();
	return 0;
}