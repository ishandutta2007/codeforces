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

const long long limit   =   1000000000000000000LL;
LL mem[(1<<16)+5],y;
int mark[(1<<16)+5],stamp;
int n,m,d[20][20];
bool vis[100];
int id[100],must[100],big[100],small[100],ans[100];

inline LL dfs(int step,int mask)
{
    if (step<0) return 1LL;
    LL &res=mem[mask];
    if (mark[mask]==stamp) return res;
    mark[mask]=stamp;
    res=0;
    
    int cur=id[step];
    for (int i=0;i<n;++i) if (!((1<<i)&mask) && (mask&must[i])==must[i] && cur>big[i] && cur<small[i]){
        res+=dfs(step-1,mask^(1<<i));
        if (res>limit) res=limit+1;
    }
    
    return res;
}

inline LL solve()
{
    for (int i=0;i<n;++i){
        must[i]=0;
        small[i]=100;
        big[i]=-1;
        for (int j=0;j<n;++j)if (i!=j){
            if (ans[j]!=-1){
                if (d[j][i]) small[i]=min(small[i],ans[j]);
                else if (d[i][j]) big[i]=max(big[i],ans[j]);
            }else if (d[j][i]) must[i]|=1<<j;
        }
    }
    
    int st=0,cnt=0;
    for (int i=0;i<n;++i) if (ans[i]!=-1) st|=1<<i;
    
    for (int i=0;i<n;++i)
    if (!vis[i]) id[cnt++]=i;
    
    ++stamp;
    return dfs(cnt-1,st);
}

int main()
{
    scanf("%d%I64d%d",&n,&y,&m);
    memset(d,0,sizeof(d));
    for (int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        d[a][b]=1;
    }
    for (int i=0;i<n;++i) d[i][i]=1;
    for (int k=0;k<n;++k)
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
            if (d[i][k] && d[k][j]) d[i][j]=1;
    
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
        if (d[i][j] && d[j][i]){
            puts("The times have changed");
            return 0;
        }
    memset(ans,-1,sizeof(ans));
    y-=2000;
    memset(mark,-1,sizeof(mark));
    memset(vis,false,sizeof(vis));
    stamp=0;
    if (solve()<y){
        puts("The times have changed");
        return 0;
    }   
    for (int i=0;i<n;++i){
        for (int j=n-1;j>=0;--j)if (!vis[j]){
            ans[i]=j;
            vis[j]=true;
            LL t=solve();
            if (t>=y) break;
            y-=t;
            vis[j]=false;
        }
    }
    for (int i=0;i<n;++i)
    {
        if (i) printf(" ");
        printf("%d",n-ans[i]);
    }
    puts("");
    
    return 0;
}