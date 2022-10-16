#include <cstdio>
#include <algorithm>
using namespace std;
const int N=205;
const int oo=1e8;
int t;
int n,k;
int x[N],y[N];
int coef[N];
int f[N][N];
int ans;
void solve()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=2*n;i++)
		coef[i]=0;
	for (int i=1;i<=k;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if (x[i]>y[i])
			swap(x[i],y[i]);
		coef[x[i]]=1;
		coef[y[i]]=-1;
	}
	for (int i=1,j=k+1;i<=2*n&&j<=n;i++)
		if (coef[i]==0)
		{
			coef[i]=1;
			x[j]=i;
			j++;
		}
	for (int i=1,j=k+1;i<=2*n&&j<=n;i++)
		if (coef[i]==0)
		{
			coef[i]=-1;
			y[j]=i;
			j++;
		}
	ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			if (x[i]<x[j]&&x[j]<y[i]&&y[i]<y[j])
				ans++;
			if (x[j]<x[i]&&x[i]<y[j]&&y[j]<y[i])
				ans++;
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