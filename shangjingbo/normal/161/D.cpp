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

long long sum[505];
int value[50005][505];
VI adj[50005],son[50005];
int n,k;

inline void dfs(int u,int fa)
{
    for (int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if (v==fa) continue;
        son[u].PB(v);
        dfs(v,u);
    }
}

inline void dfs(int st,int u,int dep)
{
    //printf("%d %d %d\n",st,u,dep);
    ++value[st][dep];
    ++sum[dep];
    if (dep==k) return;
    
    for (int i=0;i<son[u].size();++i)
        dfs(st,son[u][i],dep+1);
}
    

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    dfs(1,-1);
    
    long long ans=0;
    for (int i=1;i<=n;++i){
        for (int j=0;j<=k;++j) sum[j]=0;
        for (int j=0;j<son[i].size();++j)
            dfs(son[i][j],son[i][j],1);
        ans+=sum[k]*2LL;
        for (int j=0;j<son[i].size();++j){
            int v=son[i][j];
            for (int dep=1;dep<=k;++dep)
                ans+=value[v][dep]*(sum[k-dep]-value[v][k-dep]);
        }
    }
    cout << ans/2 << endl;
    
    return 0;
}