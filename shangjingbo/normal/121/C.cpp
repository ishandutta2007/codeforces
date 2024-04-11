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

set<long long> a;
int n,k;

int main()
{
    scanf("%d%d",&n,&k);
    long long s=1;
    int N=-1;
    for (int i=1;i<=n;++i){
        s=s*i;
        if (s>=k){
            N=i;
            break;
        }
    }
    if (s<k){
        puts("-1");
        return 0;
    }
    
    int notMove=n-N;
    int ans=0;
    for (int l=1;l<=10;++l)
        for (int i=0;i<1<<l;++i){
            long long x=0;
            for (int j=0;j<l;++j)
            if ((i>>j) &1)
                x=x*10+7;
            else x=x*10+4;
            if (x<=notMove) ++ans;
            a.insert(x);
        }
    
    bool vis[N];
    memset(vis,false,sizeof(vis));
    int st=n-N+1;
    for (int i=0;i<N;++i){
        long long frac=1;
        for (int j=1;j<=N-i-1;++j) frac*=j;
        for (int j=0;j<N;++j)
        if (!vis[j]){
            if (frac>=k){
                if (a.count(st+i) && a.count(st+j)) ++ans;
                vis[j]=true;
                break;
            }else k-=frac;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}