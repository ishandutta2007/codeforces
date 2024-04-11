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

int n,m,s,t,f[maxn],k;
bool vis[maxn],hasV[maxn];
queue<int> q;
vector<int> adj[maxn];

inline bool check(int limit)
{
    for (int i=0;i<n;++i){
        f[i]=-1;
        vis[i]=false;
    }
    f[s]=limit;
    vis[s]=true;
    while (q.size()>0) q.pop();
    
    q.push(s);
    
    while (q.size()){
        int u=q.front();
        q.pop();
        vis[u]=false;
//printf("%d %d\n",u,f[u]);
        if (f[u]>0){
            for (int i=0;i<adj[u].size();++i){
                int v=adj[u][i];
                int cost=f[u]-1;
                if (hasV[v]) cost=limit;
                if (f[v]<cost){
                    f[v]=cost;
                    if (v==t) return true;
                    if (!vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(hasV,false,sizeof(hasV));
    for (int i=0;i<k;++i){
        int x;
        scanf("%d",&x);
        --x;
        hasV[x]=true;
    }
    for (int i=0;i<n;++i) adj[i].clear();
    for (int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    scanf("%d%d",&s,&t);
    --s;--t;
    
    if (!check(n)){
        puts("-1");
        return 0;
    }
    
    int l=-1,r=n;
    while (l+1<r){
        int mid=(l+r)/2;
//printf("  %d %d %d %d\n",l,r,mid,check(mid));
        if (check(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    return 0;
}