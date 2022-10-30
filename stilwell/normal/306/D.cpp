#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int n,i,j,k;
double now,a,x,y,l;

int main()
{
	scanf("%d",&n);
	if(n<5){printf("No solution\n");return 0;}
	a=2*acos(-1)/n;
	l=100;
	for(i=1;i<n;++i)
	{
		if(i!=1)
		{
			now+=a;
			x+=l*cos(now);
			y+=l*sin(now);
			l+=0.002;
		}
		printf("%lf %lf\n",x,y);
	}
	now+=a;
	printf("%lf 0\n",x-y/tan(now));
}