#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
double x[2333],y[2333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
	}
	x[0]=x[n],y[0]=y[n];
	x[n+1]=x[1],y[n+1]=y[1];
	double minn=2e9;
	for(int i=1;i<=n;i++)
	{
		double S=-0.5*(x[i-1]*y[i]+x[i]*y[i+1]+x[i+1]*y[i-1]-x[i-1]*y[i+1]-x[i]*y[i-1]-x[i+1]*y[i]);
		double h=S/sqrt((x[i-1]-x[i+1])*(x[i-1]-x[i+1])+(y[i-1]-y[i+1])*(y[i-1]-y[i+1]));
//		cout<<i<<' '<<S<<' '<<h<<endl;
		minn=min(minn,h);
	}
	printf("%.9lf",minn);
	return 0;
}