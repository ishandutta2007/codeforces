#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll N=2050;
const ld eps=1e-10,inf=1e9;
struct Point{ld x,y;};
struct Line{Point u,d;};
const Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
const Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
const Point operator *(ld a,Point b){return (Point){a*b.x,a*b.y};}
const ld operator *(Point a,Point b){return a.x*b.x+a.y*b.y;}
ld LEN(Point a){return sqrt(a.x*a.x+a.y*a.y);}
ld cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
Point itr(Line a,Line b)
{
	ld xs=cross(b.u-a.u,b.d)/cross(a.d,b.d);
	return a.u+xs*a.d;
}
ll n,m;
Point P,Q;
Point p[N],q[N],h[10];
bool check(Point a1,Point a2,Point b1,Point b2)
{
	Point S,t1,t2,bp;
	ld dmi,dmx;
	ll i;
	bool pd;
	dmi=inf;dmx=-inf;
	b1=2.0*Q-b1;b2=2.0*Q-b2;
	if(a1.x>a2.x) swap(a1,a2);
	if(b1.x>b2.x) swap(b1,b2);
	S=b1-Q+a1;
	t1=a2-a1;t2=b2-b1;
	if(cross(t1,t2)<0) swap(t1,t2);
	h[0]=S;h[1]=S+t1;h[2]=S+t1+t2;h[3]=S+t2;
	for(i=0;i<4;i++) h[i]=h[i]-P;

	h[4]=h[0];
	pd=1;
	for(i=0;i<4;i++) if(cross(h[i],h[i+1])<-eps) pd=0;
	if(pd) dmi=0;
	for(i=0;i<4;i++) dmi=min(dmi,LEN(h[i])),dmx=max(dmx,LEN(h[i]));
	//for(i=0;i<4;i++) printf("#%lld : %lf %lf\n",i,(double)h[i].x,(double)h[i].y);
	for(i=0;i<4;i++)
	{
		bp=itr((Line){(Point){0,0},(Point){(h[i+1]-h[i]).y,-(h[i+1]-h[i]).x}},(Line){h[i],h[i+1]-h[i]});
		if((bp-h[i])*(bp-h[i+1])<0) dmi=min(dmi,LEN(bp));
	}
	//printf("U%lf %lf %lf\n",(double)dmi,(double)dmx,(double)LEN(P-Q));
	return dmi-eps*3.0<LEN(P-Q)&&dmx+eps*3.0>LEN(P-Q);
}
int main()
{
	ll i,j;
	P.x=rd();P.y=rd();
	n=rd();
	for(i=1;i<=n;i++) p[i].x=rd(),p[i].y=rd();
	p[n+1]=p[1];
	Q.x=rd();Q.y=rd();
	m=rd();
	for(i=1;i<=m;i++) q[i].x=rd(),q[i].y=rd();
	q[m+1]=q[1];
	//cout<<"check"<<check(p[2],p[3],q[1],q[2]);
	//exit(0);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(check(p[i],p[i+1],q[j],q[j+1])) 
			{
				//printf("S%lf %lf %lf %lf   %lf %lf %lf %lf\n",(double)p[i].x,(double)p[i].y,(double)p[i+1].x,(double)p[i+1].y,(double)q[j].x,(double)q[j].y,(double)q[j+1].x,(double)q[j+1].y);
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}