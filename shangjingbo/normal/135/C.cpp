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

char s[1000000];

int main()
{
    scanf("%s",s);
    int n=strlen(s);
    
    int c0=0,c1=0,cnt=0;
    for (int i=0;i<n;++i){
        if (s[i]=='0') ++c0;
        else if (s[i]=='1') ++c1;
        else ++cnt;
    }
    
    if (c1<=(n-2+1)/2) puts("00");
    
    if (s[n-1]!='0'){
        if (s[n-1]=='1'){
            if (c0<=n/2 && c1<=(n+1)/2) puts("01");
        }else{
            if (c0<=n/2 && c1+1<=(n+1)/2) puts("01");
        }
    }
    
    if (s[n-1]!='1'){
        if (s[n-1]=='0'){
            if (c0<=n/2 && c1<=(n+1)/2) puts("10");
        }else{
            if (c0+1<=n/2 && c1<=(n+1)/2) puts("10");
        }
    }
    
    if (c0-(n-2)/2<=0) puts("11");
    
    return 0;
}