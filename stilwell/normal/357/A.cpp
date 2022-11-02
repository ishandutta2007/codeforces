#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,x,y,i,j,k,sum;
int a[105];

int main()
{
	scanf("%d",&m);
	for(i=1;i<=m;++i)scanf("%d",&a[i]),n+=a[i];
	scanf("%d%d",&x,&y);
	for(i=1;i<=m;++i)
	{
		if(sum>=x&&sum<=y&&n-sum>=x&&n-sum<=y)
		{
			printf("%d\n",i);
			return 0;
		}
		sum+=a[i];
	}
	printf("0\n");
}