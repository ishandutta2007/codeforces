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

const int maxn  =   1000005;

int n,m;
char s[maxn];

struct node
{
    int c4,c7;
    int inc,dec;
    bool cover;
    
    inline void change()
    {
        cover^=1;
        swap(c4,c7);
        swap(inc,dec);
    }
}Tree[maxn*4];

inline node Merge(const node &a,const node &b)
{
    node res;
    res.cover=0;
    
    res.c4=a.c4+b.c4;
    res.c7=a.c7+b.c7;
    
    res.inc=max(a.inc+b.c7,a.c4+b.inc);
    res.dec=max(a.dec+b.c4,a.c7+b.dec);
    
    return res;
}

inline void Build(int num,int l,int r)
{
    if (l==r){
        Tree[num].cover=0;
        Tree[num].c4=(s[l]=='4');
        Tree[num].c7=(s[l]=='7');
        Tree[num].inc=Tree[num].dec=1;
        return;
    }
    int mid=(l+r)>>1;
    Build(num*2,l,mid);
    Build(num*2+1,mid+1,r);
    
    Tree[num]=Merge(Tree[num*2],Tree[num*2+1]);
}

inline void Cover(int num,int l,int r,int ll,int rr)
{
    if (rr<l || ll>r) return;
    if (ll<=l && r<=rr){
        Tree[num].change();
        return;
    }
    if (Tree[num].cover){
        Tree[num*2].change();
        Tree[num*2+1].change();
        Tree[num].cover=0;
    }
    int mid=(l+r)>>1;
    Cover(num*2,l,mid,ll,rr);
    Cover(num*2+1,mid+1,r,ll,rr);
    Tree[num]=Merge(Tree[num*2],Tree[num*2+1]);
}

inline node Query(int num,int l,int r,int ll,int rr)
{
    if (rr<l || ll>r){
        node res;
        res.c4=res.c7=res.inc=res.dec=0;
        return res;
    }
    if (ll<=l && r<=rr) return Tree[num];
    if (Tree[num].cover){
        Tree[num*2].change();
        Tree[num*2+1].change();
        Tree[num].cover=0;
    }
    int mid=(l+r)>>1;
    return Merge(Query(num*2,l,mid,ll,rr),Query(num*2+1,mid+1,r,ll,rr));
}

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    
    Build(1,0,n-1);
    
    while (m--){
        char op[20];
        scanf("%s",op);
        if (op[0]=='c'){
            printf("%d\n",Tree[1].inc);
        }else{
            int l,r;
            scanf("%d%d",&l,&r);
            --l;--r;
            Cover(1,0,n-1,l,r);
        }
    }
    
    return 0;
}