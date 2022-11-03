#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define MP make_pair
#define PB push_back

#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<string> VS;

const double pi =   acos(-1.0);
const double eps    =   1e-8;

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

const int maxn      =   150000+10;
const double inf    =   1e100;

struct node
{
    double mi,ma,md;
    node(){}
    node(double a,double b,double c){mi=a;ma=b;md=c;}
}Tree[maxn*4];

int n,m,C,x[maxn],p[maxn];
double a[maxn],S[maxn];

inline node merge(const node &a,const node &b)
{
    node res;
    res.ma=max(a.ma,b.ma);
    res.mi=min(a.mi,b.mi);
    res.md=max(a.md,b.md);
    res.md=max(res.md,b.ma-a.mi);
    return res;
}

inline void build(int num,int l,int r)
{
    if (l==r){
        Tree[num].mi=Tree[num].ma=a[l];
        Tree[num].md=0;
        return;
    }
    int mid=(l+r)>>1;
    build(num*2,l,mid);
    build(num*2+1,mid+1,r);
    Tree[num]=merge(Tree[num*2],Tree[num*2+1]);
}

inline node Query(int num,int l,int r,int ll,int rr)
{
    if (ll<=l && r<=rr) return Tree[num];
    if (rr<l || r<ll) return node(inf,-inf,0);
    
    int mid=(l+r)>>1;
    return merge(Query(num*2,l,mid,ll,rr),Query(num*2+1,mid+1,r,ll,rr));
}

int main()
{
    scanf("%d%d%d",&n,&m,&C);
    for (int i=1;i<=n;++i){
        scanf("%d",&x[i]);
    }
    for (int i=1;i<n;++i){
        scanf("%d",&p[i]);
    }
    S[1]=0;
    for (int i=1;i<=n;++i){
        a[i]=x[i]/2.0-S[i];
        S[i+1]=S[i]+p[i]/100.0*C;
    }
    
    build(1,1,n);
    
    double ans=0;
    for (int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        double t=Query(1,1,n,a,b).md;
        ans+=max(t,(x[b]-x[a])/2.0-(S[b]-S[a]));
//      printf("%lf\n",t);
    }
    printf("%.10f\n",ans);
    
    return 0;
}