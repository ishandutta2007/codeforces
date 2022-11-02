#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long k,b,n,t,x,y,z;

int main()
{
	scanf("%I64d%I64d%I64d%I64d",&k,&b,&n,&t);
	if(k==1)
	{
		x=1+n*b-t;
		x=x/b+(x%b!=0);
		if(x<0)x=0;
		printf("%I64d\n",x);
	}
	else
	{
		x=b;z=k;y=b;
		while(y+z<=t)
		{
			z*=k;
			x*=k;
			y+=x;
			--n;
		}
		if(n<0)n=0;
		printf("%I64d\n",n);
	}
}