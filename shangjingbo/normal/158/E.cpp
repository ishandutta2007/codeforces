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

const int maxn  =   4005;

int n,k,t[maxn],d[maxn];
int f[maxn][maxn];

inline void Update(int &a,int b)
{
    if (a==-1 || a>b) a=b;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;++i){
        scanf("%d%d",&t[i],&d[i]);
    }
    
    memset(f,-1,sizeof(f));
    memset(f[0],0,sizeof(f[0]));
    int ans=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<=k;++j)if (f[i][j]!=-1){
            if (j){
                Update(f[i+1][j-1],f[i][j]);
            }
            int tmp=f[i][j];
            if (tmp<t[i]){
                ans=max(ans,t[i]-tmp-1);
                tmp=t[i]+d[i]-1;
            }else tmp+=d[i];
            Update(f[i+1][j],tmp);
        }
    }
    
    for (int j=0;j<=k;++j)if (f[n][j]!=-1)
        ans=max(ans,86400-f[n][j]);
    
    printf("%d\n",ans);
    
    return 0;
}