#include <cstdio>
using namespace std;
int i,j,s,k;
int f[1000005];
int g[10][1000005];
int main()
{
	for (i=1;i<=9;i++)
		f[i]=i;
	for (i=10;i<=1000000;i++)
	{
		j=i;
		s=1;
		while (j)
		{
			if (j%10)
				s=s*(j%10);
			j/=10;
		}
		f[i]=f[s];
	}
	for (i=1;i<=1000000;i++)
		g[f[i]][i]=1;
	for (i=1;i<=1000000;i++)
		for (j=1;j<=9;j++)
			g[j][i]=g[j][i-1]+g[j][i];
	scanf("%d",&i);
	while (i--)
	{
		scanf("%d%d%d",&j,&s,&k);
		printf("%d\n",g[k][s]-g[k][j-1]);
	}
	return 0;
}