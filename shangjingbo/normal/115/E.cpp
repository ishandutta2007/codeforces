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

#define maxn 200005

long long Tree[maxn*4],Cover[maxn*4],f[maxn];
int a[maxn],n,m;
struct node
{
    int l,r,p;
}b[maxn];

inline bool cmp(const node &a,const node &b)
{
    return a.r<b.r;
}

inline void Insert(int num,int l,int r,int ll,int rr,LL delta)
{
    if (l==ll && r==rr){
        Tree[num]+=delta;
        Cover[num]+=delta;
        return;
    }
    if (Cover[num]){
        Tree[num*2]+=Cover[num];
        Tree[num*2+1]+=Cover[num];
        Cover[num*2]+=Cover[num];
        Cover[num*2+1]+=Cover[num];
        Cover[num]=0;
    }
    
    int mid=(l+r)/2;
    if (rr<=mid) Insert(num*2,l,mid,ll,rr,delta);
    else if (ll>mid) Insert(num*2+1,mid+1,r,ll,rr,delta);
    else {
        Insert(num*2,l,mid,ll,mid,delta);
        Insert(num*2+1,mid+1,r,mid+1,rr,delta);
    }
    Tree[num]=max(Tree[num*2],Tree[num*2+1]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    
    for (int i=0;i<m;++i) scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].p);
    sort(b,b+m,cmp);
    
    memset(Tree,0,sizeof(Tree));
    memset(Cover,0,sizeof(Cover));
    
    f[0]=0;
    for (int i=1,j=0;i<=n;++i){
        Insert(1,0,n,0,i-1,-a[i]);
        while (j<m && b[j].r==i){
            Insert(1,0,n,0,b[j].l-1,b[j].p);
            ++j;
        }
        f[i]=max(f[i-1],Tree[1]);
        Insert(1,0,n,i,i,f[i]);
    }
    
    printf("%I64d\n",f[n]);
    
    return 0;
}