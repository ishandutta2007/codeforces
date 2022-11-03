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

struct node
{
    int a,r;
}a[maxn];
int bak[maxn],N;
int g[maxn];

inline bool cmp(const node &a,const node &b)
{
    return a.r<b.r || a.r==b.r && a.a<b.a;
}

inline bool cmpAge(const node &a,const node &b)
{
    return a.a<b.a;
}

int c[maxn],Tree[maxn*4];
int R[maxn],A[maxn],out[maxn];

inline void add(int x)
{
    while (x<=N){
        ++c[x];
        x+=lowbit(x);
    }
}

inline int getSum(int x)
{
    int res=0;
    while (x>0){
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}

inline int getSum(int l,int r)
{
    int s=lower_bound(bak,bak+N,l)-bak;
    int t=upper_bound(bak,bak+N,r)-bak;
    --t;
    //printf("  %d %d\n",s,t);
    if (s>t) return 0;
    return getSum(t+1)-getSum(s);
}
//=====================================================

struct typeQuery
{
    int R,l,r;
    int id;
    bool flag;
}query[maxn];

inline bool cmpQuery(const typeQuery &a,const typeQuery &b)
{
    return a.R>b.R;
}

inline void Insert(int num,int l,int r,int pos,int key)
{
    if (l==r){
        Tree[num]=max(Tree[num],key);
        return;
    }
    int mid=(l+r)/2;
    if (pos<=bak[mid]) Insert(num*2,l,mid,pos,key);
    else Insert(num*2+1,mid+1,r,pos,key);
    Tree[num]=max(Tree[num*2],Tree[num*2+1]);
}

inline int Query(int num,int l,int r,int ll,int rr)
{
    if (ll>bak[r] || rr<bak[l]) return -1;
    if (ll<=bak[l] && bak[r]<=rr) return Tree[num];
    int mid=(l+r)/2;
    return max( Query(num*2,l,mid,ll,rr), Query(num*2+1,mid+1,r,ll,rr) );
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i].r);
        R[i]=a[i].r;
    }
    N=0;
    for (int i=0;i<n;++i){
        scanf("%d",&a[i].a);
        A[i]=a[i].a;
        bak[N++]=a[i].a;
    }
    sort(bak,bak+N);
    N=unique(bak,bak+N)-bak;
    
    sort(a,a+n,cmp);
    for (int i=0;i<n;++i){
        int j=i+1;
        while (j<n && a[j].r==a[i].r) ++j;
        
        for (int it=i;it<j;++it){
            g[it]=getSum(a[it].a-k,a[it].a+k);
//printf("%d %d\n",a[it].r,g[it]);
            node l,r;
            r=a[it];r.a+=k;
            l=a[it];l.a-=k;
            g[it]+=upper_bound(a+i,a+j,r,cmpAge)-lower_bound(a+i,a+j,l,cmpAge);
        }
        
        for (int it=i;it<j;++it){
            add((lower_bound(bak,bak+N,a[it].a)-bak)+1);
        }
        i=j-1;
    }
    
//  for (int i=0;i<n;++i)
//      printf("%d %d\n",a[i].r,g[i]);
    
    int Q;
    scanf("%d",&Q);
    for (int i=0;i<Q;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        --x;--y;
        query[i].R=max(R[x],R[y]);
        query[i].l=max(A[x]-k,A[y]-k);
        query[i].r=min(A[x]+k,A[y]+k);
        query[i].flag=true;
        
        //if (A[x]<query[i].l || A[x]>query[i].r) query[i].flag=false;
        //if (A[y]<query[i].l || A[y]>query[i].r) query[i].flag=false;
        if (query[i].l>query[i].r){
            query[i].flag=false;
        }
        
        query[i].id=i;
    }
    sort(query,query+Q,cmpQuery);
    
    memset(Tree,-1,sizeof(Tree));
    
    for (int i=0,j=n-1;i<Q;++i){
        while (j>=0 && a[j].r>=query[i].R){
//printf("  insert  %d %d\n",a[j].a,g[j]);
            Insert(1,0,N-1,a[j].a,g[j]);
            --j;
        }
//printf("id=   %d  R=  %d  l=  %d  r=  %d\n",query[i].id,query[i].R,query[i].l,query[i].r);
//printf("query=    %d\n",Query(1,0,N-1,query[i].l,query[i].r));
        if (query[i].flag) out[query[i].id]=Query(1,0,N-1,query[i].l,query[i].r);
        else out[query[i].id]=-1;
    }
    
    for (int i=0;i<Q;++i)
        printf("%d\n",out[i]);
    
    return 0;
}