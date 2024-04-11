#include <cstdio>
using namespace std;
int n,m,i,j,k;
int a[105];
int val[105];
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		val[a[i]]++;
	}
	for (i=10000;i>0;i--)
	{
		j=0;
		for (k=1;k<=100;k++)
			j+=val[k]/i;
		if (j>=n)
			break;
	}
	printf("%d\n",i);
	return 0;
}