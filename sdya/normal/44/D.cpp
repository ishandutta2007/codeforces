#include <iostream>
#include <set>
#include <string>
#include <string.h>
#include <cstring>
#include <math.h>

using namespace std;

double res = 1e30;
double x[6000], y[6000], z[6000];
int n;

double dist(double x1, double y1, double z1, double x2, double y2, double z2)
{
	double A = (x1-x2)*(x1-x2);
	double B = (y1-y2)*(y1-y2);
	double C = (z1-z2)*(z1-z2);
	return sqrt(A+B+C);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
	for (int i = 2; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
		{
			double d = dist(x[i],y[i],z[i],x[j],y[j],z[j]);
			double d1 = dist(x[1],y[1],z[1],x[i],y[i],z[i]);
			double d2 = dist(x[1],y[1],z[1],x[j],y[j],z[j]);
			if (d1 > d2) swap(d1, d2);
			double x = d2 - d1;
			int t = (int)(x / d);
			if (t % 2 == 0)
			{
				double add = d - (x - (double)(t) * d);
				res = min(res, d2 + add / 2.0);
			} else
			{
				double add = d + (x - (double)(t) * d);
				res = min(res, d2 + add / 2.0);
			}
		}
	printf("%.10lf\n", res);
	return 0;
}