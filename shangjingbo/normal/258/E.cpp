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

struct node
{
    int cnt,cover;
}tree[maxn*4];
VI interval[maxn],adj[maxn];
int n,m,l[maxn],r[maxn],len,ans[maxn];

inline void dfs(int u,int fa)
{
    l[u]=++len;
    for (int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if (v==fa){
            continue;
        }
        dfs(v,u);
    }
    r[u]=len;
}

inline void insert(int num,int l,int r,int ll,int rr,int sign)
{
    if (ll>r || rr<l) return;
    if (ll<=l && r<=rr){
        tree[num].cover+=sign;
        if (tree[num].cover>0) tree[num].cnt=r-l+1;
        else{
            if (l==r) tree[num].cnt=0;
            else tree[num].cnt=tree[num*2].cnt+tree[num*2+1].cnt;
        }
        return;
    }
    int mid=(l+r)/2;
    insert(num*2,l,mid,ll,rr,sign);
    insert(num*2+1,mid+1,r,ll,rr,sign);
    if (tree[num].cover>0){
        tree[num].cnt=r-l+1;
    }else{
        tree[num].cnt=tree[num*2].cnt+tree[num*2+1].cnt;
    }
}

inline void solve(int u,int fa)
{
    for (int i=0;i<interval[u].size();++i){
        int v=interval[u][i];
        insert(1,1,len,l[v],r[v],1);
    }
    ans[u]=tree[1].cnt;
    for (int i=0;i<adj[u].size();++i){
        int v=adj[u][i];
        if (v==fa){
            continue;
        }
        solve(v,u);
    }
    for (int i=0;i<interval[u].size();++i){
        int v=interval[u][i];
        insert(1,1,len,l[v],r[v],-1);
    }
}

bool occur[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        adj[a].PB(b);
        adj[b].PB(a);
    }
    len=0;
    dfs(1,-1);
    
    for (int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        interval[a].PB(b);
        interval[a].PB(a);
        interval[b].PB(a);
        interval[b].PB(b);
    }
    memset(tree,0,sizeof(tree));
    solve(1,-1);
    
    for (int i=1;i<=n;++i){
        printf("%d ",max(ans[i]-1,0));
    }
    
    return 0;
}