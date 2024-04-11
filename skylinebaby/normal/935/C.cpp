#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
	double R,x,y,u,v;
	scanf("%lf %lf %lf %lf %lf",&R,&x,&y,&u,&v);
	double t = x - u;
	double s = y - v;
	double p = t * t;
	double q = s * s;
	double z = pow(p+q,0.5);
	double r = (z + R) / 2;
	if (z>=R) 
	{
		printf("%.8lf %.8lf %.8lf\n",x,y,R);
		return 0;		
	}
	if (t==0&&s==0)
	{
		double qw = R / 2;
		printf("%.8lf %.8lf %.8lf\n",x+qw,y,qw);
		return 0;		
	} 
	double e = t * (r/z) + u;
	double f = s * (r/z) + v;
	printf("%.8lf %.8lf %.8lf\n",e,f,r);
	return 0;
}