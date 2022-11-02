#include<cmath>
#include<cstdio>

#define pi acos(-1.0)

using namespace std;

int n;
double len,x,y,deltajd,jd;

int main()
{
	scanf("%d",&n);
	if(n<=4)return puts("No solution"),0;
	len=100.0;
	x=0.000;
	y=0.000;
	deltajd=2.*pi/n;
	jd=0.000;
	for(int i=1;i<=n-1;i++)
	{
		printf("%.5lf %.5lf\n",x,y);
		if(i==n-1)break;
		jd+=deltajd;
		x+=len*cos(jd);
		y+=len*sin(jd);
		len+=0.002;
	}
	jd+=deltajd;
	printf("%.5lf %.5lf",x-y/tan(jd),0.0);
}