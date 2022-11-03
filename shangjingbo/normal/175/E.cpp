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

const int limit =   12;

int nf,ne,ns;
int rf,re,rs;
double lf,le,ls;
int df,de,sel[limit+1];
double f[limit+1][21][21],damageF[limit+1],damageE[limit+1];

inline double dfs(int x,int s)
{
    if (s==ns){
        //dp
        memset(f,0,sizeof(f));
        for (int i=0;i<limit;++i){
            for (int j=0;j<=nf;++j)
                for (int k=0;k<=ne;++k){
                    for (int dj=0;dj+sel[i]<=2 && j+dj<=nf;++dj)
                        for (int dk=0;dk+dj+sel[i]<=2 && k+dk<=ne;++dk){
                            f[i+1][j+dj][k+dk]=max(f[i+1][j+dj][k+dk],f[i][j][k]+dj*(damageF[i]+2*lf)*df+dk*(damageE[i]+2*le)*de);
                        }
                }
        }
        return f[limit][nf][ne];
    }
    if (x==limit) return 0;
    
    double res=0;
    for (int i=0;i<=2 && s+i<=ns;++i){
        for (int x0=0;x0<limit;++x0){
            damageF[x0]+=i*max(0.0,min(x+ls,x0+lf)-max(x-ls,x0-lf));
            damageE[x0]+=i*max(0.0,min(x+ls,x0+le)-max(x-ls,x0-le));
        }
        
        sel[x]=i;
        res=max(dfs(x+1,s+i),res);
        sel[x]=0;
        
        for (int x0=0;x0<limit;++x0){
            damageF[x0]-=i*max(0.0,min(x+ls,x0+lf)-max(x-ls,x0-lf));
            damageE[x0]-=i*max(0.0,min(x+ls,x0+le)-max(x-ls,x0-le));
        }
    }
    return res;
}

int main()
{
    scanf("%d%d%d",&nf,&ne,&ns);
    scanf("%d%d%d",&rf,&re,&rs);
    lf=sqrt(rf*rf-1.0),le=sqrt(re*re-1.0),ls=sqrt(rs*rs-1.0);
    scanf("%d%d",&df,&de);
    
    memset(sel,0,sizeof(sel));
    printf("%.10f\n",dfs(0,0));
    
    return 0;
}