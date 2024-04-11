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

const int maxn  =   100005;

queue<int> q;
VI adj[maxn],xxx[maxn];
int n,m,f[maxn];
bool mark[maxn],vis[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&f[i]);
    for (int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[b].PB(a);
        xxx[a].PB(b);
    }
    
    memset(mark,0,sizeof(mark));
    for (int i=1;i<=n;++i)if (f[i]==2){
        q.push(i);
        mark[i]=1;
    }
    
    while (q.size()){
        int u=q.front();
        q.pop();
        if (f[u]==1) continue;
        for (int i=0;i<adj[u].size();++i){
            int v=adj[u][i];
            if (!mark[v]){
                mark[v]=1;
                q.push(v);
            }
        }
    }
    
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;++i)if (f[i]==1){
        q.push(i);
        vis[i]=1;
    }
    while (q.size()){
        int u=q.front();
        q.pop();
        for (int i=0;i<xxx[u].size();++i){
            int v=xxx[u][i];
            if (!vis[v] && f[v]!=1){
                vis[v]=1;
                q.push(v);
            }
        }
    }
    
    for (int i=1;i<=n;++i){
        if (vis[i] && mark[i]) puts("1");
        else puts("0");
    }

    return 0;
}