#include <cstdio>
using namespace std;
int n,a,b;
int x,y;
int i,j;
int p[1000005];
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	if (a<b)
		a^=b^=a^=b;
	for (x=0;a*x<=n;x++)
		if ((n-a*x)%b==0)
		{
			y=(n-a*x)/b;
			break;
		}
	if (x*a>n)
	{
		printf("-1\n");
		return 0;
	}
	while (x--)
	{
		i++;
		if (a==1)
			p[i]=i;
		else
		{
			for (j=i;j<i+a-1;j++)
				p[j]=j+1;
			p[i+a-1]=i;
		}
		i=i+a-1;
	}
	while (y--)
	{
		i++;
		if (b==1)
			p[i]=i;
		else
		{
			for (j=i;j<i+b-1;j++)
				p[j]=j+1;
			p[i+b-1]=i;
		}
		i=i+b-1;
	}
	for (i=1;i<=n;i++)
		printf(i==n?"%d\n":"%d ",p[i]);
	return 0;
}