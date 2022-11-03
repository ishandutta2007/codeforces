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

const int maxn  =   5005;

int n;
vector<PII> adj[maxn];
int mark[maxn],stamp;
int size[maxn],total;
long long f[maxn],g[maxn];
set<PII> forbid;

long long current;

inline void dfs2(int u,int fa)
{
    for (int i=0;i<(int)adj[u].size();++i){
        int v=adj[u][i].first;
        long long c=adj[u][i].second;
        if (v==fa || forbid.count(MP(u,v))){
            continue;
        }
        current+=c*size[v]*(total-size[v]);
        g[v]=g[u]-c*size[v]+c*(total-size[v]);
        dfs2(v,u);
    }
}

inline void dfs(int u,int fa)
{
    mark[u]=stamp;
    ++total;
    f[u]=0;
    size[u]=1;
    for (int i=0;i<(int)adj[u].size();++i){
        int v=adj[u][i].first;
        long long c=adj[u][i].second;
        if (v==fa || forbid.count(MP(u,v))){
            continue;
        }
        dfs(v,u);
        f[u]+=f[v]+c*size[v];
        size[u]+=size[v];
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].PB(MP(b,c));
        adj[b].PB(MP(a,c));
    }
    
    long long ans=1000000000000000000LL;
    for (int i=1;i<=n;++i){
        for (int j=0;j<(int)adj[i].size();++j){
            int v=adj[i][j].first;
            if (i<v){
                forbid.clear();
                forbid.insert(MP(i,v));
                forbid.insert(MP(v,i));
                
                long long cur=0;
                
                ++stamp;
                total=0;
                dfs(i,-1);
                g[i]=f[i];
                current=0;
                dfs2(i,-1);
                cur+=current;
                
                long long left=g[i],leftSize=0;
                for (int u=1;u<=n;++u){
                    if (mark[u]==stamp){
                        left=min(left,g[u]);
                        ++leftSize;
                    }
                }
                
                ++stamp;
                total=0;
                dfs(v,-1);
                g[v]=f[v];
                current=0;
                dfs2(v,-1);
                cur+=current;
                
                long long right=g[v],rightSize=0;
                for (int u=1;u<=n;++u){
                    if (mark[u]==stamp){
                        right=min(right,g[u]);
                        ++rightSize;
                    }
                }
                
                cur+=left*rightSize+right*leftSize+leftSize*rightSize*adj[i][j].second;
/*cout << i << " " << v << endl;
cout << left << " " << right << endl;
cout << leftSize << " " << rightSize << endl;
cout << cur << endl;
cout << endl;*/
                ans=min(ans,cur);
            }
        }
    }
    
    printf("%I64d\n",ans);
    
    return 0;
}