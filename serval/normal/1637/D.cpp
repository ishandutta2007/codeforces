#include <cstdio>
#include <algorithm>
using namespace std;
const int N=105;
const int C=1e4+5;
int n;
int a[N],b[N];
bool f[N][C];
long long ans,s;
void solve()
{
	scanf("%d",&n);
	s=0;
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
		s+=a[i]+b[i];
	ans=1e18;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=n*100;j++)
			f[i][j]=0;
	f[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=n*100;j>=0;j--)
		{
			if (j>=a[i])
				f[i][j]|=f[i-1][j-a[i]];
			if (j>=b[i])
				f[i][j]|=f[i-1][j-b[i]];
		}
	for (int i=0;i<=n*100;i++)
		if (f[n][i])
			ans=min(ans,1ll*i*i+1ll*(s-i)*(s-i));
	for (int i=1;i<=n;i++)
	{
		ans+=1ll*(n-2)*a[i]*a[i];
		ans+=1ll*(n-2)*b[i]*b[i];
	}
	printf("%lld\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}