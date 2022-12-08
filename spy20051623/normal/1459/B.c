#include<stdio.h>
#include<math.h>
main()
{
	int n;
	long long re;
	scanf("%d",&n);
	if(n%2)re=(n+1)*(n+3)/2;
	else re=pow(n/2+1,2);
	printf("%lld",re);
}