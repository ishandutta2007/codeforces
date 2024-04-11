#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <complex>

using namespace std;

const double PI=acos(-1);
typedef complex<double> c_d;

double xp,yp,vp,x,y,v,r,R,leftc,rightc,midc;

bool equal(double a,double b)
{
	if (abs(a-b)<=1e-9) return true; else return false;
}

double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double dis2(double x1,double y1,double x2,double y2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double dian(double x1,double y1,double x2,double y2,double x3,double y3)
{
	x2-=x1;x3-=x1;
	y2-=y1;y3-=y1;
	return x2*x3+y2*y3;
}

double cha(double x1,double y1,double x2,double y2,double x3,double y3)
{
	x2-=x1;x3-=x1;
	y2-=y1;y3-=y1;
	return x2*y3-x3*y2;
}

bool inter(double x1,double y1,double x2,double y2,double r)
{
	if (dian(x1,y1,0,0,x2,y2)<0) return false;
	if (dian(x2,y2,0,0,x1,y1)<0) return false;
	double area=abs(cha(0,0,x1,y1,x2,y2));
	double h=area/dis(x1,y1,x2,y2);
	if ((h<r)||(equal(h,r))) return true; else return false;
}

pair<c_d,c_d> qie(double x,double y,double r)
{
	double lou=sqrt(dis2(x,y,0,0)-r*r);
	double lou2=dis(x,y,0,0);
	double chu=r/lou2;
	double theta=acos(chu);
	c_d qb(x,y);
	c_d qc(chu*cos(theta),chu*sin(theta));
	c_d qd((1/chu)*cos(theta),(1/chu)*sin(theta));
	qd=qb/qd;qc=qb*qc;
	//qd.real()-=x;qd.imag()-=y;
	//qc.real()-=x;qc.imag()-=y;
	return make_pair(qd,qc);
}

double dish(double x1,double y1,double x2,double y2,double r)
{
    double area=abs(cha(0,0,x1,y1,x2,y2));
    double h=area/r;
    double theta=asin(h/r);
    if (dian(0,0,x1,y1,x2,y2)<0) theta=PI-theta;
    return theta*r;
}

bool reach(double times)
{
	double t,evet,nowx,nowy,dist,angle;
	evet=2*PI*R/vp;
	t=times-floor(times/evet+(1e-10))*evet;
	c_d now(xp,yp);
	angle=2*PI*t/evet;
	c_d qiu(cos(angle),sin(angle));
	now*=qiu;
	nowx=now.real();nowy=now.imag();
	//cout<<now<<endl;
	//cout<<dis(nowx,nowy,xp,yp)<<endl;
	if (inter(x,y,nowx,nowy,r))
	{
		c_d o1,o2,o3,o4;
		pair<c_d,c_d> cs=qie(x,y,r);
		o1=cs.first;o2=cs.second;
		cs=qie(nowx,nowy,r);
		o3=cs.first;o4=cs.second;
		/*cout<<now<<endl;
		cout<<o1<<" "<<o2<<endl;
		cout<<o3<<" "<<o4<<endl;
		cout<<r<<endl;*/
		dist=dis(x,y,o1.real(),o1.imag())+dis(nowx,nowy,o3.real(),o3.imag());
		dist+=min(
				min(dish(o1.real(),o1.imag(),o3.real(),o3.imag(),r),
					dish(o1.real(),o1.imag(),o4.real(),o4.imag(),r)),
				min(dish(o2.real(),o2.imag(),o3.real(),o3.imag(),r),
					dish(o2.real(),o2.imag(),o4.real(),o4.imag(),r))
				 );
        //cout<<"P"<<endl;
	}
	else
		dist=dis(x,y,nowx,nowy);
	double e=v*times;
	return (e>dist)||(equal(e,dist));
}

int main()
{
	//freopen("C.in","r",stdin);
	cin>>xp>>yp>>vp;
	R=dis(xp,yp,0,0);
	cin>>x>>y>>v>>r;
	//cout<<reach(1.5)<<endl;return 0;
	leftc=0;rightc=1000000000;
	for (int i=1;i<=200;i++)
	{
		midc=(leftc+rightc)/2;
		if (reach(midc)) rightc=midc; else leftc=midc;
		//cout<<leftc<<" "<<rightc<<endl;
	}
	printf("%.10lf\n",midc);

	return 0;
}