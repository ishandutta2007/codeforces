#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=5005,mod=1000000007;
int n,k;
typedef long long LL;
LL s[N][N],ans,inv[N];

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

LL C(int x)
{
	if(x>n) return 0;
	LL rt=1;
	rep(i,n-x+1,n) rt=rt*i%mod;
	return rt*inv[x]%mod;
}

int main()
{
	scanf("%d%d",&n,&k);
	LL flv=1,m=getmi(2,n),inv2=(mod+1)/2;
	rep(i,0,k) s[i][i]=1,inv[i]=getmi(i,mod-2);
	inv[0]=1;
	rep(i,1,k) inv[i]=inv[i-1]*inv[i]%mod;
	rep(i,1,k) rep(j,1,i-1) s[i][j]=(s[i-1][j]*j+s[i-1][j-1])%mod;
	rep(i,1,k)
	{
		flv=flv*i%mod,m=m*inv2%mod;
		ans=(ans+flv*s[k][i]%mod*m%mod*C(i))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}