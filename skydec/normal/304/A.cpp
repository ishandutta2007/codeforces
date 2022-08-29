#include<stdio.h>
#include<math.h>
using namespace std;
long n;long ans;
int main()
{
	scanf("%ld",&n);ans=0;
	for(long a=1;a<=n;a++)
	for(long b=a;b<=n;b++)
	{
		long c=a*a+b*b;
		long k=(long)sqrt(c);
		if((k*k==c)&&(k<=n))ans++;
	}
	printf("%ld\n",ans);
	return 0;
}