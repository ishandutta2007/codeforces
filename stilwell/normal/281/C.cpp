#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

double ans,w,h,l,pi,a,p;
int i,j,k,tot;
double a1,a2,b1,b2,tmp;

struct node
{
	double x,y;
	double d;
}t[100];

double change(double a){return a/180*pi;}

// kx+b= h  ->  x=(h-b)/k
// kx+b= -h ->  x=(-h-b)/k
// kw+b= y  ->  y=kw+b
//-kw+b= y  ->  y=-kw+b

void check()
{
	if(t[tot].x<-w){--tot;return;}
	if(t[tot].x>w){--tot;return;}
	if(t[tot].y<-h){--tot;return;}
	if(t[tot].y>h){--tot;return;}
}

void work(double x,double y)
{
	double z,b,xx,yy,k;
	z=sqrt(x*x+y*y);
	b=atan(y/x);
	if(b<0)b=-b;
	xx=z/cos(b);
	yy=z/cos(pi/2-b);
	if(x<0)xx=-xx;
	if(y<0)yy=-yy;
	k=-yy/xx;
	t[++tot].x=(h-yy)/k;
	t[tot].y=h;
	check();
	t[++tot].x=(-h-yy)/k;
	t[tot].y=-h;
	check();
	t[++tot].x=w;
	t[tot].y=k*w+yy;
	check();
	t[++tot].x=-w;
	t[tot].y=-k*w+yy;
	check();
}

inline bool cmp(const node &a,const node &b){return a.d<b.d;}

int main()
{
	//freopen("rect.in","r",stdin);
	//freopen("rect.out","w",stdout);
	scanf("%lf%lf%lf",&w,&h,&a);
	w/=2;h/=2;
	if(a==0||a==180)
	{
		printf("%.9lf\n",w*h*4);
		return 0;
	}
	if(a==90)
	{
		if(w<h)printf("%.9lf\n",w*w*4);
		else printf("%.9lf\n",h*h*4);
		return 0;
	}
	pi=3.1415926535;
	a=change(a);
	a1=w*cos(a);
	b1=sqrt(w*w-a1*a1);
	if(a1<0)b1=-b1;
	if(a>pi/2)a1=-a1;
	a2=h*cos(a);
	b2=sqrt(h*h-a2*a2);
	if(a2<0)b2=-b2;
	if(a>pi/2)a2=-a2;
	swap(a2,b2);
	a2=-a2;
	work(a1,b1);
	work(a2,b2);
	work(-a1,-b1);
	work(-a2,-b2);
	for(i=1;i<=tot;++i)t[i].d=atan2(t[i].x,t[i].y);
	sort(t+1,t+tot+1,cmp);
	t[tot+1].x=t[1].x;
	t[tot+1].y=t[1].y;
	for(i=1;i<=tot;++i)
	{
		tmp=t[i].x*t[i+1].y-t[i+1].x*t[i].y;
		if(tmp<0)tmp=-tmp;
		tmp/=2;
		ans+=tmp;
	}
	printf("%.9lf\n",ans);
}