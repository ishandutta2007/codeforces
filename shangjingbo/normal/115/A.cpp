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

#define maxn 2005

VI Adj[maxn];
int n;
bool isRoot[maxn];

inline int dfs(int u)
{
    int res=1;
    for (int i=0;i<Adj[u].size();++i)
        res=max(res,dfs(Adj[u][i])+1);
    return res;
}

int main()
{
    scanf("%d",&n);
    memset(isRoot,true,sizeof(isRoot));
    for (int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        if (x!=-1){
            Adj[x].PB(i);
            isRoot[i]=false;
        }
    }
    
    int ans=0;
    for (int i=1;i<=n;++i) if (isRoot[i]){
        ans=max(ans,dfs(i));
    }
    
    printf("%d\n",ans);

    //while (1);
    
    return 0;
}