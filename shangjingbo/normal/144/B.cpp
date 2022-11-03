#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define MP make_pair
#define PB push_back

#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<string> VS;

const double pi	=	acos(-1.0);
const double eps	=	1e-8;

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

const int maxn	=	1005;

int x[maxn],y[maxn],R[maxn],xa,xb,ya,yb,n;
vector<PII> inter;

int main()
{
	scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
	if (xa>xb) swap(xa,xb);
	if (ya>yb) swap(ya,yb);
	
	scanf("%d",&n);
	
	int ans=0;
	for (int i=0;i<n;++i){
		scanf("%d%d%d",&x[i],&y[i],&R[i]);
	}
	for (int xx=xa;xx<=xb;++xx){
		for (int yy=ya;yy<=yb;++yy){
			if (xx==xa || xx==xb || yy==ya || yy==yb){
				bool ok=false;
				for (int i=0;i<n && !ok;++i)
				if (sqr(x[i]-xx)+sqr(y[i]-yy)<=sqr(R[i]))
					ok=true;
				
				if (!ok) ++ans;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}