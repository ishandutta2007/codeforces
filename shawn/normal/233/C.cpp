#include<cstdio>
#include<algorithm>
using namespace std;
int f[105],e[1005][1005],n,v;
int main()
{
	f[2]=0;
	for(int i=3;i<=100;i++)
	f[i]=f[i-1]+(i-1)*(i-2)/2;
	scanf("%d",&n);
	for(int i=100;i>=2;i--)
	if (f[i]<=n)
	{
		v=i;
		break;
	}
	n-=f[v];
	for(int i=1;i<=v;i++)
	for(int j=1;j<=v;j++)
	if (i!=j) e[i][j]=1;
	int i=v;
	while (n!=0)
	{
		while (i>=2&&n<(i*(i-1))/2) i--;
		n-=(i*(i-1))/2;
		v++;
		for(int j=1;j<=i;j++)
		e[j][v]=e[v][j]=1;
	}
	printf("%d\n",v);
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		putchar(e[i][j]+48);
		puts("");
	}
	return 0;
}