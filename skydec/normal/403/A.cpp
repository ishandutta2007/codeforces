#include<stdio.h>
using namespace std;
long n,p,t;
int main()
{
	scanf("%ld",&t);
	for(long cases=1;cases<=t;cases++)
	{
		scanf("%ld%ld",&n,&p);p+=2*n;
		for(long i=1;(i<=n)&&p;i++)
		{
			for(long j=i+1;(j<=n)&&p;j++)
			{
				printf("%ld %ld\n",i,j);
				p--;
			}
		}
	}
	return 0;
}