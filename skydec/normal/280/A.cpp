#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	double za,zb,zc;
	scanf("%lf%lf%lf",&za,&zb,&zc);
	if(zc>90.0)
	{
		zc=180.0-zc;
	}
	if(za<zb)
	{
		swap(za,zb);
	}
	if(zc==90.0)
	{
		printf("%lf\n",zb*zb);
		return 0;
	}
	zc/=180.0;
	zc*=3.14159265358979323846264338327950288;
	if((1.0+cos(zc))/za<(sin(zc))/zb)
	{
		printf("%lf\n",zb*zb*(1.0/sin(zc)));
	}
	else
	{
		double pl=(za+zb)*sin(zc)/(1.0+cos(zc)+sin(zc));
		double x=(za-pl)/(1+cos(zc)-sin(zc));
		double y=(zb-pl)/(1+cos(zc)-sin(zc));
		printf("%lf\n",za*zb-(x*x+y*y)*cos(zc)*sin(zc));
	}
}