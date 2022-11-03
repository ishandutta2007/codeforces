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

const int maxn  =   55;

int n,p,a[maxn];
double f[2][maxn][maxn];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    scanf("%d",&p);
    double ans=0;
    for (int forbid=0;forbid<n;++forbid){
        memset(f,0,sizeof(f));
        int now=0,old=1;
        memset(f,0,sizeof(f));
        f[now][0][0]=1;
        int N=1;
        for (int i=0;i<n;++i){
            if (i==forbid){
                continue;
            }
            now=1-now;
            old=1-old;
            memset(f[now],0,sizeof(f[now]));
            for (int j=0;j<=N;++j){
                for (int k=0;k<=p;++k){
                    f[now][j][k]+=f[old][j][k]*(N-j)/(N+1.0);
                    if (k+a[i]<=p){
                        f[now][j+1][k+a[i]]+=f[old][j][k]*(j+1.0)/(N+1.0);
                    }
                }
            }
            ++N;
        }
//printf("%lf\n",f[now][0][0]);
        for (int i=0;i<=n;++i){
            for (int j=0;j<=p;++j){
                if (j+a[forbid]<=p){
                    ans+=f[now][i][j];
                }
            }
        }
//printf("%d %lf\n",forbid,ans);
    }
    printf("%.10f\n",ans);
    return 0;
}