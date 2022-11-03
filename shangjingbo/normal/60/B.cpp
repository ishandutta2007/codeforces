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

int k,n,m;
const int dx[]={1,-1,0,0,0,0};
const int dy[]={0,0,1,-1,0,0};
const int dz[]={0,0,0,0,1,-1};
char s[15][15][15];

inline int flood(int z,int x,int y)
{
	if (z<=0 || z>k) return 0;
	if (x<=0 || x>n) return 0;
	if (y<=0 || y>m) return 0;
	if (s[z][x][y]=='#') return 0;
	
	s[z][x][y]='#';
	int res=1;
	for (int kk=0;kk<6;++kk)
		res+=flood(z+dz[kk],x+dy[kk],y+dx[kk]);
	return res;
}

int main()
{
	scanf("%d%d%d",&k,&n,&m);
	for (int i=1;i<=k;++i)
	{
		for (int j=1;j<=n;++j)
			scanf("%s",s[i][j]+1);
	}
	
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",flood(1,x,y));
	
	return 0;
}