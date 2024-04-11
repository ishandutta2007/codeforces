#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=255,mod=998244353;
int n,k;
LL flv[N],inv[N],f[N][N];

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

int main()
{
	scanf("%d%d",&n,&k);
	flv[0]=inv[0]=1;
	rep(i,1,n) flv[i]=flv[i-1]*i%mod,inv[i]=inv[i-1]*getmi(i,mod-2)%mod;
	f[k+1][0]=1;
	repd(i,k,1) rep(j,0,n-1) rep(x,0,n-1-j)
		f[i][j+x]=(f[i][j+x]+f[i+1][j]*inv[x]%mod*getmi(k-i+1,(n-1-j-x)*x+x*(x-1)/2))%mod;
	printf("%lld\n",f[1][n-1]*flv[n-1]%mod);
	return 0;
}