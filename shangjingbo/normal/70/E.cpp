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
const int inf   =   1000000000;

#define maxn 200

int n,build,d[maxn][maxn],pay[maxn];
int f[maxn][maxn];
VI Adj[maxn];

inline int dfs(int u,int to,int fa)
{
    int &res=f[u][to];
    if (res!=-1) return res;
    res=min(build,pay[d[u][to]]);
    for (int i=0;i<Adj[u].size();++i){
        int v=Adj[u][i];
        if (v==fa) continue;
        int t=inf;
        for (int j=1;j<=n;++j){
            t=min(t,dfs(v,j,u)+(j!=to || build<pay[d[u][to]] && j==u)*build);
        }
        res+=t;
    }
    return res;
}

int mark[maxn];

inline void output(int u,int to,int fa)
{
    mark[u]=to;
    if (build<pay[d[u][to]]) mark[u]=u;
    for (int i=0;i<Adj[u].size();++i){
        int v=Adj[u][i];
        if (v==fa) continue;
        int t=inf;
        for (int j=1;j<=n;++j){
            t=min(t,dfs(v,j,u)+(j!=to || build<pay[d[u][to]] && j==u)*build);
        }
        for (int j=1;j<=n;++j)
        if (t==(dfs(v,j,u)+(j!=to || build<pay[d[u][to]] && j==u)*build)){
            output(v,j,u);
            break;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&build);
    //n=180;
    //build=1;
    for (int i=1;i<n;++i)
        //pay[i]=100000;
        scanf("%d",&pay[i]);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)
            d[i][j]=inf;
        d[i][i]=0;
    }
    for (int i=1;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        //a=i;b=i+1;
        Adj[a].PB(b);
        Adj[b].PB(a);
        d[a][b]=d[b][a]=1;
    }
    
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    memset(f,-1,sizeof(f));
    int ans=inf;
    for (int i=1;i<=n;++i)
        ans=min(ans,dfs(1,i,0)+build);
    
    printf("%d\n",ans);
    
    for (int i=1;i<=n;++i){
        if (dfs(1,i,0)+build==ans){
            output(1,i,0);
            break;
        }
    }
    for (int i=1;i<=n;++i) printf("%d ",mark[i]);
    
    return 0;
}