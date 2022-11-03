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

const int maxn  =   200005;
const long long inf =   1000000000000000000LL;

int n,a[maxn];
pair<LL,int> f[maxn][2];
bool memo[maxn][2];

set<PII> inStack;

inline pair<LL,int> go(int x,int t)
{
    if (x<=0 || x>n) return MP(0,0);
    if (x==1){
        if (t==0){
            return MP(inf,0);
        }
        return MP(0,1);
    }
    if (inStack.count(MP(x,t))){
        return MP(inf,0);
    }
    inStack.insert(MP(x,t));
    if (memo[x][t]){
        return f[x][t];
    }
    memo[x][t]=true;
    pair<LL,int> &res=f[x][t];
    int y;
    if (t==0) y=x+a[x];
    else y=x-a[x];
    res=go(y,t^1);
    if (res.first!=inf){
        res.first+=a[x];
    }
    return res;
}

int main()
{
    scanf("%d",&n);
    for (int i=2;i<=n;++i){
        scanf("%d",&a[i]);
    }
    
    for (int i=1;i<n;++i){
        inStack.clear();
        inStack.insert( MP(1,0) );
        pair<LL,int> ans=go(1+i,1);
        if (ans.first==inf){
            puts("-1");
        }else{
            printf("%I64d\n",ans.first+i*(ans.second+1));
        }
    }
    
    return 0;
}