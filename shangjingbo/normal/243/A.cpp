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

const int maxn  =   100005;

bool mark[(1<<20)+10];
int n,a[maxn],last[maxn][20];

int main()
{
    //freopen("input.txt","r",stdin);
    
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<20;++i){
        last[n][i]=n;
    }
    for (int i=n-1;i>=0;--i){
        memcpy(last[i],last[i+1],sizeof(last[i]));
        for (int j=0;j<20;++j){
            if (a[i]>>j&1){
                last[i][j]=i;
            }
        }
    }
    
    for (int i=0;i<n;++i){
        int x=a[i],pos=i+1;
        mark[x]=true;
        while (1){
            int u=-1;
            for (int j=0;j<20;++j){
                if (x>>j&1){
                    continue;
                }
                if (u==-1 || last[pos][j]<last[pos][u]){
                    u=j;
                }
            }
            if (u==-1 || last[pos][u]>=n){
                break;
            }
            pos=last[pos][u];
            x|=a[pos];
            mark[x]=true;
            pos++;
        }
    }
    
    int res=0;
    for (int i=0;i<1<<20;++i){
        res+=mark[i];
        //if (mark[i]) printf("%d ",i);
    }
    printf("%d\n",res);
    
    return 0;
}