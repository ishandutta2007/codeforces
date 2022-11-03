#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef unsigned long long ULL;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

struct Tpoint
{
	double x,y;
	Tpoint(){}
	Tpoint(double _x,double _y){x=_x;y=_y;}
	inline void read(){scanf("%lf%lf",&x,&y);}
	inline void show(){printf("%lf %lf\n",x,y);}
	inline double norm(){ return sqrt( sqr(x)+sqr(y) ); }
	inline double norm2(){ return sqr(x)+sqr(y); }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x+b.x,a.y+b.y); }
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x-b.x,a.y-b.y); }
inline Tpoint operator *(const Tpoint &a,const double &b){ return Tpoint(a.x*b,a.y*b); }
inline Tpoint operator /(const Tpoint &a,const double &b){ return Tpoint(a.x/b,a.y/b); }
inline double det(const Tpoint &a,const Tpoint &b){ return a.x*b.y-a.y*b.x; }
inline double dot(const Tpoint &a,const Tpoint &b){ return a.x*b.x+a.y*b.y; }
//=============================================================================================

#define maxn 1000

struct P3
{
	double x,y,z;
	P3(){}
	P3(double a,double b,double c){x=a;y=b;z=c;}
	inline void read(){scanf("%lf%lf%lf",&x,&y,&z);}
	inline double norm(){return sqrt(x*x+y*y+z*z);}
}a[maxn];
inline P3 operator +(const P3 &a,const P3 &b){return P3(a.x+b.x,a.y+b.y,a.z+b.z);}
inline P3 operator -(const P3 &a,const P3 &b){return P3(a.x-b.x,a.y-b.y,a.z-b.z);}
inline P3 operator *(const P3 &a,const double &b){return P3(a.x*b,a.y*b,a.z*b);}
inline P3 operator /(const P3 &a,const double &b){return P3(a.x/b,a.y/b,a.z/b);}
inline double dot(const P3 &a,const P3 &b){return a.x*b.x+a.y*b.y+a.z*b.z;}
inline P3 det(const P3 &a,const P3 &b)
{
	return P3( a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x );
}
//==========================================================================

const double eps	=	 1e-8;

inline int sign(double x)
{
	if (x>eps) return 1;
	if (x<-eps) return -1;
	return 0;
}

struct circle
{
	Tpoint o;
	double r;
};

circle ans;

inline void CircleCenter(Tpoint p0, Tpoint p1, Tpoint p2, Tpoint &cp)
{
	double a1=p1.x-p0.x , b1=p1.y-p0.y , c1=(sqr(a1)+sqr(b1)) / 2 ;
	double a2=p2.x-p0.x , b2=p2.y-p0.y , c2=(sqr(a2)+sqr(b2)) / 2 ;
	double d = a1*b2 - a2*b1 ;
	cp.x = p0.x + ( c1*b2 - c2*b1 ) / d ;
	cp.y = p0.y + ( a1*c2 - a2*c1 ) / d ;

}

inline bool check(const Tpoint &a)
{
	return (a-ans.o).norm2() <= ans.r+eps;
}

inline void miniCircle(Tpoint a[],int n)
{
	/*for (int i=0;i<n;++i){
		a[i].show();
	}
	puts("=============================");*/
	int i,j,k;
	ans.r=0;
	ans.o=Tpoint(0,0);
	random_shuffle(a,a+n);
	for (int i=0;i<n;++i) if (!check(a[i])){
		ans.o=a[i];
		ans.r=0;
		for (int j=0;j<i;++j) if (!check(a[j])){
			ans.o=(a[i]+a[j])/2;
			ans.r=(ans.o-a[i]).norm2();
			for (int k=0;k<j;++k)if (!check(a[k])){
				CircleCenter(a[i],a[j],a[k],ans.o);
				ans.r=(ans.o-a[i]).norm2();
			}
		}
	}
	printf("%.10f\n",sqrt(fabs(ans.r)));
}

Tpoint p[maxn];
int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i)
		a[i].read();
	
	for (int i=0;i<m;++i){
		double A,B,C;
		scanf("%lf%lf%lf",&A,&B,&C);
		P3 dz(A,B,C),ta,b;
		if (sign(A)){
			ta=P3(-C/A,0,1);
			b=P3(-B/A,1,0);
		}else if (sign(B)){
			ta=P3(1,-A/B,0);
			b=P3(0,-C/B,1);
		}else if (sign(C)){
			ta=P3(1,0,-A/C);
			b=P3(0,1,-B/C);
		}else while (1);
		
		P3 dx=ta-b,o=b;
		P3 dy=det(dz,dx);
		dx=det(dy,dz);
		
		dx=dx/dx.norm();
		dy=dy/dy.norm();
		
		for (int j=0;j<n;++j){
			p[j]=Tpoint( dot(a[j]-o,dx), dot(a[j]-o,dy) );
		}
		
		miniCircle(p,n);
	}
	
	return 0;
}