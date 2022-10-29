#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=305,mod=1000000007;
typedef long long LL;
int n,a[N],tp,tot;
LL f[2][N],flv[N],inv[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int query(int x)
{
	for(int i=2; i*i<=x; ++i)
		while(x%(i*i)==0) x/=i*i;
	return x;
}

LL getmi(LL a,LL x)
{
	LL rt=1;
	while(x)
	{
		if(x&1) rt=rt*a%mod;
		a=a*a%mod,x>>=1;
	}
	return rt;
}

LL C(int n,int m)
{
	return n<m?0:flv[n]*inv[m]%mod*inv[n-m]%mod;
}

void prepare()
{
	flv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod;
	inv[n]=getmi(flv[n],mod-2);
	repd(i,n,1) inv[i-1]=inv[i]*i%mod;
}

void inc(LL &x,LL y)
{	
	x=(x+y)%mod;
}

void ins(int x)
{
	tp^=1,memset(f[tp],0,sizeof(f[tp]));
	rep(i,0,tot) rep(j,1,x)
	{
		LL tmp=C(x-1,j-1)*flv[x]%mod*f[tp^1][i]%mod;
		rep(k,0,min(i,j)) inc(f[tp][i-k+x-j],tmp*C(i,k)%mod*C(tot+1-i,j-k));
	}
	tot+=x;
}

int main()
{
	n=getint();
	prepare();
	rep(i,1,n)
		a[i]=query(getint());
	sort(a+1,a+1+n);
	int p=1;
	f[0][0]=1;
	while(p<=n)
	{
		int q=p;
		while(q+1<=n && a[q+1]==a[p]) ++q;
		ins(q-p+1),p=q+1;
	}
	printf("%lld\n",f[tp][0]);
	return 0;
}