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

long long n,x,y,base;
long long A[1000005];

struct Tmat
{
	long long a[2][2];
	inline void clear(){memset(a,0,sizeof(a));}
	inline void diagonal()
	{
		clear();
		for (int i=0;i<2;++i)
			a[i][i]=1;
	}
};
inline Tmat operator *(const Tmat &a,const Tmat &b)
{
	Tmat res;
	res.clear();
	for (int k=0;k<2;++k)
		for (int i=0;i<2;++i)
			for (int j=0;j<2;++j)
			{
				res.a[i][j]+=a.a[i][k]*b.a[k][j];
				res.a[i][j]%=base;
			}
	return res;
}

inline Tmat calc(const Tmat &a,long long t)
{
	Tmat res;
	res.diagonal();
	if (!t) return res;
	res=calc(a,t>>1);
	res=res*res;
	if (t&1LL) res=res*a;
	return res;
}

int main()
{
	cin >> n >> x >> y >> base;
	
	long long s=0;
	for (int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		A[i]=x;
		s+=A[i];
		s%=base;
	}
	if (n==1)
	{
		printf("%d\n",(int)s);
		return 0;
	}
	sort(A,A+n);
	
	Tmat a;
	// ( f[i],f[i+1] ) * a = (f[i+1],f[i+2])
	a.a[0][0]=0;a.a[0][1]=1;
	a.a[1][0]=1;a.a[1][1]=1;
	a=calc(a,x);
	//f[0]=0,f[1]=1;
	long long tmax=(A[n-2]*a.a[1][0]+A[n-1]*a.a[1][1])%base;
	
	// ( g[i],h[i] ) * a = (g[i+1],h[i+1])
	a.a[0][0]=1;a.a[0][1]=0;
	a.a[1][0]=1;a.a[1][1]=3;
	a=calc(a,x);
	//g[0]=0,h[0]=1
	s=(s*a.a[1][1]-(A[0]+A[n-1])*a.a[1][0])%base;
	if (s<0) s+=base;
	
	a.a[0][0]=1;a.a[0][1]=0;
	a.a[1][0]=1;a.a[1][1]=3;
	a=calc(a,y);
	//g[0]=0,h[0]=1
	s=(s*a.a[1][1]-(A[0]+tmax)*a.a[1][0])%base;
	if (s<0) s+=base;
	
	printf("%d\n",(int)s);
	
	return 0;
}