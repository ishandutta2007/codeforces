#include <cstdio>
using namespace std;
const int maxn=300005;
int n,i,j,s,m,b;
long long v,ans;
int c[2][maxn];
int a[maxn];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%lld",&v);
		a[i]=__builtin_popcount(v&0xffffffff)+__builtin_popcount(v>>32);
	}
	b=0;
	for (i=1;i<=n;i++)
	{
		b^=a[i]&1;
		s=0;
		m=0;
		for (j=i;j>=1;j--)
		{
			s+=a[j];
			if (s>=128)
				break;
			if (a[j]>m)
				m=a[j];
			if ((s&1)==0&&s>=2*m)
				ans++;
		}
		ans+=c[b][j];
		c[b^(a[i]&1)][i]++;
		c[0][i]+=c[0][i-1];
		c[1][i]+=c[1][i-1];
	}
	printf("%lld\n",ans);
	return 0;
}