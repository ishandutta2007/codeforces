#include <cstdio>
using namespace std;
int n,i,j,ans;
int a[2005];
int f[2][2005];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[0][i]=1;
	}
	ans=1;
	for (i=1;i<=n;i++)
		for (j=1;j<i;j++)
			if (a[i]==a[j]||a[j]==1)
			{
				if (f[0][j]+1>f[0][i])
					f[0][i]=f[0][j]+1;
				if (f[0][i]>ans)
					ans=f[0][i];
				if (f[1][j]+1>f[1][i])
					f[1][i]=f[1][j]+1;
				if (f[1][i]>ans)
					ans=f[1][i];
			}
			else
			{
				if (f[0][j]+1>f[1][i])
					f[1][i]=f[0][j]+1;
				if (f[1][i]>ans)
					ans=f[1][i];
			}
	printf("%d\n",ans);
	return 0;
}