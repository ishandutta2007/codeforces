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

const int maxn      =   100005;
const long long inf =   1000000000000000LL;

struct node
{
    int left,right,aux,cnt,size;
    long long key;
}tree[maxn];
int n,a[maxn],tot;
long long s[maxn];

inline void init()
{
    tot=0;
    tree[0].left=tree[0].right=tree[0].cnt=tree[0].size=0;
    tree[0].aux=(RAND_MAX<<14)+RAND_MAX+1;
}

inline void renew(int &root)
{
    tree[root].size=tree[root].cnt+tree[tree[root].left].size+tree[tree[root].right].size;
}

inline void leftRotate(int &root)
{
    int t=tree[root].left;
    tree[root].left=tree[t].right;
    tree[t].right=root;
    renew(root);
    renew(t);
    root=t;
}

inline void rightRotate(int &root)
{
    int t=tree[root].right;
    tree[root].right=tree[t].left;
    tree[t].left=root;
    renew(root);
    renew(t);
    root=t;
}

inline void insert(int &root,long long key)
{
    if (root==0){
        root=++tot;
        tree[root].left=tree[root].right=0;
        tree[root].cnt=tree[root].size=1;
        tree[root].key=key;
        tree[root].aux=(rand()<<14)+rand();
        return;
    }
    if (tree[root].key==key){
        ++tree[root].cnt;
    }else if (key<tree[root].key){
        insert(tree[root].left,key);
        if (tree[tree[root].left].aux<tree[root].aux) leftRotate(root);
    }else{
        insert(tree[root].right,key);
        if (tree[tree[root].right].aux<tree[root].aux) rightRotate(root);
    }
    renew(root);
}

inline int getNum(int &root,long long key)
{
    if (root==0) return 0;
    if (tree[root].key>key) return getNum(tree[root].left,key);
    return tree[root].cnt+tree[tree[root].left].size+getNum(tree[root].right,key);
}

inline long long calc(long long limit)
{
    init();
    int root=0;
    insert(root,s[0]);
    long long ret=0;
    for (int i=1;i<=n;++i){
        long long x=s[i]-limit;
        ret+=getNum(root,x);
//printf("q %I64d   %d\n",x,getNum(root,x));
        insert(root,s[i]);
//printf("i %I64d\n",s[i]);
    }
//cout << limit << " " <<  ret << endl;
    return ret;
}

int main()
{
    long long k;
    scanf("%d%I64d",&n,&k);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
        s[i+1]=s[i]+a[i];
    }
    LL l=-1,r=inf*2;
    while (l+1<r){
        LL mid=(l+r)/2;
        if (calc(mid-inf)>=k) l=mid;
        else r=mid;
    }
    
    printf("%I64d\n",l-inf);
    
    
    return 0;
}