#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,x,y;

int main()
{
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		if(m==0)printf("1\n");
		else printf("-1\n");
		return 0;
	}
	m-=n/2-1;
	if(m<=0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d %d ",m,2*m);
	x=n/2-1;
	y=n%2;
	for(i=1;x;i+=2)
	if(i!=m&&i!=m*2&&i+1!=m&&i+1!=m*2)
	{
		printf("%d %d ",i,i+1);
		--x;
	}
	if(y)printf("1000000000 ");
	printf("\n");
}