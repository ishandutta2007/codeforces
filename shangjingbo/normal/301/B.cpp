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

const int maxn  =   105;

int n,d,a[maxn],x[maxn],y[maxn];
bool vis[maxn];
int dist[maxn];

inline bool update(int &a,int b)
{
    if (a==-1 || a>b) {
        a=b;
        return true;
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&d);
    for (int i=1;i<n-1;++i){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;++i){
        scanf("%d%d",&x[i],&y[i]);
    }
    queue<int> q;
    q.push(n-1);
    memset(dist,-1,sizeof(dist));
    memset(vis,false,sizeof(vis));
    dist[n-1]=0;
    vis[n-1]=true;
    while (q.size()){
        int u=q.front();
        q.pop();
        vis[u]=false;
//printf("%d %d\n",u,dist[u]);
        for (int v=0;v<n;++v){
            if (u==v){
                continue;
            }
            int cost = abs(x[u]-x[v]) + abs(y[u]-y[v]);
            cost *= d;
            if (update(dist[v], max(dist[u] + cost - a[v], 0))) {
//printf("  %d->%d %d\n",u,v,dist[v]);
                if (!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    printf("%d\n",dist[0]);
    
    return 0;
}