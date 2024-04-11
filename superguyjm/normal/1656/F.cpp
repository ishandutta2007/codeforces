#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=200005;
int n;
LL a[N],ans;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

LL check(LL x)
{
	rep(i,1,n) a[i]+=x;
	LL ret=0;
	if(a[1]<=0 && a[n]>=0)
	{
		ret=a[1]*a[n];
		rep(i,2,n-1) if(a[i]<=0) ret+=a[i]*a[n]; else ret+=a[i]*a[1];
	}
	else
	{
		if(a[1]>=0) rep(i,2,n) ret+=a[1]*a[i];
		else rep(i,1,n-1) ret+=a[i]*a[n];
	}
	rep(i,1,n) a[i]-=x;
	return ret-x*x*(n-1);
}

void solve()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	sort(a+1,a+1+n);
	LL x=a[1]*(n-2),y=a[n]*(n-2);
	rep(i,1,n) x+=a[i],y+=a[i];
	if(x>y) swap(x,y);
	if(x>0 || y<0) 
	{
		puts("INF");
		return;
	}
	ans=check(0);
	int l=-5000000,r=5000000;
	rep(i,1,100)
	{
		LL m1=check(l+(r-l)/3);
		LL m2=check(l+(r-l)/3*2);
		ans=max(ans,max(m1,m2));
		if(m1>m2) r=l+(r-l)/3*2;
		else l=l+(r-l)/3;
	}
	rep(i,l,r) ans=max(ans,check(i));
	printf("%lld\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}