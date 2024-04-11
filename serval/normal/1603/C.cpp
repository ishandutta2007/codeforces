#include <cstdio>
using namespace std;
const int N=1e5+5;
const int mod=998244353;
int t;
int n;
int a[N];
int f[N],c[N],s[N],cnt;
int g[N],gc[N],gs[N],tcnt;
bool gv[N];
int ans;
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=0;
	cnt=0;
	for (int i=n;i;i--)
	{
		for (int j=1;j<=cnt;j++)
		{
			int k=(a[i]+f[j]-1)/f[j];
			int v=a[i]/k;
			if (!gv[v])
			{
				g[++tcnt]=v;
				gv[v]=1;
			}
			gc[v]=(gc[v]+c[j]+1ll*s[j]*(k-1)%mod)%mod;
			gs[v]=(gs[v]+s[j])%mod;
		}
		cnt=0;
		for (int j=1;j<=tcnt;j++)
		{
			int cur=g[j];
			gv[cur]=0;
			cnt++;
			f[cnt]=cur;
			c[cnt]=gc[cur];
			ans=(ans+c[cnt])%mod;
			s[cnt]=gs[cur];
			gc[cur]=0;
			gs[cur]=0;
		}
		tcnt=0;
		cnt++;
		f[cnt]=a[i];
		c[cnt]=0;
		s[cnt]=1;
	}
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&t);
	while (t--)
		solve();
	return 0;
}