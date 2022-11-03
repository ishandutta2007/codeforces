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

int n,a[100005],cnt[100005];

int main()
{
    scanf("%d",&n);
    if (n&1){
        puts("NO");
        return 0;
    }
    for (int i=0;i<n;++i)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if (a[n-1]-a[0]>100000){
        puts("NO");
        return 0;
    }
    
    for (int i=1;i<n;++i)
        a[i]-=a[0];
    a[0]=0;
    
    for (int i=0;i<n;++i)
        ++cnt[a[i]];
    
    --cnt[0];
    int cur=0;
    for (int i=1;i<n;++i){
        if (cnt[cur+1]){
            ++cur;
            --cnt[cur];
        }else if (cur>0 && cnt[cur-1]){
            --cur;
            --cnt[cur];
        }else{
            puts("NO");
            return 0;
        }
    }
    if (cur!=1) puts("NO");
    else puts("YES");
    
    return 0;
}