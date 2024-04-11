#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		if(i==j)printf("%d ",m);
		else printf("0 ");
		printf("\n");
	}
}