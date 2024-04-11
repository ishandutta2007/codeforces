#include<stdio.h>
using namespace std;
long n,m;
int main()
{
	scanf("%ld%ld",&n,&m);
	if(m==3)
	{
		if(n==4)printf("0 0\n3 0\n0 3\n1 1\n");
		else if(n==3)printf("0 0\n3 0\n2 5\n");
		else printf("-1\n");
		return 0;
	}
	if(m&1)
	for(long i=1;i<=m;i++)
	printf("%ld %ld\n",((i-1)/2+1)*((i&1)?-1:1),((i-1)/2+1)*((i-1)/2+1)*13);
	else
	for(long i=1;i<=m;i++)
	printf("%ld %ld\n",((i-1)/2+1)*((i&1)?-1:1),((i-1)/2+1)*((i-1)/2+1));
	for(long i=1;i<=n-m;i++)
	printf("%ld %ld\n",((i-1)/2+1)*((i&1)?-1:1),-((i-1)/2+1)*((i-1)/2+1)*17-10086);
	return 0;
}