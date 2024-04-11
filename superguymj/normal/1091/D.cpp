#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=1000005,mod=998244353;
int n;
LL flv[N],inv[N],ans;

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

LL C(int ,int m)
{
	return n<m?0:flv[n]*inv[m]%mod*inv[n-m]%mod;
}

int main()
{
	scanf("%d",&n);
	flv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod,inv[i]=getmi(flv[i],mod-2);
	ans=flv[n];
	rep(i,2,n) ans=(ans+C(n,n-i+1)*(n-i)%mod*flv[i-1]%mod*(i-1))%mod;
	printf("%lld\n",ans);
	return 0;
}