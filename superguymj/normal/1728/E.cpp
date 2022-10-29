#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=300005,M=555;
typedef long long LL;
int n,lim;
LL a[N],b[N],c[N],ans[N],mx[M][M];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void init()
{
	rep(i,1,n) ans[0]+=b[i];
	rep(i,1,n) c[i]=a[i]-b[i];
	sort(c+1,c+1+n);
	reverse(c+1,c+1+n);
	rep(i,1,n) ans[i]=ans[i-1]+c[i];
	lim=550;

	rep(i,1,lim)
	{
		int tp=0;
		rep(j,0,n)
		{
			mx[i][tp]=max(mx[i][tp],ans[j]);
			if((++tp)==i) tp=0;
		}
	}
}

void exgcd(LL a,LL b,LL &x,LL &y,LL &d)
{
	if(!b)
	{
		x=1,y=0,d=a;
		return;
	}
	exgcd(b,a%b,y,x,d),y-=a/b*x;
}

LL query(LL x,LL m)
{
	if(m<=lim) return mx[m][x];
	LL mx=0;
	for(LL i=x; i<=n; i+=m)
		mx=max(mx,ans[i]);
	return mx;
}

LL query()
{
	LL x=getint(),y=getint();
	LL _x,_y,d;
	exgcd(x,y,_x,_y,d);
	if(n%d) return -1;
	_x*=n/d;
	_y*=n/d;
	if(_x<0)
	{
		LL dv=(-_x+(y/d)-1)/(y/d);
		_x+=dv*(y/d);
		_y-=dv*(x/d);
		if(_y<0) return -1;
	}
	else
	{
		LL dv=_x/(y/d);
		_x-=dv*(y/d);
		_y+=dv*(x/d);
		if(_y<0) return -1;
	}
	return query(_x*x,y/d*x);
}

int main()
{
	n=getint();
	rep(i,1,n) a[i]=getint(),b[i]=getint();
	init();
	int m=getint();
	while(m--) printf("%lld\n",query());
	return 0;
}