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

#define maxn 100005

int a[maxn],h[maxn],l[maxn],r[maxn];
int x[maxn],z[maxn],bak[maxn*5];
double Tree[maxn*5*4];
int n,m,N;

inline void Insert(int num,int l,int r,int ll,int rr,double key)
{
    if (rr<bak[l]) return;
    if (ll>bak[r]) return;
    if (ll<=bak[l] && bak[r]<=rr){
        Tree[num]*=key;
        return;
    }
    if (l==r) return;
    int mid=(l+r)>>1;
    Insert(num*2,l,mid,ll,rr,key);
    Insert(num*2+1,mid+1,r,ll,rr,key);
}

inline double Query(int num,int l,int r,int x)
{
    if (l==r) return Tree[num];
    int mid=(l+r)>>1;
    if (x<=bak[mid]) return Query(num*2,l,mid,x)*Tree[num];
    return Query(num*2+1,mid+1,r,x)*Tree[num];
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i){
        scanf("%d%d%d%d",&a[i],&h[i],&l[i],&r[i]);
        bak[N++]=a[i]-h[i];
        bak[N++]=a[i]+h[i];
        bak[N++]=i-1;
        bak[N++]=i+1;
    }
    double ans=0;
    for (int i=0;i<m;++i){
        scanf("%d%d",&x[i],&z[i]);
        bak[N++]=x[i];
    }
    sort(bak,bak+N);
    N=unique(bak,bak+N)-bak;
    
    for (int i=1;i<=4*N;++i)
        Tree[i]=1;
    for (int i=0;i<n;++i){
        Insert(1,0,N-1,a[i]-h[i],a[i]-1,1-l[i]/100.0);
        Insert(1,0,N-1,a[i]+1,a[i]+h[i],1-r[i]/100.0);
    }
    
    for (int i=0;i<m;++i){
        ans+=z[i]*Query(1,0,N-1,x[i]);
    }
    
    printf("%.10f\n",ans);
    
    return 0;
}