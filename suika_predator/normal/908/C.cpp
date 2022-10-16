#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

#define sqr(x) ((x)*(x))
int n,r;
double x[2333],y[2333];
const double eps=1e-13;
int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&x[i]);
		y[i]=r;
		for(int j=1;j<i;j++)
		{
			if(abs(x[i]-x[j])<=2*r+eps)
			{
				y[i]=max(y[i],y[j]+sqrt(4.0*r*r-sqr(abs(x[i]-x[j]))));
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%.9lf ",y[i]);
	return 0;
}