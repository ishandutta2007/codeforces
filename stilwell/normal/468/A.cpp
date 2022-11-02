#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k;
bool f;

int main()
{
	scanf("%d",&n);
	if(n<4)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	while(n>5)
	{
		printf("%d - %d = 1\n",n,n-1);
		if(f)printf("1 * 1 = 1\n");
		f=true;
		n-=2;
	}
	if(n==5)
	{
		printf("5 - 1 = 4\n");
		printf("4 - 2 = 2\n");
		printf("2 * 4 = 8\n");
		printf("3 * 8 = 24\n");
	}
	else
	{
		printf("1 * 2 = 2\n");
		printf("2 * 4 = 8\n");
		printf("3 * 8 = 24\n");
	}
	if(f)printf("24 * 1 = 24\n");
}