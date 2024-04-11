#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n/2;++j)
		++k,printf("%d %d ",k,n*n-k+1);
		printf("\n");
	}
}