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

int n;
char a[10000],b[10000];

inline bool win(char a,char b)
{
	if (a=='R' && b=='S') return true;
	if (a=='S' && b=='P') return true;
	if (a=='P' && b=='R') return true;
	return false;
}

int main()
{
	scanf("%d%s%s",&n,a,b);
	int la=strlen(a),lb=strlen(b);
	int lcm=la*lb/__gcd(la,lb);
	int limit=n%lcm;
	int ca=0,cb=0,aa=0,bb=0;
	for (int i=0;i<lcm;++i){
		int x=i%la,y=i%lb;
		if (win(a[x],b[y])) ++ca,aa+=(i<limit);
		else if (win(b[y],a[x])) ++cb,bb+=(i<limit);
	}
	int mul=((n-limit)/lcm);
	printf("%d %d\n",cb*mul+bb,ca*mul+aa);
	
	return 0;
}