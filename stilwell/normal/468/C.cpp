#include <stdio.h>
#include <stdlib.h>
using namespace std;

unsigned long long n,l,r,tmp;
int i;

unsigned long long mult(unsigned long long x,int y,unsigned long long z)
{
	unsigned long long ans=0;
	while(y)
	{
		if(y%2)ans=(ans+x)%z;
		x=(x+x)%z;
		y/=2;
	}
	return ans;
}

int main()
{
	scanf("%I64u",&n);
	l=1;r=10000000000000000000ll;
	tmp=45*19%n;
	for(i=1;i<=18;++i)tmp=mult(tmp,10,n);
	tmp=(tmp+1)%n;
	l+=n-tmp;r+=n-tmp;
	printf("%I64u %I64u\n",l,r);
}