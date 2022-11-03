#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
using namespace std;

#define PB push_back
#define MP make_pair

#define FOR(it,a) for (__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

inline int sign(double x)
{
    if (x<-eps) return -1;
    return x>eps;
}

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double x,double y):x(x),y(y){}
    inline double norm(){return sqrt(x*x+y*y);}
    inline void rotate(double ang)
    {
        double co=cos(ang),si=sin(ang);
        double tx=x,ty=y;
        x=tx*co-ty*si;
        y=tx*si+ty*co;
    }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){return Tpoint(a.x+b.x,a.y+b.y);}
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){return Tpoint(a.x-b.x,a.y-b.y);}
inline Tpoint operator *(const Tpoint &a,const double &b){return Tpoint(a.x*b,a.y*b);}
inline Tpoint operator /(const Tpoint &a,const double &b){return Tpoint(a.x/b,a.y/b);}
inline double det(const Tpoint &a,const Tpoint &b){return a.x*b.y-a.y*b.x;}
inline double dot(const Tpoint &a,const Tpoint &b){return a.x*b.x+a.y*b.y;}
//================================

const int maxn  =   405;

int n,x[maxn],y[maxn];

const int maxnode   =   maxn+maxn+2;
const int maxedge   =   (maxn*maxn+2*maxn)*2;

int head[maxnode],vtx[maxedge],c[maxedge],tot,next[maxedge];
double cost[maxedge],dist[maxedge],Tcost;
int pre[maxnode],s,t,flow;
bool vis[maxnode];

inline void add(int a,int b,int cc,double cst)
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

inline double calc(double x,double y,double a,double b)
{
    return sqrt( sqr(x-a)+sqr(y-b) );
}

inline bool spfa()
{
    queue<int> q;
    q.push(s);
    for (int i=0;i<=t;++i){
        dist[i]=1e100;
        vis[i]=false;
    }
    dist[s]=0;
    while (q.size()){
        int u=q.front();
        vis[u]=false;
        q.pop();
        for (int p=head[u];p;p=next[p]){
            if (c[p] && dist[vtx[p]]>dist[u]+cost[p]+eps){
                dist[vtx[p]]=dist[u]+cost[p];
                pre[vtx[p]]=p;
                if (!vis[vtx[p]]){
                    vis[vtx[p]]=true;
                    q.push(vtx[p]);
                }
            }
        }
    }
    return dist[t]<1e90;
}

inline void push()
{
    for (int u=t,p;u!=s;u=vtx[p]){
        p=pre[u];
        --c[p];
        ++c[p^=1];
    }
    Tcost+=dist[t];
    ++flow;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d%d",&x[i],&y[i]);
    }
    int maxy=*max_element(y,y+n);
    int root,cnt=0;
    for (int i=0;i<n;++i){
        if (y[i]==maxy){
            root=i;
            ++cnt;
        }
    }
    if (cnt>1){
        puts("-1");
        return 0;
    }
    
    tot=2;
    memset(head,0,sizeof(head));
    s=n+n;t=s+1;
    for (int i=0;i<n;++i){
        add(s,i,2,0);
        if (i!=root){
            add(i+n,t,1,0);
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (y[i]>y[j]){
                add(i,j+n,1,calc(x[i],y[i],x[j],y[j]));
            }
        }
    }
    
    flow=0;
    Tcost=0;
    while (spfa()){
        push();
    }
    if (flow!=n-1){
        puts("-1");
    }else{
        printf("%.10f\n",Tcost);
    }
    
    return 0;
}