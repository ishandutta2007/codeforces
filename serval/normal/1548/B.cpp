#include <cstdio>
using namespace std;
const int N=2e5+5;
int t;
int n;
long long a[N],b[N];
long long f[19][N];
long long gcd(long long a,long long b)
{
	if (a%b==0)
		return b;
	return gcd(b,a%b);
}
long long cal(int l,int r)
{
	int x=0;
	while ((1<<(x+1))<=(r-l+1))
		x++;
	return gcd(f[x][l],f[x][r-(1<<x)+1]);
}
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if (n==1)
	{
		printf("1\n");
		return;
	}
	for (int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
		if (b[i]<0)
			b[i]=-b[i];
	}
	n--;
	for (int i=1;i<=n;i++)
		f[0][i]=b[i];
	for (int i=1;i<=18;i++)
	{
		int t=(1<<i);
		for (int j=1;j<=n-t+1;j++)
			f[i][j]=gcd(f[i-1][j],f[i-1][j+t/2]);
	}
	int ans=1;
	for (int i=1;i<=n;i++)
	{
		if (b[i]<2)
			continue;
		int r=i;
		for (int j=18;j>=0;j--)
		{
			int t=r+(1<<j);
			if (t>n)
				continue;
			if (cal(i,t)>=2)
				r=t;
		}
		if (r-i+2>ans)
			ans=r-i+2;
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