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

int s[1006],n,m,h;
int f[100006],cnt[100006],len,pr[100006];

inline void add(int x,int d)
{
    while (x>1){
        int y=f[x];
        cnt[y]+=d;
        x/=pr[y];
    }
}

int main()
{
    memset(f,-1,sizeof(f));
    for (int i=2;i<=100000;++i) if (f[i]==-1){
        f[i]=len;
        for (long long j=(long long)i*i;j<=100000;j+=i)
        if (f[j]==-1) f[j]=len;
        
        pr[len++]=i;
    }
    scanf("%d%d%d",&n,&m,&h);
    for (int i=1;i<=m;++i) scanf("%d",&s[i]);
    swap(s[h],s[m]);
    
    int s1=0,s2=0;
    for (int i=1;i<m;++i) s1+=s[i];
    s2=s1+s[m]-1;
    
    if (s2<n-1){
        puts("-1.0");
        return 0;
    }
    if (s[m]==1){
        puts("0.0");
        return 0;
    }
    if (s1<n-1){
        puts("1.0");
        return 0;
    }
    
    for (int i=0;i<n-1;++i){
        add(s1-i,1);
        add(s2-i,-1);
    }
    
    double ans=1;
    for (int i=0;i<len;++i)
    if (cnt[i]>0){
        for (int j=0;j<cnt[i];++j) ans*=pr[i];
    }else for (int j=cnt[i];j<0;++j) ans/=pr[i];
    
    ans=1-ans;
    printf("%.10f\n",ans);
    
    return 0;
}