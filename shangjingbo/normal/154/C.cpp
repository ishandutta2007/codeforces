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

const int maxn  =   1000005;

int n,m;
ULL pw[maxn],h[maxn];
vector<ULL> a;
VI adj[maxn];

const ULL magic =   37;

int main()
{
    scanf("%d%d",&n,&m);
    pw[0]=1;
    for (int i=1;i<=n;++i) pw[i]=pw[i-1]*magic;
    
    for (int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].PB(b);
        adj[b].PB(a);
    }
    long long ans=0;
    for (int i=1;i<=n;++i){
        sort(adj[i].begin(),adj[i].end());
        for (int j=0;j<adj[i].size();++j){
            int v=adj[i][j];
            h[i]+=pw[v];
        }
        a.PB(h[i]);
    }
    sort(a.begin(),a.end());
    for (int i=0;i<a.size();++i){
        int j=i;
        while (j<n && a[j]==a[i]) ++j;
        
        ans+=(LL)(j-i)*(j-i-1)/2;
        
        i=j-1;
    }
    
    for (int i=1;i<=n;++i){
        for (int j=0;j<adj[i].size();++j){
            int v=adj[i][j];
            if (i<v && h[v]-pw[i]==h[i]-pw[v]) ++ans;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}