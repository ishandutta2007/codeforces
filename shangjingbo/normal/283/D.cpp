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

const int maxn  =   5005;

long long a[maxn];
int b[maxn],f[maxn],n;

inline bool can(int i,int j)
{
    if (a[i]%a[j]){
        return false;
    }
    int s=b[i],t=b[j];
    int n=j-i;
    if (s+n==t){
        return true;
    }
    if (n==1 && t==0){
        return true;
    }
    if (n-1>=t){
        return true;
    }
    return false;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%I64d",&a[i]);
        b[i]=0;
        while (a[i]%2==0){
            ++b[i];
            a[i]/=2;
        }
    }

    f[0]=0;
    int ans=0;
    for (int i=1;i<=n;++i){
        f[i]=0;
        for (int j=0;j<i;++j){
            if (j==0 || can(j,i)){
                f[i]=max(f[i],f[j]+1);
            }
        }
        ans=max(ans,f[i]);
    }
    
    printf("%d\n",n-ans);
    
    return 0;
}