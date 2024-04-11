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
#define maxn 100005

int n,a[maxn];

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	
	int Min=n-1;
	for (int i=0;i<n && i<3;++i)
		for (int j=i+1;j<n && j<3;++j)
		{
			double b,c;
			if (a[i]==0)
			{
				if (a[j]!=0) continue;
				c=0,b=0;
			}
			else c=a[i],b=a[j]/(double)a[i];
			int sum=2;
			double now=a[j]*b;
			for (int k=j+1;k<n;++k)
			if (fabs(now-a[k])<1e-7)
			{
				++sum;
				now*=b;
			}
			
			Min=min(Min,n-sum);
		}
	
	if (Min==0) puts("0");
	else if (Min==1) puts("1");
	else puts("2");
	
	return 0;
}