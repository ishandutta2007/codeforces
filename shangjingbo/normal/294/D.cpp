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

//                   UL UR Dl DR
const int dx[]  =   {-1,-1,1,1};
const int dy[]  =   {-1,1,-1,1};

int main()
{
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    char sdir[100];
    scanf("%d%d%s",&x,&y,sdir);
    int dir=0;
    if (sdir[0]=='D') {
        dir|=2;
    }
    if (sdir[1]=='R'){
        dir|=1;
    }
    
    int target=0;
    for (int i=1;i<=n;++i){
        if ((i+1)%2==(x+y)%2){
            ++target;
        }
        if ((i+m)%2==(x+y)%2){
            ++target;
        }
    }
    for (int i=2;i<m;++i){
        if ((i+1)%2==(x+y)%2){
            ++target;
        }
        if ((i+n)%2==(x+y)%2){
            ++target;
        }
    }
//cerr << "target = " << target << endl;
    set<PII> visit;
    long long total_time=1;
    for (int t=0;t<(n+m)*4;++t){
        visit.insert(MP(x,y));
//printf("%d %d %d\n",x,y,dir);
        if ((int)visit.size()==target){
            printf("%I64d\n",total_time);
            return 0;
        }
        int l=0,r=max(n,m)+1;
        while (l+1<r){
            int mid=(l+r)/2;
            int xx=x+dx[dir]*mid;
            int yy=y+dy[dir]*mid;
            if (xx>=1 && xx<=n && yy>=1 && yy<=m){
                l=mid;
            }else{
                r=mid;
            }
        }
//printf("steps = %d\n",l);
        total_time+=l;
        x+=dx[dir]*l;
        y+=dy[dir]*l;
        
        if (x==1 || x==n){
            dir^=2;
        }
        if (y==1 || y==m){
            dir^=1;
        }
        
        if (x==1 && y==1){
            dir=3;
        }else if (x==1 && y==m){
            dir=2;
        }else if (x==n && y==1){
            dir=1;
        }else if (x==n && y==m){
            dir=0;
        }
    }
    puts("-1");
    
    return 0;
}