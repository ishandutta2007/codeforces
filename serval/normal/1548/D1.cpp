#include <cstdio>
using namespace std;
const int N=6005;
int n;
int x[N],y[N];
int tx[N],ty[N];
int p[2][2][2];
long long ans;
int gcd(int x,int y)
{
	if (x==0||y==0)
		return x+y;
	if (x%y==0)
		return y;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;i++)
	{
		for (int x=0;x<=1;x++)
			for (int y=0;y<=1;y++)
				for (int z=0;z<=1;z++)
					p[x][y][z]=0;
		for (int j=1;j<=n;j++)
			if (i!=j)
			{
				tx[j]=(x[j]-x[i])/2;
				ty[j]=(y[j]-y[i])/2;
				if (tx[j]<0)
					tx[j]=-tx[j];
				if (ty[j]<0)
					ty[j]=-ty[j];
				p[gcd(tx[j],ty[j])&1][tx[j]&1][ty[j]&1]++;
			}
		for (int x=0;x<=1;x++)
			for (int y=0;y<=1;y++)
				for (int z=0;z<=1;z++)
					ans+=p[x][y][z]*(p[x][y][z]-1)/2*(2*x+1);
	}
	printf("%lld\n",ans/3);
	return 0;
}