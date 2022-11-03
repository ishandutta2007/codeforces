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

const int maxn  =   100005;

int a[maxn],id[maxn];
bool vis[maxn];

inline bool cmpA(const int &i,const int &j)
{
    return a[i]>a[j];
}

int main()
{
    int n,k;
    LL b;
    scanf("%d%d",&n,&k);
    scanf("%I64d",&b);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        id[i]=i;
    }
    sort(id+1,id+n,cmpA);
    
    LL sum=0;
    for (int i=1;i<=k-1;++i){
        sum+=a[id[i]];
        vis[id[i]]=true;
    }
    
    for (int i=1;i<=n;++i){
        LL cost=sum;
        if (vis[i]){
            cost-=a[i];
            cost+=a[id[k]];
        }
        
        if (b-cost<a[i]){
            printf("%d\n",i);
            return 0;
        }
    }
    
    printf("%d\n",n);
    
    return 0;
}