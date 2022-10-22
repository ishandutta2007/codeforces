#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
typedef long long LL;
const int N=100005;
const LL INF=2000000000000000000;
int n,m,k,a[N],b[N],c[N];
LL ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL sqr(LL x) {return x*x;}

void chkmin(LL &ans,LL a,LL b,LL c)
{
	ans=min(ans,sqr(a-b)+sqr(b-c)+sqr(a-c));
}

LL calc(int a[],int b[],int c[],int n,int m,int k)
{
	LL ans=INF;
	int j1=0,j2=1;
	rep(i,1,n)
	{
		while(j1+1<=m && b[j1+1]<=a[i]) ++j1;
		while(j2+1<=k && c[j2]<a[i]) ++j2;
		if(j1 && b[j1]<=a[i] && a[i]<=c[j2]) chkmin(ans,a[i],b[j1],c[j2]);
	}
	return ans;
}

LL solve(int a[],int b[],int c[],int n,int m,int k)
{
	return min(calc(a,b,c,n,m,k),calc(a,c,b,n,k,m));
}

void solve()
{
	n=getint(),m=getint(),k=getint();
	rep(i,1,n) a[i]=getint();
	sort(a+1,a+1+n);
	rep(i,1,m) b[i]=getint();
	sort(b+1,b+1+m);
	rep(i,1,k) c[i]=getint();
	sort(c+1,c+1+k);
	ans=min(solve(a,b,c,n,m,k),min(solve(b,a,c,m,n,k),solve(c,a,b,k,n,m)));
	printf("%lld\n",ans);
}

int main()
{
	for(int _=getint(); _; --_) solve();
	return 0;
}