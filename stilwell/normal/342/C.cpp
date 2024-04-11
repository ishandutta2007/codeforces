#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int r,h,i,j,k,ans;
double lim;

int main()
{
	scanf("%d%d",&r,&h);
	ans=h/r*2;h%=r;
	if(h<r/2.0)++ans;
	else if(h<sqrt(3)/2*r)ans+=2;
		else ans+=3;
	printf("%d\n",ans);
}