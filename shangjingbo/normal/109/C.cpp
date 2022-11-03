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

#define maxn 100005

int head[maxn],vtx[maxn*2],next[maxn*2],cost[maxn*2],tot;
int f[maxn],g[maxn],n,sum[maxn];

inline bool isLucky(int x)
{
    while (x>0){
        int t=x%10;
        if (t!=4 && t!=7) return false;
        x/=10;
    }
    return true;
}

inline void Add(int a,int b,int c)
{
    vtx[tot]=b;
    next[tot]=head[a];
    cost[tot]=c;
    head[a]=tot++;
}

inline void dfs(int u,int fa)
{
    sum[u]=1;
    f[u]=0;
    for (int p=head[u];p;p=next[p]) if (vtx[p]!=fa){
        dfs(vtx[p],u);
        sum[u]+=sum[vtx[p]];
        if (cost[p]) f[u]+=sum[vtx[p]];
        else f[u]+=f[vtx[p]];
    }
}

inline void change(int u,int fa)
{
    for (int p=head[u];p;p=next[p]) if (vtx[p]!=fa){
        int v=vtx[p];
        if (cost[p]) g[v]=f[v]+n-sum[v];
        else g[v]=g[u];
        change(vtx[p],u);
    }
}

int main()
{
    scanf("%d",&n);
    memset(head,0,sizeof(head));
    tot=2;
    for (int i=1;i<n;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        c=isLucky(c);
        Add(a,b,c);
        Add(b,a,c);
    }
    
    dfs(1,0);
    g[1]=f[1];
    change(1,0);
    
    LL ans=0;
    for (int i=1;i<=n;++i) ans+=(LL)g[i]*(LL)(g[i]-1);
    cout << ans << endl;
    
    return 0;
}