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

#define PB push_back
#define MP make_pair

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))

typedef double LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double a,double b){x=a;y=b;}
    inline double norm(){return sqrt(sqr(x)+sqr(y));}
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){return Tpoint(a.x+b.x,a.y+b.y);}
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){return Tpoint(a.x-b.x,a.y-b.y);}
inline Tpoint operator *(const Tpoint &a,const double &b){return Tpoint(a.x*b,a.y*b);}
inline Tpoint operator /(const Tpoint &a,const double &b){return Tpoint(a.x/b,a.y/b);}
inline double dot(const Tpoint &a,const Tpoint &b){return a.x*b.x+a.y*b.y;}
inline double det(const Tpoint &a,const Tpoint &b){return a.x*b.y-a.y*b.x;}
//==============================================================================================

const int maxn  =   1000005;

int a[maxn],id[maxn],n;

inline bool cmp(const int &i,const int &j)
{
    return a[i]>a[j] || a[i]==a[j] && i<j;
}

struct node
{
    double st,d;
}tree[maxn*4];
int Left[maxn],Right[maxn];

inline int Find(int x,int f[])
{
    if (x==f[x]) return x;
    return f[x]=Find(f[x],f);
}

inline void cover(int num,int l,int r,int ll,int rr,double st,double d)
{
//printf("%d %d %d %d %d\n",num,l,r,ll,rr);
    if (l==ll && r==rr){
        tree[num].st+=st;
        tree[num].d+=d;
        return;
    }
    int mid=(l+r)/2;
    if (rr<=mid) cover(num*2,l,mid,ll,rr,st,d);
    else if (ll>mid) cover(num*2+1,mid+1,r,ll,rr,st,d);
    else{
        cover(num*2,l,mid,ll,mid,st,d);
        cover(num*2+1,mid+1,r,mid+1,rr,st+d*(mid+1-ll),d);
    }
}

inline double query(int num,int l,int r,int pos)
{
    if (l==r) return tree[num].st;
    int mid=(l+r)/2;
    double delta=tree[num].st+tree[num].d*(pos-l);
    if (pos<=mid) return query(num*2,l,mid,pos)+delta;
    return query(num*2+1,mid+1,r,pos)+delta;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
//a[i]=rand()%100+1;printf("%d ",a[i]);
        scanf("%d",&a[i]);
    }
//puts("");
    for (int i=1;i<=n;++i) id[i]=i;
    sort(id+1,id+n+1,cmp);
    
    for (int i=0;i<=n+1;++i){
        Left[i]=i;
        Right[i]=i;
    }
    
    for (int it=1;it<=n;++it){
        int i=id[it];
        int L=i-Find(i-1,Left)-1;
        int R=Find(i+1,Right)-i-1;
        int s1=1,s2=L+1;
        int t1=R+1,t2=L+R+1;
    
//printf("%d %d:%d %d   %d\n",s1,t1,s2,t2,a[i]);
        
        if (t1<=s2){
            if (s1<=t1-1) cover(1,1,n,s1,t1-1,a[i],a[i]);
            if (t1<=s2) cover(1,1,n,t1,s2,(LL)(R+1)*a[i],0);
            if (s2+1<=t2) cover(1,1,n,s2+1,t2,(LL)R*a[i],-a[i]);
        }else{
            if (s1<=s2-1) cover(1,1,n,s1,s2-1,a[i],a[i]);
            if (s2<=t1) cover(1,1,n,s2,t1,(LL)(s2-s1+1)*a[i],0);
            if (t1+1<=t2) cover(1,1,n,t1+1,t2,(LL)(s2-s1)*a[i],-a[i]);
        }
//puts("hi");
        Left[i]=i-1;
        Right[i]=i+1;
    }
    
    int Q;
    scanf("%d",&Q);
    for (int i=0;i<Q;++i){
        int k=i+1;
        scanf("%d",&k);
        double sum=query(1,1,n,k);
        printf("%.10f\n",sum/(n-k+1));
        
/*double s=0;
for (int j=1;j+k<=n+1;++j){
    double mi=a[j];
    for (int x=0;x<k;++x){
        mi=min(mi,(double)a[j+x]);
    }
    s+=mi;
}
printf("    %.10f\n",s/(n-k+1));*/
    }
    
    return 0;
}