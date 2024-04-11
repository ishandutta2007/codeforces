#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long n,x,y,i,j,k;

int main()
{
	scanf("%I64d%I64d%I64d",&n,&x,&y);
	if(y<n||n-1+(y-n+1)*(y-n+1)<x)printf("-1\n");
	else
	{
		printf("%I64d\n",y-n+1);
		for(i=1;i<n;++i)printf("1\n");
	}
}