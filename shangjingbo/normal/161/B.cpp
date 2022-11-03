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

const int maxn  =   1005;

int n,k;
struct node
{
    int c,t,id;
}a[maxn];

inline bool cmp(const node &a,const node &b)
{
    return a.t<b.t || a.t==b.t && a.c>b.c;
}

int main()
{
    scanf("%d%d",&n,&k);
    long long sum=0;
    for (int i=0;i<n;++i){
        scanf("%d%d",&a[i].c,&a[i].t);
        a[i].id=i+1;
        sum+=a[i].c;
    }
    sum=sum*2;
    sort(a,a+n,cmp);
    
    for (int i=0;i<k-1;++i){
        if (a[i].t==1) sum-=a[i].c;
    }
    bool fl=false;
    int Min=a[k-1].c;
    for (int i=k-1;i<n;++i){
        if (a[i].t==1) fl=true;
        Min=min(Min,a[i].c);
    }
    if (fl) sum-=Min;
    printf("%I64d.%I64d\n",sum/2,(sum%2)*5);
    for (int i=0;i<k-1;++i)
        printf("1 %d\n",a[i].id);
    printf("%d",n-k+1);
    for (int i=k-1;i<n;++i)
        printf(" %d",a[i].id);
    
    return 0;
}