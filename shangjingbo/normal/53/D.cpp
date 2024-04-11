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

int n,a[1000],b[1000];
vector<PII> res;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	for (int i=0;i<n;++i)
		scanf("%d",&b[i]);
	
	for (int i=0;i<n;++i)
	{
		int j=i;
		while (b[j]!=a[i]) ++j;
		
		for (int k=j;k>i;--k)
		{
			res.PB(MP(k-1,k));
			swap(b[k-1],b[k]);
		}
	}
	
	printf("%d\n",(int)res.size());
	for (int i=0;i<res.size();++i)
		printf("%d %d\n",res[i].first+1,res[i].second+1);
	
	return 0;
}