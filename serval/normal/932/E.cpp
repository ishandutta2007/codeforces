#include <cstdio>
using namespace std;
const int mod=1000000007;
const int K=5005;
int n,k,f,c;
int s[K][K],ans;
int fpw(int b,int e=mod-2)
{
	if (e<0) return 0;
	if (!e) return 1;
	int ret=fpw(b,e>>1);
	ret=1ll*ret*ret%mod;
	if (e&1) ret=1ll*ret*b%mod;
	return ret;
}
int main()
{
	scanf("%d%d",&n,&k);
	s[0][0]=1;
	for (int i=1;i<=k;i++)
		for (int j=1;j<=i;j++)
			s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
	f=c=1;
	for (int i=0;i<=k;i++)
	{
		ans=(ans+1ll*s[k][i]*f%mod*c%mod*fpw(2,n-i))%mod;
		f=1ll*f*(i+1)%mod;
		c=1ll*c*(n-i)%mod*fpw(i+1)%mod;
	}
	printf("%d\n",ans);
	return 0;
}