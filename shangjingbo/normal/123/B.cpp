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

int main()
{
    LL a,b,x1,y1,x2,y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    
    LL sx=(x1+y1)/(2*a);while (sx*2*a>(x1+y1)) --sx;while ((sx+1)*2*a<=x1+y1) ++sx;
    LL sy=(x1-y1)/(2*b);while (sy*2*b>(x1-y1)) --sy;while ((sy+1)*2*b<=x1-y1) ++sy;
    
    LL tx=(x2+y2)/(2*a);while (tx*2*a>(x2+y2)) --tx;while ((tx+1)*2*a<=x2+y2) ++tx;
    LL ty=(x2-y2)/(2*b);while (ty*2*b>(x2-y2)) --ty;while ((ty+1)*2*b<=x2-y2) ++ty;
    
    cout << max(abs(sx-tx),abs(sy-ty)) << endl;
    
    return 0;
}