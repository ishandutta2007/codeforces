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

typedef long long LL;
typedef vector<int> VI;
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

#define maxn 40005

double sum[maxn*2],Ans;
Tpoint a[maxn*2];
int n;

inline void solve()
{
	for (int i=0;i<n;++i)
		a[i+n]=a[i];
	
	sum[0]=0;
	for (int i=1;i<=2*n;++i)
		sum[i]=sum[i-1]+det(a[i],a[i-1])/2;
	
	for (int i=0,j=0;i<n;++i)
	{
		if (j<=i) j=i+1;
		while (j+1<2*n && dot(a[j+1]-a[i],a[i+1]-a[i])+1e-8>dot(a[j]-a[i],a[i+1]-a[i])) ++j;
		
		if (j==i+1) Ans=0;
		if (j>=2*n) break;
		
		double X=dot(a[j]-a[i],a[i+1]-a[i])/(a[i+1]-a[i]).norm();
		double Y=sqrt( sqr((a[j]-a[i]).norm()) - sqr(X) );
		
		double Area=sum[j]-sum[i];
		Area+=det(a[i],a[j])/2;
		
		Ans=min(Ans,X*Y/2-fabs(Area));
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		a[i].read();
	Ans=1e100;
	
	solve();
	
	for (int i=0;i<n/2;++i)
		swap(a[i],a[n-1-i]);
	
	solve();	
	
	printf("%.9f\n",Ans);
	
	return 0;
}