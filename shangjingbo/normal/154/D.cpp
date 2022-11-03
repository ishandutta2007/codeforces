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
    int x1,x2,a,b;
    scanf("%d%d%d%d",&x1,&x2,&a,&b);
    if (x2>=x1+a && x2<=x1+b){
        puts("FIRST");
        printf("%d\n",x2);
        return 0;
    }
    
    if (a<=0 && b>=0){
        puts("DRAW");
        return 0;
    }
    
    LL delta=x1-x2;
    int sign=1;
    if (a>0){
        a=-a;
        b=-b;
        swap(a,b);
        delta=-delta;
        sign=-1;
    }
    
    LL lose=-a-b;
    LL k=delta/lose;
    if (delta%lose==0 && k>0){
        puts("SECOND");
        return 0;
    }
    
    while ((k+1)*lose-b<=delta) ++k;
    while (k*lose-b>delta) --k;
    
    if (k>0 && k*lose-b<=delta && delta<=k*lose-a){
        cout << "FIRST" << endl;
        LL out=k*lose;
        cout << out*sign+x2 << endl;
        return 0;
    }
    
    puts("DRAW");
    
    return 0;
}