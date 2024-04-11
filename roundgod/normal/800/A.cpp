#include<bits/stdc++.h>
#define MAXN 100005
#define eps 1e-8
using namespace std;
double n,p;
double a[MAXN],b[MAXN];
bool C(double x)
{
	double s=x*p;
	for(int i=0;i<n;i++)
		if(a[i]-x*b[i]<0) s-=(x*b[i]-a[i]);
	return s>=0;
}
int main()
{
	scanf("%lf%lf",&n,&p);
	double s=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&b[i],&a[i]);
		s+=b[i];
	}
	if(s<=p)
	{
		printf("-1\n");
		return 0;
	}
	double lb=0,rb=1e10+1;
	for(int i=0;i<300;i++)
	{
		double mid=(lb+rb)/2;
		if(C(mid)) lb=mid; else rb=mid;
	}
	printf("%.10f",lb);
	return 0;
}