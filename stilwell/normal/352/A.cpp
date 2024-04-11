#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,n0,n5,i;

int main()
{
	scanf("%d",&n);
	for(;n;--n)
	{
		scanf("%d",&i);
		if(i==0)++n0;else ++n5;
	}
	n5-=n5%9;
	if(!n0)
	{
		printf("-1\n");
		return 0;
	}
	if(n5)
	{
		for(;n5;--n5)printf("5");
		for(;n0;--n0)printf("0");
	}
	else
	{
		printf("0");
	}
	printf("\n");
}