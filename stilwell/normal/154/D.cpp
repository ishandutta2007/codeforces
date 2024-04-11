#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

long long d,x1,x2,xx1,xx2,a,b,i,j,k;
bool wei;

int main()
{
	scanf("%I64d%I64d%I64d%I64d",&x1,&x2,&a,&b);
	xx1=x1;xx2=x2;
	if(x1>x2)x1=-x1,x2=-x2,a=-a,b=-b,swap(a,b),wei=true;
	d=x2-x1;
	if(a<=0)
	{
		if(d<=b)printf("FIRST\n%I64d\n",xx2);
		else printf("DRAW\n");
	}
	else
	{
		d%=(a+b);
		if(d==0)printf("SECOND\n");
		else if(d>=a&&d<=b)
		{
			if(wei)printf("FIRST\n%I64d\n",xx1-d);
			else printf("FIRST\n%I64d\n",xx1+d);
		}
		else printf("DRAW\n");
	}
}