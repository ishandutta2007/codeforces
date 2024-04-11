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

int n,k,mark[100005];
char s[100005];

int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    memset(mark,-1,sizeof(mark));
    int i=1;
    for (int it=1;it<=k;++it){
        i=max(i-3,1);
        while (i+1<=n && !(s[i]=='4' && s[i+1]=='7')) ++i;
        if (i+1<=n){
            if (i&1){
                s[i+1]='4';
            }else{
                s[i]='7';
            }
            if (mark[i]==-1){
                mark[i]=it;
            }else{
                int len=it-mark[i];
                k=(k-it)%len+it;
            }
        }else break;
    }
    
    puts(s+1);
    
    return 0;
}