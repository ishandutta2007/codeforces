// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	double h,m,a1=0,a2=0;
	scanf("%lf:%lf",&h,&m);
	if ( h>=12 ) h-=12;
	a2=360.0*m/60;
	a1+=a2/360*30;
	a1+=360*h/12;
	printf("%.9f %.9f\n",a1,a2);
	return 0;
}