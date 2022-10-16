#include <cstdio>
using namespace std;
const int mod=998244353;
const int N=4005;
const int K=2005;
int n,k,l;
int fac,ans;
int f[N][K][2];
int fpw(int b,int e=mod-2)
{
	if (!e)
		return 1;
	int ret=fpw(b,e>>1);
	ret=1ll*ret*ret%mod;
	if (e&1)
		ret=1ll*ret*b%mod;
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&k,&l);
	f[0][0][0]=1;
	for (int i=1;i<=2*n+1;i++)
		for (int j=0;j<=n;j++)
			for (int x=0;x<=1;x++)
				if (f[i-1][j][x])
				{
					if (j)
						f[i][j-1][x]=(f[i][j-1][x]+1ll*f[i-1][j][x]*j)%mod;
					if (i+j-1<2*n+x)
						f[i][j+1][x]=(f[i][j+1][x]+f[i-1][j][x])%mod;
					if (j>=k&&!x)
						f[i][j][1]=(f[i][j][1]+f[i-1][j][x])%mod;
				}
	fac=1;
	for (int i=n+1;i<=2*n+1;i++)
		fac=1ll*fac*i%mod;
	ans=f[2*n+1][0][1];
	ans=1ll*ans*fpw(2,n)%mod;
	ans=1ll*ans*fpw(fac)%mod*l%mod;
	printf("%d\n",ans);
	return 0;
}