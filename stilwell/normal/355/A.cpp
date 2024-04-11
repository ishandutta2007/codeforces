#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;

int main()
{
	scanf("%d%d",&n,&m);
	if(m==0&&n>1)
	{
		printf("No solution\n");
		return 0;
	}
	if(n==1)printf("%d\n",m);
	else
	{
		printf("1");--m;
		for(n-=2;n;--n)printf("0");
		printf("%d\n",m);
	}
}