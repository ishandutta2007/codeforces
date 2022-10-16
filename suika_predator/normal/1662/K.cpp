#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
const double r60=acos(-1)/3;
double x[5],y[5];
namespace solve
{
	double x0,y0;
	double dis(double a,double b,double c,double d)
	{
		return hypot(a-c,b-d);
	}
	double fermat(double a,double b,double c,double d,double e,double f)
	{
		double dx=c-a,dy=d-b;
		double dx2=e-a,dy2=f-b;
		if(dx*dy2-dy*dx2>0)swap(c,e),swap(d,f),swap(dx,dx2),swap(dy,dy2);
		double tx=dx*cos(r60)-dy*sin(r60),ty=dx*sin(r60)+dy*cos(r60);
		return dis(a+tx,b+ty,e,f);
	}
	double checkdeg(double A,double B,double C)
	{
		return acos((A*A+B*B-C*C)/(2*A*B))<=2*r60;
	}
	double getdis(double x2,double y2,double x3,double y3)
	{
		double A=dis(x0,y0,x2,y2),B=dis(x0,y0,x3,y3),C=dis(x2,y2,x3,y3);
		double ans;
		if(checkdeg(A,B,C) and checkdeg(B,C,A) and checkdeg(C,A,B))ans=fermat(x0,y0,x2,y2,x3,y3);
		else ans=min({A+B,A+C,B+C});
		return ans;
	}
	double check()
	{
		double ans=max({getdis(x[1],y[1],x[2],y[2]),getdis(x[1],y[1],x[3],y[3]),getdis(x[2],y[2],x[3],y[3])});
//		cerr<<"check "<<x0<<' '<<y0<<' '<<ans<<endl;
		return ans;
	}
	double fucky0(double l,double r)
	{
		while(r-l>eps)
		{
			y0=l+(r-l)/111*55;
			double cml=check();
			y0=l+(r-l)/111*56;
			double cmr=check();
			if(cml<cmr)r=l+(r-l)/111*56;
			else l=l+(r-l)/111*55;
		}
		y0=(l+r)/2;
		return check();
	}
	double fuckx0(double l,double r)
	{
		while(r-l>eps)
		{
//			cerr<<l<<' '<<r<<endl;
			x0=l+(r-l)/111*55;
			double cml=fucky0(-10000,10000);
//			cerr<<"gety0~l "<<y0<<endl;
			x0=l+(r-l)/111*56;
			double cmr=fucky0(-10000,10000);
//			cerr<<"gety0~r "<<y0<<endl;
			if(cml<cmr)r=l+(r-l)/111*56;
			else l=l+(r-l)/111*55;
		}
		x0=(l+r)/2;
		return fucky0(-10000,10000);
	}
}
int main()
{
	for(int i=1;i<=3;i++)cin>>x[i]>>y[i];
	cout<<fixed<<setprecision(9)<<solve::fuckx0(-10000,10000)<<endl;
//	cerr<<solve::x0<<' '<<solve::y0<<endl;
	return 0;
}