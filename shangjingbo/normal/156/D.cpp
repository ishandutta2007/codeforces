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

int n,m,base;
VI adj[maxn];
queue<int> q;
int color[maxn],N,a[maxn];

inline void flood(int s)
{
    while (q.size()) q.pop();
    q.push(s);
    color[s]=++N;
    a[N]=0;
    while (q.size()){
        int u=q.front();
        q.pop();
        ++a[N];
        for (int i=0;i<adj[u].size();++i){
            int v=adj[u][i];
            if (color[v]==-1){
                color[v]=N;
                q.push(v);
            }
        }
    }
}

inline int powmod(int x,int t,int base)
{
    if (!t) return 1%base;
    int y=powmod(x,t>>1,base);
    y=(LL)y*y%base;
    if (t&1) y=(LL)y*x%base;
    return y;
}

int main()
{
    scanf("%d%d%d",&n,&m,&base);
    
    for (int i=1;i<=n;++i) adj[i].clear();
    
    for (int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    N=0;
    memset(color,-1,sizeof(color));
    for (int i=1;i<=n;++i)
    if (color[i]==-1){
        flood(i);
    }
    
    if (N==1){
        printf("%d\n",1%base);
        return 0;
    }
    
    if (N==2){
        printf("%d\n",(LL)a[1]*a[2]%base);
        return 0;
    }
    
    --N;
    
    int ans=1;
    for (int i=1;i<=N;++i) ans=(LL)ans*a[i]%base;
    
    int sum=0;
    for (int i=1;i<=N;++i){
        if (i==1){
            int tmp=(n-a[i])%base;
            tmp=(LL)tmp*powmod(n,N-1,base)%base;
            sum+=tmp;
            if (sum>=base) sum-=base;
        }else{
            int tmp=(base-a[i]%base)%base;
            tmp=(LL)tmp*(base-n%base)%base;
            tmp=(LL)tmp*powmod(n,N-2,base)%base;
            sum-=tmp;
            if (sum<0) sum+=base;
        }
    }
    
    ans=(LL)ans*sum%base;
    
    cout << ans << endl;
        
    return 0;
}