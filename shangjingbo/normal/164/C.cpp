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

const int maxn  =   1005*2+10;
const int maxm  =   (maxn*4+maxn*2)*2+5;
const int inf   =   1000000000;

int head[maxn],vtx[maxm],next[maxm],c[maxm],cost[maxm],tot;
int s,t,dist[maxn],pre[maxn];
bool vis[maxn],sp[maxm];

inline void add(int a,int b,int cc,int cst)
{
    vtx[tot]=b;
    next[tot]=head[a];
    c[tot]=cc;
    cost[tot]=cst;
    head[a]=tot++;
    
    vtx[tot]=a;
    next[tot]=head[b];
    c[tot]=0;
    cost[tot]=-cst;
    head[b]=tot++;
}

inline void push()
{
    for (int u=t,p;u!=s;u=vtx[p]){
        p=pre[u];
        --c[p];
        ++c[p^=1];
    }
}

queue<int> q;

inline bool spfa()
{
    for (int i=0;i<=t;++i) dist[i]=-inf;
    memset(vis,false,sizeof(vis));
    dist[s]=0;
    q.push(s);
    vis[s]=true;
    while (q.size()){
        int u=q.front();
        q.pop();
        vis[u]=false;
        for (int p=head[u];p;p=next[p])
        if (c[p] && dist[vtx[p]]<dist[u]+cost[p]){
            dist[vtx[p]]=dist[u]+cost[p];
            pre[vtx[p]]=p;
            if (!vis[vtx[p]]){
                vis[vtx[p]]=true;
                q.push(vtx[p]);
            }
        }
    }
    return dist[t]>=0;
}

struct node
{
    int s,l,v;
    int id;
}a[maxn];

inline bool cmp(const node &a,const node &b)
{
    return a.s<b.s;
}

int ans[maxn];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;++i){
        scanf("%d%d%d",&a[i].s,&a[i].l,&a[i].v);
        a[i].id=i;
    }
    sort(a,a+n,cmp);
    memset(head,0,sizeof(head));
    tot=2;
    s=n+n;t=s+1;
    for (int i=0;i<n;++i){
        sp[tot]=sp[tot+1]=true;
        add(i,i+n,1,a[i].v);
        add(i,i+n,k,0);
        add(s,i,k,0);
        add(i+n,t,k,0);
    }
    for (int i=0;i+1<n;++i){
        add(i,i+1,k,0);
    }
    for (int i=0;i<n;++i){
        int next=-1;
        for (int j=0;j<n;++j)
        if (i!=j && a[i].s+a[i].l<=a[j].s){
            if (next==-1 || a[j].s<a[next].s) next=j;
        }
        if (next!=-1){
            add(i+n,next,k,0);
        }
    }
    
    for (int it=0;it<k && spfa();++it){
        push();
    }
    
    for (int i=0;i<n;++i){
        int out=0;
        for (int p=head[i];p;p=next[p])if (sp[p]){
            if (!c[p]) out=1;
            else out=0;
        }
        //printf("%d ",out);
        ans[a[i].id]=out;
    }
    for (int i=0;i<n;++i)
        printf("%d ",ans[i]);
    
    return 0;
}