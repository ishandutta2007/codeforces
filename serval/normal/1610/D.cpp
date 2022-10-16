#include <cstdio>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int n;
int a[N];
int ans;
int s[N];
int fac[N],inv[N];
int suf[N];
int fpw(int b,int e)
{
	if (e==0)
		return 1;
	int ret=fpw(b,e>>1);
	ret=1ll*ret*ret%mod;
	if (e&1)
		ret=1ll*ret*b%mod;
	return ret;
}
int C(int n,int m)
{
	if (m<0||m>n||n<0)
		return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[__builtin_ctz(a[i])]++;
	}
	fac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=fpw(fac[n],mod-2);
	for (int i=n;i;i--)
		inv[i-1]=1ll*inv[i]*i%mod;
	suf[32]=s[32];
	for (int i=31;i;i--)
		suf[i]=suf[i+1]+s[i];
	ans=1ll*(fpw(2,s[0])-1)*fpw(2,suf[1])%mod;
	for (int i=1;i<32;i++)
		for (int j=2;j<=s[i];j+=2)
			ans=(ans+1ll*C(s[i],j)*fpw(2,suf[i+1]))%mod;
	printf("%d\n",ans);
	return 0;
}