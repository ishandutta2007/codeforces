#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=200005,mod=998244353;
int n,k,mu[N];
LL ans,flv[N],inv[N],s[N];

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

LL get(int n)
{
	int m=min(n,k);
	LL ret=0;
	rep(i,0,m) ret=(ret+getmi(i,n)*inv[i]%mod*s[m-i])%mod;
	return ret-1;
}

int main()
{
	scanf("%d%d",&n,&k);
	if(n==1 || k==1) return puts("1"),0;
	mu[1]=1;
	rep(i,1,n)
		for(int j=i+i; j<=n; j+=i)
			mu[j]-=mu[i];
	flv[0]=1;
	rep(i,1,k) flv[i]=flv[i-1]*i%mod;
	inv[k]=getmi(flv[k],mod-2);
	repd(i,k,1) inv[i-1]=inv[i]*i%mod;
	s[0]=1;
	rep(i,1,k) s[i]=(s[i-1]+inv[i]*getmi(-1,i))%mod;
	rep(i,1,n)
		ans=(ans+mu[i]*get((n+i-1)/i))%mod;
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}