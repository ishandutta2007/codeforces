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

const long double eps   =   1e-8;
const int eachSize  =   256;

struct node
{
    int a,b,id;
    node(){}
    node(int x,int y,int z){a=x;b=y;id=z;}
    inline LL calc(LL t)
    {
        return a+b*t;
    }
};

inline bool operator<(const node &a,const node &b)
{
    return a.b<b.b || a.b==b.b && a.a>b.a;
}

inline bool operator ==(const node &a,const node &b)
{
    return a.a==b.a && a.b==b.b;
}

inline long double cross(const node &a,const node &b)
{
    //a.a+a.b*x=b.a+b.b*x
    return ((long double)a.a-b.a)/((long double)b.b-a.b);
}

#define maxn 100005

node l[maxn];
int n,Q,a[maxn],b[maxn];
node q[maxn/eachSize+1][eachSize+1];
int head[maxn/eachSize+1],tail[maxn/eachSize+1];
int out[maxn];

struct Event
{
    int l,r,t,i;
}E[maxn];

inline bool cmpT(const Event &a,const Event &b)
{
    return a.t<b.t;
}

int main()
{
    scanf("%d%d",&n,&Q);
    for (int i=0;i<n;++i){
        scanf("%d%d",&a[i],&b[i]);
    }
    
    for (int st=0,id=0;st<n;st+=eachSize,++id){
        int ed=st+eachSize;
        int N=0;
        for (int i=st;i<ed && i<n;++i){
            l[N++]=node(a[i],b[i],i);
        }
        sort(l,l+N);
        int p=0;
        for (int i=0;i<N;++i){
            if (!p || l[p-1].b<l[i].b) l[p++]=l[i];
        }
        N=p;
        head[id]=tail[id]=0;
        for (int i=0;i<N;++i){
            while (tail[id]-head[id]>1 && cross(q[id][tail[id]-1],q[id][tail[id]-2])>cross(l[i],q[id][tail[id]-2])+eps) --tail[id];
            q[id][tail[id]++]=l[i];
        }
    }
    
    for (int i=0;i<Q;++i){
        scanf("%d%d%d",&E[i].l,&E[i].r,&E[i].t);
        E[i].i=i;
    }
    sort(E,E+Q,cmpT);
    
    for (int i=0;i<Q;++i){
        int l=E[i].l,r=E[i].r,t=E[i].t;
        --l;--r;
        LL ans=0;
        int best=-1;
        while (l<=r && (l&(eachSize-1))){
            if (ans<a[l]+(LL)b[l]*t){
                ans=a[l]+(LL)b[l]*t;
                best=l;
            }
            ++l;
        }
        while (l<=r && (r&(eachSize-1))!=eachSize-1){
            if (ans<a[r]+(LL)b[r]*t){
                ans=a[r]+(LL)b[r]*t;
                best=r;
            }
            --r;
        }
        if (l<=r){
            int id=l/eachSize;
            for (int st=l;st<=r;st+=eachSize,++id){
                while (tail[id]-head[id]>1 && q[id][head[id]].calc(t)<q[id][head[id]+1].calc(t)) ++head[id];
                if (head[id]<tail[id]){
                    if (ans<q[id][head[id]].calc(t)){
                        ans=q[id][head[id]].calc(t);
                        best=q[id][head[id]].id;
                    }
                }
            }
        }
        out[E[i].i]=best;
    }
    
    for (int i=0;i<Q;++i)
        printf("%d\n",out[i]+1);
    
    return 0;
}