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
//=============================================================================================
#define maxn 200005

int x[maxn],n;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&x[i]);
	sort(x,x+n);
	
	int l=-1,r=1000000001;
	while (l+1<r)
	{
		int mid=(l+r)/2;
		int s=0;
		for (int i=0;i<3;++i)
		{
			int t=s+1;
			while (t<n && x[t]-x[s]<=mid) ++t;
			s=t;
		}
		
		if (s>=n) r=mid;
		else l=mid;
	}
	printf("%lf\n",r/2.0);
	int s=0;
	for (int i=0;i<3;++i)
	{
		int t=s+1;
		while (t<n && x[t]-x[s]<=r) ++t;
		if (i) printf(" ");
		printf("%lf",(x[s]+x[t-1])/2.0);
		
		s=t;
	}
	puts("");
	
	return 0;
}