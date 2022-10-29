#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=200005,mod=1000000007;
int n,m,x;
LL flv[N],inv[N],ans,sum;

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

void prepare()
{
	flv[0]=inv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod,inv[i]=getmi(flv[i],mod-2);
}

LL C(int n,int m)
{
	return n>=m?flv[n]*inv[m]%mod*inv[n-m]%mod:0;
}

LL S(int n,int m)
{
	if(n<m) return 0;
	LL rt=0;
	rep(i,0,m)
		if(i&1) rt=(rt-C(m,i)*getmi(m-i,n))%mod;
		else rt=(rt+C(m,i)*getmi(m-i,n))%mod;
	rt=rt*inv[m]%mod;
	return (rt+mod)%mod;
}

int main()
{
	scanf("%d%d",&n,&m);
	prepare();
	ans=(S(n-1,m)*(n+m-1)+S(n-1,m-1))%mod;
	rep(i,1,n) scanf("%d",&x),sum=(sum+x)%mod;
	printf("%lld\n",ans*sum%mod);
	return 0;
}