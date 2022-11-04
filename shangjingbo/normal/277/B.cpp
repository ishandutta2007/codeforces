#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
using namespace std;

#define PB push_back
#define MP make_pair

#define FOR(it,a) for (__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

inline int sign(double x)
{
    if (x<-eps) return -1;
    return x>eps;
}

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double x,double y):x(x),y(y){}
    inline double norm(){return sqrt(x*x+y*y);}
    inline void rotate(double ang)
    {
        double co=cos(ang),si=sin(ang);
        double tx=x,ty=y;
        x=tx*co-ty*si;
        y=tx*si+ty*co;
    }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){return Tpoint(a.x+b.x,a.y+b.y);}
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){return Tpoint(a.x-b.x,a.y-b.y);}
inline Tpoint operator *(const Tpoint &a,const double &b){return Tpoint(a.x*b,a.y*b);}
inline Tpoint operator /(const Tpoint &a,const double &b){return Tpoint(a.x/b,a.y/b);}
inline double det(const Tpoint &a,const Tpoint &b){return a.x*b.y-a.y*b.x;}
inline double dot(const Tpoint &a,const Tpoint &b){return a.x*b.x+a.y*b.y;}
//================================

int n,m;
int x[1000000],y[1000000];

int main()
{
    scanf("%d%d",&n,&m);
    
    if (m==3 && n>4){
        puts("-1");
        return 0;
    }
    
    int head=0,tail=m,sum=-2;
    for (int i=1;i<=m;++i){
        x[tail]=i;
        y[tail]=m*m+10+i*i;
        x[head]=i;
        y[head]=-m*m-10-i*i;
        ++tail;
        ++head;
    }
    
/*    for (int i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            for (int k=j+1;k<n;++k){
                LL a=x[j]-x[i],b=y[j]-y[i];
                LL c=x[k]-x[i],d=y[k]-y[i];
                if (a*d==b*c){
                    puts("co-line");
                    while (1);
                }
            }
        }
    }*/
    
    for (int i=0;i<n;++i){
        printf("%d %d\n",x[i],y[i]);
    }
    
    return 0;
}