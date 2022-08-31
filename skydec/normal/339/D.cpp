#include<stdio.h>
#include<cmath>
using namespace std;
long sum[600000];
long dep[600000];
long n,m;
void down(long i)
{
	if((dep[i]&1)==(n&1))sum[i]=sum[i*2]|sum[i*2+1];
	else sum[i]=sum[i*2]^sum[i*2+1];
}
int main()
{
	scanf("%ld%ld",&n,&m);long q=(1<<(n))-1;
	dep[1]=1;
	for(long i=2;i<=2*q+1;i++)dep[i]=dep[i/2]+1;
	for(long i=1;i<=(q+1);i++)scanf("%ld",&sum[i+q]);
	for(long i=q;i>=1;i--)down(i);
	for(long i=1;i<=m;i++)
	{
		long p,b;scanf("%ld%ld",&p,&b);
		p+=q;sum[p]=b;p>>=1;
		while(p>=1)
		{
			down(p);
			p>>=1;
		}
		printf("%ld\n",sum[1]);
	}
	return 0;
}