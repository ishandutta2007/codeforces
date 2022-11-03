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

const int inf   =   1000000000;
const int del[] ={1,-1};

#define maxn 155

int n,m,f[maxn][maxn][2];
bool canDown[maxn][maxn][2];
char s[maxn][maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i) scanf("%s",s[i]);
    
    while (n>0){
        bool must=false;
        for (int i=0;i<m;++i) if (s[n-1][i]=='W') must=true;
        if (!must) --n;
        else break;
    }
    
    if (n==0){
        puts("0");
        return 0;
    }
    
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            for (int dir=0;dir<2;++dir){
                canDown[i][j][dir]=true;
                f[i][j][dir]=inf;
                for (int k=j+del[dir];k>=0 && k<m && canDown[i][j][dir];k+=del[dir]){
                    if (s[i][k]=='W') canDown[i][j][dir]=false;
                    if (i+1<n && s[i+1][k]=='W') canDown[i][j][dir]=false;
                }
            }
        }
    }
    
    f[0][0][0]=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j)
        if (f[i][j][0]<inf){
            if (j+1<m) f[i][j+1][0]=min(f[i][j+1][0],f[i][j][0]+1);
            if (canDown[i][j][0]) f[i+1][j][1]=min(f[i+1][j][1],f[i][j][0]+1);
        }
        for (int j=m-1;j>=0;--j)
        if (f[i][j][1]<inf){
            if (j) f[i][j-1][1]=min(f[i][j-1][1],f[i][j][1]+1);
            if (canDown[i][j][1]) f[i+1][j][0]=min(f[i+1][j][0],f[i][j][1]+1);
        }
    }
    
    int ans=inf;
    for (int j=0;j<m;++j)
        for (int k=0;k<2;++k)
        if (canDown[n-1][j][k])
            ans=min(ans,f[n-1][j][k]);
    
    printf("%d\n",ans); 
    
    return 0;
}