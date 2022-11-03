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
const int maxn  =   65;
const int limit =   61;

struct node
{
    int s,u,t;
    node(){}
    node(int a,int b,int c){s=a;u=b;t=c;}
};

queue<node> q;
bool vis[maxn][maxn][limit+1];
int f[maxn][maxn][limit+1];
int n,m,r,dist[maxn][maxn],d[maxn][maxn];

int main()
{
    scanf("%d%d%d",&n,&m,&r);
    
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j) dist[i][j]=inf;
    for (int _=0;_<m;++_){
        for (int s=0;s<n;++s)
            for (int t=0;t<n;++t)
                scanf("%d",&d[s][t]);
        for (int k=0;k<n;++k)
            for (int i=0;i<n;++i)
                for (int j=0;j<n;++j)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                dist[i][j]=min(dist[i][j],d[i][j]);
    }
    
    memset(f,-1,sizeof(f));
    memset(vis,false,sizeof(vis));
    for (int i=0;i<n;++i){
        f[i][i][0]=0;
        q.push(node(i,i,0));
        vis[i][i][0]=true;
    }
    
    while (q.size()){
        int u=q.front().u,s=q.front().s,t=q.front().t;
        q.pop();
        vis[s][u][t]=false;
        if (t==limit) continue;
        for (int v=0;v<n;++v){
            if (f[s][v][t+1]==-1 || f[s][v][t+1]>f[s][u][t]+dist[u][v]){
                f[s][v][t+1]=f[s][u][t]+dist[u][v];
                if (!vis[s][v][t+1]){
                    vis[s][v][t+1]=true;
                    q.push(node(s,v,t+1));
                }
            }
        }
    }
    
    for (;r>0;--r){
        int s,t,k;
        scanf("%d%d%d",&s,&t,&k);
        --s;--t;++k;
        int ans=-1;
        for (int i=0;i<=k && i<=limit;++i)
        if (f[s][t][i]!=-1){
            if (ans==-1 || ans>f[s][t][i]){
                ans=f[s][t][i];
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}