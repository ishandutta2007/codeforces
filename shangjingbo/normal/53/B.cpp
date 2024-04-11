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
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x+b.x,a.y+b.y); }
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x-b.x,a.y-b.y); }
inline Tpoint operator *(const Tpoint &a,const double &b){ return Tpoint(a.x*b,a.y*b); }
inline Tpoint operator /(const Tpoint &a,const double &b){ return Tpoint(a.x/b,a.y/b); }
inline double det(const Tpoint &a,const Tpoint &b){ return a.x*b.y-a.y*b.x; }
inline double dot(const Tpoint &a,const Tpoint &b){ return a.x*b.x+a.y*b.y; }

int main()
{
	int h,w;
	scanf("%d%d",&h,&w);
	double lrate=0.8,rrate=1.25;
	
	long long big=0;
	int ansh=0,answ=0;
	for (int width=1;width<=w;width<<=1)
	{
		long long hl=(long long)ceil(lrate*width);
		long long hr=(long long)floor(rrate*width);
		hl=max(hl,1LL);
		hr=min(hr,(long long)h);
		if (hl<=hr)
		{
			long long area=width*hr;
			if (area>big || area==big && hr>ansh)
			{
				big=area;
				ansh=(int)hr;
				answ=width;
			}
		}
	}
	
	lrate=1.0/1.25,rrate=1.0/0.8;
	for (int width=1;width<=h;width<<=1)
	{
		long long hl=(long long)ceil(lrate*width);
		long long hr=(long long)floor(rrate*width);
		hl=max(hl,1LL);
		hr=min(hr,(long long)w);
		if (hl<=hr)
		{
			long long area=width*hr;
			if (area>big || area==big && width>ansh)
			{
				big=area;
				ansh=width;
				answ=(int)hr;
			}
		}
	}
	
	printf("%d %d\n",ansh,answ);
	
	return 0;
}