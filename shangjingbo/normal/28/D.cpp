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
//============================================================================================

const int inf   =   1000000000;
#define maxn 100005

int f[maxn],l[maxn],r[maxn],v[maxn],c[maxn],n;
bool mark[maxn];
int bak[maxn],N;
vector<PII> a[maxn];

inline int dfs(int i)
{
    if (r[i]==0) return v[i];
    int &res=f[i];
    if (mark[i]) return res;
    mark[i]=true;
    res=-inf;
    int id=lower_bound(bak,bak+N,l[i]+c[i])-bak;
    if (id==N || bak[id]!=l[i]+c[i]) return res;
    
    int st=lower_bound(a[id].begin(),a[id].end(),MP(r[i],-1))-a[id].begin();
    
    for (int j=st;j<a[id].size() && a[id][j].first==r[i];++j){
        if (a[id][j].second>i){
            //printf("transing: %d %d\n",i,a[id][j].second);
            res=max(res,dfs(a[id][j].second)+v[i]);
        }
    }
    //printf("%d %d\n",i,res);
    return res;
}

int out[maxn],len;

inline void output(int i)
{
    out[len++]=i;
    if (r[i]==0) return;
    int &res=f[i];
    int id=lower_bound(bak,bak+N,l[i]+c[i])-bak;
    int st=lower_bound(a[id].begin(),a[id].end(),MP(r[i],-1))-a[id].begin();
    for (int j=st;j<a[id].size() && a[id][j].first==r[i];++j){
        if (a[id][j].second>i){
            //printf("transing: %d %d\n",i,a[id][j].second);
            if (res==dfs(a[id][j].second)+v[i]){
                output(a[id][j].second);
                return;
            }
        }
    }
    //printf("%d %d\n",i,res);
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d%d%d%d",&v[i],&c[i],&l[i],&r[i]);
        bak[N++]=l[i];
    }
    sort(bak,bak+N);
    N=unique(bak,bak+N)-bak;
    
    for (int i=0;i<n;++i){
        a[lower_bound(bak,bak+N,l[i])-bak].PB(MP(c[i]+r[i],i));
    }
    
    for (int i=0;i<n;++i){
        sort(a[i].begin(),a[i].end());
    }
    
    int ans=0;
    memset(mark,false,sizeof(mark));
    for (int i=0;i<n;++i){
        if (l[i]==0){
            ans=max(ans,dfs(i));
        }
    }
    //printf("%d\n",ans);
    len=0;
    for (int i=0;i<n;++i){
        if (l[i]==0 && ans==dfs(i)){
            output(i);
            break;
        }
    }
    printf("%d\n",len);
    for (int i=0;i<len;++i)
        printf("%d ",out[i]+1);
    
    return 0;
}