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

const int maxn	=	100005;

vector< pair<double,int> > event;
double ans[maxn];
int n,l,v1,v2,a[maxn];

int main()
{
	scanf("%d%d%d%d",&n,&l,&v1,&v2);
	for (int i=0;i<n;++i) scanf("%d",&a[i]);
	
	event.clear();
	double T=2.0*l;
	for (int i=0;i<n;++i){
		double pos=(l/(double)(v1+v2))*v2;
		if (a[i]-1e-8<pos){
			event.PB(MP(0,1));
			event.PB(MP(a[i],-1));
			event.PB(MP(a[i]-pos+T,1));
			event.PB(MP(T,-1));
		}else{
			event.PB(MP(a[i]-pos,1));
			event.PB(MP(a[i],-1));
		}
	}
	
	event.PB(MP(0,0));
	event.PB(MP(T,0));
	sort(event.begin(),event.end());
	

	int sum=0;
	memset(ans,0,sizeof(ans));
	for (int i=0;i<event.size();++i){
//printf("%d\n",sum);
		if (i){
			ans[sum]+=event[i].first-event[i-1].first;
		}
		sum+=event[i].second;
	}
	
	for (int i=0;i<=n;++i){
		printf("%.12f\n",ans[i]/T);
	}
	
	return 0;
}