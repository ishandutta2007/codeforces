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

const int maxn  =   300005;

VI adj[maxn];
int jump[maxn][20],dep[maxn],cover[maxn],sum[maxn],n,Q,out[maxn];

inline int getLca(int a,int b)
{
    int i=19;
    while (dep[b]>dep[a]){
        while (dep[jump[b][i]]<dep[a]) --i;
        b=jump[b][i];
    }
    if (a==b) return a;
    i=19;
    while (jump[a][0]!=jump[b][0]){
        while (jump[a][i]==jump[b][i]) --i;
        a=jump[a][i];
        b=jump[b][i];
    }
    return jump[a][0];
}

inline void dfs(int u,int fa)
{
    jump[u][0]=fa;
    for (int i=0;jump[u][i] && jump[ jump[u][i] ][i];++i){
        jump[u][i+1]=jump[ jump[u][i] ][i];
    }
    dep[u]=dep[fa]+1;
    
    for (int i=0;i<adj[u].size();++i)
    if (adj[u][i]!=fa)
        dfs(adj[u][i],u);
}

map<PII,int> hash;

inline void getAns(int u,int fa)
{
    sum[u]=0;
    for (int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if (v!=fa){
            getAns(v,u);
            out[hash[MP(u,v)]]=sum[v]+cover[v];
            sum[u]+=sum[v]+cover[v];
        }
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].PB(b);
        adj[b].PB(a);
        hash[MP(a,b)]=hash[MP(b,a)]=i;
    }
    
    dep[0]=-1;
    dfs(1,0);
    
    scanf("%d",&Q);
    for (int i=0;i<Q;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        if (dep[a]>dep[b]) swap(a,b);
        int lca=getLca(a,b);
        if (lca==a){
            ++cover[b];
            --cover[a];
        }else{
            ++cover[b];
            ++cover[a];
            cover[lca]-=2;
        }
    }
    
    getAns(1,0);
    
    for (int i=1;i<n;++i) printf("%d ",out[i]);
    
    return 0;
}