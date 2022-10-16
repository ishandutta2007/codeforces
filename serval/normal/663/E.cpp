#include <cstdio>
using namespace std;
const int N=1048576;
int n,m;
int i,j,k,ans;
char a[25][N];
long long x,y,f[N],g[N];
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for (i=1;i<=m;i++)
	{
		j=0;
		for (k=1;k<=n;k++)
			j=(j<<1)^(a[k][i]-'0');
		f[j]++;
	}
	for (i=0;i<(1<<n);i++)
	{
		g[i]=__builtin_popcount(i);
		if (n-g[i]<g[i])
			g[i]=n-g[i];
	}
	for (i=2;i<=(1<<n);i<<=1)
		for (j=0;j<(1<<n);j+=i)
			for (k=0;k<(i>>1);k++)
			{
				x=f[j+k];
				y=f[j+k+(i>>1)];
				f[j+k]=x+y;
				f[j+k+(i>>1)]=x-y;
				x=g[j+k];
				y=g[j+k+(i>>1)];
				g[j+k]=x+y;
				g[j+k+(i>>1)]=x-y;
			}
	for (i=0;i<(1<<n);i++)
		f[i]*=g[i];
	for (i=2;i<=(1<<n);i<<=1)
		for (j=0;j<(1<<n);j+=i)
			for (k=0;k<(i>>1);k++)
			{
				x=f[j+k];
				y=f[j+k+(i>>1)];
				f[j+k]=(x+y)>>1;
				f[j+k+(i>>1)]=(x-y)>>1;
			}
	ans=n*m;
	for (i=0;i<(1<<n);i++)
		if (f[i]<ans)
			ans=f[i];
	printf("%d\n",ans);
	return 0;
}