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

const int maxn  =   105;

int father[maxn+maxn],n,m;
bool vis[maxn+maxn];

inline int Find(int x)
{
    if (father[x]==x) return x;
    return father[x]=Find(father[x]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n+m;++i){
        father[i]=i;
    }
    int sum=0;
    for (int i=1;i<=n;++i){
        int p;
        scanf("%d",&p);
        sum+=p;
        for (int j=0;j<p;++j){
            int x;
            scanf("%d",&x);
            father[Find(i)]=Find(n+x);
        }
    }
    memset(vis,false,sizeof(vis));
    int cnt=0;
    for (int i=1;i<=n;++i){
        cnt+=vis[Find(i)]==false;
        vis[Find(i)]=true;
    }
    printf("%d\n",cnt-(sum>0));
    return 0;
}