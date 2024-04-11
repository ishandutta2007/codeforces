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
#define limit 10000000

int father[limit+5];

inline int Find(int x)
{
	if (father[x]==x) return x;
	return father[x]=Find(father[x]);
}

inline bool Union(int x,int y)
{
	if (father[x]==-1 || father[y]==-1) return false;
	int f1=Find(x),f2=Find(y);
	if (f1==f2) return false;
	father[f1]=f2;
	return true;
}
	

int main()
{
	int n,Ans;
	scanf("%d",&n);
	memset(father,-1,sizeof(father));
	for (int i=0;i<n;++i)
	{
		int x;
		scanf("%d",&x);
		father[x]=x;
	}
	Ans=n;
	for (long long u=1;2*u*u<=limit;++u)
	{
		long long x,y,z;
		for (long long v=u+1;(x=2*u*v)<=limit;v+=2)
		{
			y=v*v-u*u;
			if (y>limit) break;
			if (__gcd(u,v)!=1) continue;
			z=u*u+v*v;
			Ans-=Union(x,y);
			if (z<=limit) Ans-=Union(x,z)+Union(y,z);
		}
	}
	printf("%d\n",Ans);
	
	return 0;
}