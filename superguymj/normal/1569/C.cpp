#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
 
using namespace std;
typedef long long LL;
const int N=200005,mod=998244353;
int n,a[N];
LL flv[N],inv[N];
 
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
	return flv[n]*inv[m]%mod*inv[n-m]%mod;
}
 
void solve()
{
	scanf("%d",&n);
	int mx1=0,mx2=0;
	rep(i,1,n)
	{
		scanf("%d",&a[i]);
		if(a[i]>mx1) mx2=mx1,mx1=a[i];
		else if(a[i]>mx2) mx2=a[i];
	}
	flv[0]=inv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod,inv[i]=getmi(flv[i],mod-2);
	if(mx1==mx2) printf("%lld\n",flv[n]);
	else if(mx1==mx2+1)
	{
		int cnt=0;
		rep(i,1,n) if(a[i]==mx2) ++cnt;
		printf("%lld\n",flv[cnt]*cnt%mod*C(n,cnt+1)%mod*flv[n-cnt-1]%mod);
	}
	else puts("0");
}
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}