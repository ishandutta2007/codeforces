#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,c;

int main()
{
	scanf("%d",&n);
	if(n&1){printf("-1\n");return 0;}
	n/=2;
	for(i=1;i<=n;++i)
	{
		c=0;
		for(j=1;j<=n;++j)
		{
			c^=1;
			for(k=1;k<=n;++k)if(c^(k&1))printf("ww");else printf("bb");printf("\n");
			for(k=1;k<=n;++k)if(c^(k&1))printf("ww");else printf("bb");printf("\n");
		}
		printf("\n");
		c=1;
		for(j=1;j<=n;++j)
		{
			c^=1;
			for(k=1;k<=n;++k)if(c^(k&1))printf("ww");else printf("bb");printf("\n");
			for(k=1;k<=n;++k)if(c^(k&1))printf("ww");else printf("bb");printf("\n");
		}
		printf("\n");
	}
}