#include <cstdio>
using namespace std;
int n,i,j;
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i<<=1)
	{
		if (i<=n&&i+(i/2)>n)
		{
			printf("%d\n",i);
			continue;
		}
		if (i+(i/2)<=n&&i*2>n)
		{
			printf("%d\n",i+(i/2));
			continue;
		}
		for (j=1;j<=(n/i+1)/2;j++)
			printf("%d ",i);
	}
	return 0;
}