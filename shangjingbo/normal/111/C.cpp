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

int f[2][(1<<6+6)+10],n,m;

inline void Update(int &a,int b)
{
    if (a==-1 || a>b) a=b;
}

int main()
{
    scanf("%d%d",&n,&m);
    if (n<m) swap(n,m);
    int tot=m+m;
    memset(f,-1,sizeof(f));
    int now=0,old=1;
    f[now][0]=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            now=1-now;
            old=1-old;
            memset(f[now],-1,sizeof(f[now]));
            for (int k=0;k<1<<tot;++k) if (f[old][k]!=-1){
                //printf("%d %d %d %d\n",i,j,k,f[old][k]);
                //L
                int p=m-1;
                int c=(k>>p)&1;
                c=1-c;
                if (j>0) Update(f[now][(k>>1)|(1<<p-1)],f[old][k]+c);
                //R
                p=m+1;
                c=(k>>p)&1;
                c=1-c;
                if (j+1<m) Update(f[now][(k>>1)|(1<<p-1)],f[old][k]+c);
                //U
                p=0;
                c=(k>>p)&1;
                c=1-c;
                if (i>0) Update(f[now][k>>1],f[old][k]+c);
                //D
                p=2*m;
                c=0;
                c=1-c;
                if (i+1<n) Update(f[now][(k>>1)|(1<<p-1)],f[old][k]+c);
                //S
                p=m;
                c=(k>>p)&1;
                c=1-c;
                Update(f[now][(k>>1)|(1<<p-1)],f[old][k]+c);
            }
        }
    }
    
    int ans=-1;
    for (int i=0;i<1<<tot;++i) if (f[now][i]!=-1) Update(ans,f[now][i]);
    printf("%d\n",n*m-ans);
    
    return 0;
}