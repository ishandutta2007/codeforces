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

int n,m,a[maxn];
double f[maxn][maxn],bak[maxn][maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            f[i][j]=a[i]>a[j];
        }
    }
    
    for (int i=0;i<m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        for (int z=1;z<=n;++z){
            bak[x][z]=f[x][z];
            bak[y][z]=f[y][z];
        }
        for (int z=1;z<=n;++z){
            if (z!=x && z!=y){
                f[x][z]=0.5*(bak[x][z]+bak[y][z]);
                f[y][z]=0.5*(bak[x][z]+bak[y][z]);
            }else if (z==x){
                f[y][z]=0.5*bak[y][x]+0.5*bak[x][y];
            }else if (z==y){
                f[x][z]=0.5*bak[y][x]+0.5*bak[x][y];
            }
            f[z][x]=1-f[x][z];
            f[z][y]=1-f[y][z];
        }
    }
    double ans=0;
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            ans+=f[i][j];
        }
    }
    printf("%.10f\n",ans);
    
    return 0;
}