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

#define maxm 100005
#define maxn 6

int pre[maxm][maxn],next[maxm][maxn],n,m;
long long f[2][1<<5];

inline void Update(long long &a,long long b)
{
    if (a==-1 || a>b) a=b;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<m;++i)
        for (int j=0;j<n;++j)
            scanf("%d",&pre[i][j]);
    for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
            scanf("%d",&next[i][j]);
    
    memset(f,-1,sizeof(f));
    int now=0,old=1;
    f[0][(1<<n)-1]=0;
    
    for (int i=1;i<m;++i)
    {
        for (int j=0;j<n;++j)
        {
            now=1-now;
            old=1-old;
            memset(f[now],-1,sizeof(f[now]));
            for (int stat=0;stat<1<<n;++stat)
            if (f[old][stat]!=-1)
            {
                for (int dig=0;dig<2;++dig)
                {
                    //up
                    long long cost=0;
                    if ((stat&1)!=dig) cost+=pre[i][j];
                    
                    //left
                    if (j && (stat&(1<<n-1))>0!=dig) cost+=next[i][j-1];
                    
                    //right
                    if (j==n-1 && (stat&2)>0!=dig) cost+=next[i][j];
                    
                    Update(f[now][(stat>>1)|(dig<<n-1)],f[old][stat]+cost);
                }
            }
            //printf("%I64d\n",f[now][1]);
        }
    }
    printf("%I64d\n",f[now][0]);
    
    return 0;
}