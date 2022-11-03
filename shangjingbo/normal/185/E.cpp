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

const int inf   =   1000000000;
const int maxn  =   200005;

struct node
{
    int x,y;
}a[maxn],b[maxn];
int n,m,dist[maxn];
vector< pair<node,int> > event;
int Tree[maxn*4];

inline bool cmp1(const pair<node,int> &a,const pair<node,int> &b)
{
    if (a.first.y!=b.first.y) return a.first.y<b.first.y;
    return a.second<b.second;
}

inline bool cmp2(const pair<node,int> &a,const pair<node,int> &b)
{
    if (a.first.y!=b.first.y) return a.first.y<b.first.y;
    return a.second<b.second;
}

inline bool cmp3(const pair<node,int> &a,const pair<node,int> &b)
{
    if (a.first.y!=b.first.y) return a.first.y>b.first.y;
    return a.second<b.second;
}

inline bool cmp4(const pair<node,int> &a,const pair<node,int> &b)
{
    if (a.first.y!=b.first.y) return a.first.y>b.first.y;
    return a.second<b.second;
}

vector<int> bakx;

inline void build(int num,int l,int r)
{
    Tree[num]=-inf;
    if (l==r) return;
    int mid=(l+r)/2;
    build(num*2,l,mid);
    build(num*2+1,mid+1,r);
}

inline void insert(int num,int l,int r,int pos,int key)
{
    if (bakx[l]<=pos && pos<=bakx[r]){
        Tree[num]=max(Tree[num],key);
    }else return;
    if (l==r) return;
    int mid=(l+r)/2;
    insert(num*2,l,mid,pos,key);
    insert(num*2+1,mid+1,r,pos,key);
}

inline int query(int num,int l,int r,int ll,int rr)
{
//printf("%d %d %d %d   %d\n",bakx[l],bakx[r],ll,rr,Tree[num]);
    if (ll<=bakx[l] && bakx[r]<=rr) return Tree[num];
    if (bakx[l]>rr || ll>bakx[r]) return -inf;
    int mid=(l+r)/2;
    return max( query(num*2,l,mid,ll,rr),query(num*2+1,mid+1,r,ll,rr) );
}

inline bool cmpDist(const int &i,const int &j)
{
    return dist[i]>dist[j];
}

set<int> treeNode[maxn*4];
vector<int> bak;
int id[maxn];

inline void insert(int num,int l,int r,node a)
{
    if (bak[l]<=a.x && a.x<=bak[r]){
        treeNode[num].insert(a.y);
    }else return;
    if (l==r) return;
    int mid=(l+r)/2;
    insert(num*2,l,mid,a);
    insert(num*2+1,mid+1,r,a);
}

inline bool query(int num,int l,int r,int xl,int xr,int yl,int yr)
{
    if (xl<=bak[l] && bak[r]<=xr){
        set<int>::iterator it=treeNode[num].lower_bound(yl);
        if (it==treeNode[num].end()) return false;
        return *it<=yr;
    }
    if (bak[l]>xr || bak[r]<xl) return false;
    int mid=(l+r)/2;
    return query(num*2,l,mid,xl,xr,yl,yr) || query(num*2+1,mid+1,r,xl,xr,yl,yr);
}

inline bool check(int limit)
{
    int xl=-inf,xr=inf,yl=-inf,yr=inf;
    for (int i=0;i<n;++i){
        int u=id[i];
        xl=max(xl,a[u].x+a[u].y-limit);
        xr=min(xr,a[u].x+a[u].y+limit);
        yl=max(yl,a[u].x-a[u].y-limit);
        yr=min(yr,a[u].x-a[u].y+limit);
        
        if (xl>xr) return false;
        if (yl>yr) return false;
        
        if (i+1==n) return true;
        
        if (dist[id[i+1]]<=limit){
            int delta=limit-dist[id[i+1]];
            if (query(1,0,bak.size()-1,xl-delta,xr+delta,yl-delta,yr+delta)) return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    event.clear();
    bakx.clear();
    for (int i=0;i<n;++i){
        scanf("%d%d",&a[i].x,&a[i].y);
        event.push_back(MP(a[i],i));
        bakx.push_back(a[i].x);
        dist[i]=inf;
    }
    
    for (int i=0;i<m;++i){
        scanf("%d%d",&b[i].x,&b[i].y);
        event.push_back(MP(b[i],-1));
        bakx.push_back(b[i].x);
    }
    sort(bakx.begin(),bakx.end());
    bakx.erase(unique(bakx.begin(),bakx.end()),bakx.end());
    
    sort(event.begin(),event.end(),cmp1);
    build(1,0,bakx.size()-1);
    for (int i=0;i<event.size();++i){
        if (event[i].second==-1){
//printf("insert    %d  %d\n",event[i].first.x,event[i].first.x+event[i].first.y);
            insert(1,0,bakx.size()-1,event[i].first.x,event[i].first.x+event[i].first.y);
        }else{
//printf("query %d  %d\n",event[i].first.x,query(1,0,bakx.size()-1,-inf,event[i].first.x));
            dist[event[i].second]=event[i].first.x+event[i].first.y-query(1,0,bakx.size()-1,-inf,event[i].first.x);
        }
    }
    
    sort(event.begin(),event.end(),cmp2);
    build(1,0,bakx.size()-1);
    for (int i=0;i<event.size();++i){
        if (event[i].second==-1){
//printf("insert    %d  %d\n",event[i].first.x,event[i].first.y);
            insert(1,0,bakx.size()-1,event[i].first.x,-event[i].first.x+event[i].first.y);
        }else{
//printf("query %d  %d\n",event[i].first.x,query(1,0,bakx.size()-1,event[i].first.x,inf));
            dist[event[i].second]=min(dist[event[i].second],-event[i].first.x+event[i].first.y-query(1,0,bakx.size()-1,event[i].first.x,inf));
        }
    }
    
    sort(event.begin(),event.end(),cmp3);
    build(1,0,bakx.size()-1);
    for (int i=0;i<event.size();++i){
        if (event[i].second==-1){
            insert(1,0,bakx.size()-1,event[i].first.x,-event[i].first.x-event[i].first.y);
        }else{
            dist[event[i].second]=min(dist[event[i].second],-event[i].first.x-event[i].first.y-query(1,0,bakx.size()-1,event[i].first.x,inf));
        }
    }
    
    sort(event.begin(),event.end(),cmp4);
    build(1,0,bakx.size()-1);
    for (int i=0;i<event.size();++i){
        if (event[i].second==-1){
            insert(1,0,bakx.size()-1,event[i].first.x,event[i].first.x-event[i].first.y);
        }else{
            dist[event[i].second]=min(dist[event[i].second],event[i].first.x-event[i].first.y-query(1,0,bakx.size()-1,-inf,event[i].first.x));
        }
    }
    
    for (int i=0;i<n;++i) id[i]=i;
    sort(id,id+n,cmpDist);
    
/*  for (int i=0;i<n;++i){
        printf("%d ",dist[i]);
    }
    puts("");*/
    
    bak.clear();
    for (int i=0;i<m;++i){
        bak.PB(b[i].x+b[i].y);
    }
    sort(bak.begin(),bak.end());
    bak.erase(unique(bak.begin(),bak.end()),bak.end());
    for (int i=0;i<m;++i){
        node cur;
        cur.x=b[i].x+b[i].y;
        cur.y=b[i].x-b[i].y;
        insert(1,0,bak.size()-1,cur);
    }
    
    int l=-1,r=dist[id[0]];
    while (l+1<r){
        int mid=(l+r)/2;
        if (check(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    
    return 0;
}