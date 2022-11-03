#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define MP make_pair
#define PB push_back

#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<string> VS;

const double pi	=	acos(-1.0);
const double eps	=	1e-8;

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double _x,double _y){x=_x;y=_y;}
    inline void read(){scanf("%lf%lf",&x,&y);}
    inline void show(){printf("%lf %lf\n",x,y);}
    inline double norm(){ return sqrt( sqr(x)+sqr(y) ); }
};
inline Tpoint operator +(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x+b.x,a.y+b.y); }
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x-b.x,a.y-b.y); }
inline Tpoint operator *(const Tpoint &a,const double &b){ return Tpoint(a.x*b,a.y*b); }
inline Tpoint operator /(const Tpoint &a,const double &b){ return Tpoint(a.x/b,a.y/b); }
inline double det(const Tpoint &a,const Tpoint &b){ return a.x*b.y-a.y*b.x; }
inline double dot(const Tpoint &a,const Tpoint &b){ return a.x*b.x+a.y*b.y; }
//=============================================================================================

int a,b,c,S;

inline double g(double x,double y)
{
	double z=S-x-y;
	if (fabs(x)<eps || fabs(y)<eps || fabs(z)<eps){
		return -1e100;
	}
	double ans=0;
	if (a==0) ans+=0;
	else ans+=a*log(x);
	if (b==0) ans+=0;
	else ans+=b*log(y);
	if (c==0) ans+=0;
	else ans+=c*log(z);
	return ans;
}

inline double f(double x,double &y)
{
	double l=0,r=S-x;
	for (int it=0;it<300;++it){
		double m1=l+(r-l)/3,m2=r-(r-l)/3;
		if (g(x,m1)+eps<g(x,m2)) l=m1;
		else r=m2;
	}
	y=l;
	return g(x,y);
}

int main()
{
	scanf("%d%d%d%d",&S,&a,&b,&c);
	
	double l=0,r=S,y;
	for (int it=0;it<300;++it){
		double m1=l+(r-l)/3,m2=r-(r-l)/3;
		if (f(m1,y)+eps<f(m2,y)) l=m1;
		else r=m2;
	}
	f(l,y);
	printf("%.10f %.10f %.10f\n",l,y,S-l-y);
	
	return 0;
}