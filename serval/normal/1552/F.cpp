#include <cstdio>
#include <algorithm>
using namespace std;
const int mod=998244353;
const int N=2e5+5;
int n;
int x[N],y[N],s[N],f[N],sf[N];
int ans;
int fd(int p)
{
	int l=1,r=n,mid;
	while (l<r)
	{
		mid=(l+r)>>1;
		if (x[mid]<p)
			l=mid+1;
		else
			r=mid;
	}
	return l;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&x[i],&y[i],&s[i]);
	for (int i=1;i<=n;i++)
	{
		f[i]=(x[i]-y[i])%mod;
		int j=fd(y[i]);
		f[i]=(f[i]+sf[i-1]-sf[j-1])%mod;
		if (f[i]<0)
			f[i]+=mod;
		sf[i]=(sf[i-1]+f[i])%mod;
	}
	ans=(x[n]+1)%mod;
	for (int i=1;i<=n;i++)
		if (s[i])
			ans=(ans+f[i])%mod;
	printf("%d\n",ans);
	return 0;
}