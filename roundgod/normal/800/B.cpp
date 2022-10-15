#include<bits/stdc++.h>
#define F first
#define S second
#define MAXN 1005
#define EPS 1e-3
using namespace std;
typedef pair<double,double> P;
int n,k;
P a[MAXN];
struct triplet
{
	double x0,y0,x1,y1,x2,y2;
}save[MAXN];
bool judge(triplet p,double d)
{
	if(p.x1==p.x2)
	{
		double dis=max(p.x1-p.x0,p.x0-p.x1);
		return (2*d-dis)<0;
	}
	else
	{
		double k=(p.y2-p.y1)/(p.x2-p.x1);
		double dis=(p.y0-k*p.x0+k*p.x1-p.y1)/(sqrt(k*k+1));
		dis=max(dis,-dis);
		return (2*d-dis)<0;
	}
}
bool C(double d)
{
	bool f=true;
	for(int i=0;i<n;i++)
		if(!judge(save[i],d)) f=false;
	return f;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf%lf",&a[i].F,&a[i].S);
	for(int i=0;i<n;i++)
	{
		save[i].x1=a[i].F;
		save[i].y1=a[i].S;
		save[i].x0=a[(i+1)%n].F;
		save[i].y0=a[(i+1)%n].S;
		save[i].x2=a[(i+2)%n].F;
		save[i].y2=a[(i+2)%n].S;
	}
	double lb=0,rb=2e9;
	for(int i=0;i<300;i++)
	{
		double mid=(lb+rb)/2;
		if(C(mid)) lb=mid; else rb=mid;
	}
	printf("%.10f",lb);
	return 0;
}