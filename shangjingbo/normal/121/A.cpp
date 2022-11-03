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

vector<long long> a;

int main()
{
    a.clear();
    for (int l=1;l<=10;++l)
        for (int i=0;i<1<<l;++i){
            long long x=0;
            for (int j=0;j<l;++j)
            if ((i>>j) &1)
                x=x*10+7;
            else x=x*10+4;
            a.PB(x);
        }
    sort(a.begin(),a.end());
    long long l,r,ans=0;
    cin >> l >> r;
    for (int i=0;i<a.size();++i){
        long long limit=l;
        if (i) limit=max(limit,a[i-1]+1);
        if (limit<=min(a[i],r)){
            ans+=(min(a[i],r)-limit+1)*a[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}