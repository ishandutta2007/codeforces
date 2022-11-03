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

const int maxn  =   400005;

int n;
double cover[maxn*4],tree[maxn*4];

inline void calc(int num)
{
    tree[num]=tree[num*2]+tree[num*2+1];
}

inline void pass(int num,int l,int r)
{
    int mid=(l+r)/2;
    tree[num*2]+=(mid-l+1)*cover[num];
    cover[num*2]+=cover[num];
    tree[num*2+1]+=(r-mid)*cover[num];
    cover[num*2+1]+=cover[num];
    cover[num]=0;
}

inline void insert(int num,int l,int r,int pos,int key)
{
    if (l==r){
        tree[num]=key;
        cover[num]=0;
        return;
    }
    int mid=(l+r)/2;
    pass(num,l,r);
    if (pos<=mid) insert(num*2,l,mid,pos,key);
    else insert(num*2+1,mid+1,r,pos,key);
    calc(num);
}

inline void add(int num,int l,int r,int ll,int rr,int delta)
{
    if (l>rr || r<ll){
        return;
    }
    if (ll<=l && r<=rr){
        tree[num]+=(r-l+1)*delta;
        cover[num]+=delta;
        return;
    }
    pass(num,l,r);
    int mid=(l+r)/2;
    add(num*2,l,mid,ll,rr,delta);
    add(num*2+1,mid+1,r,ll,rr,delta);
    calc(num);
}

inline double query(int num,int l,int r,int ll,int rr)
{
    if (l>rr || r<ll) return 0;
    if (ll<=l && r<=rr){
        return tree[num];
    }
    pass(num,l,r);
    int mid=(l+r)/2;
    return query(num*2,l,mid,ll,rr)+query(num*2+1,mid+1,r,ll,rr);
}

int main()
{
    scanf("%d",&n);
    int N=1;
    insert(1,1,n+1,N,0);
    for (int i=0;i<n;++i){
        int op,x,y;
        scanf("%d",&op);
        if (op==1){
            scanf("%d%d",&x,&y);
            if (x>N) x=N;
            add(1,1,n+1,1,x,y);
        }else if (op==2){
            scanf("%d",&x);
            ++N;
            insert(1,1,n+1,N,x);
        }else if (op==3){
            --N;
        }
        double sum=query(1,1,n+1,1,N);
//printf("  %.10f\n",sum);
        printf("%.10f\n",sum/N);
    }
    return 0;
}