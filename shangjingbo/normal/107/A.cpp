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

#define maxn 2005

int n,m,next[maxn],c[maxn],x[maxn],y[maxn],z[maxn],cap[maxn];
int in[maxn],out[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        next[a]=b;
        cap[a]=c;
        ++in[b];
        ++out[a];
    }
    int N=0;
    for (int i=1;i<=n;++i) if (!in[i] && out[i]){
        int j=i,delta=1000000000;
        while (out[j]){
            delta=min(delta,cap[j]);
            j=next[j];
        }
        x[N]=i;
        y[N]=j;
        z[N++]=delta;
    }
    
    printf("%d\n",N);
    for (int i=0;i<N;++i) printf("%d %d %d\n",x[i],y[i],z[i]);
    return 0;
}