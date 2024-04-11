#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long n,m;

int main()
{
	scanf("%I64d",&n);
	while(n%3==0)n/=3;
	n/=3;
	for(m=1;n/m>=3;m*=3);
	if(n==0)printf("1\n");
	else printf("%I64d\n",n+1);
}