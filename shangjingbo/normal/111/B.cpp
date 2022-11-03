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

int f[100000+10],pr[100000],len;
int a[1000],cnt[1000],ans;
int x[100005],y[100005];
int last[100005];
int total=0;

inline void dfs(int step,int mul,int l,int r)
{
    if (step==-1){
        bool ok=(last[mul]<l);
        if (ok) ++ans;
        last[mul]=r+1;
        return;
    }
    for (int i=0;i<=cnt[step];++i){
        dfs(step-1,mul,l,r);
        if (i<cnt[step]) mul=mul*a[step];
    }
}

int main()
{
    memset(f,-1,sizeof(f));len=0;
    for (int i=2;i<=100000;++i)if (f[i]==-1){
        f[i]=len;
        for (LL j=(LL)i*i;j<=100000;j+=i){
            if (f[j]==-1) f[j]=len;
        }
        pr[len++]=i;
    }
    
    int n;
    scanf("%d",&n);
    memset(last,-1,sizeof(last));
    for (int i=0;i<n;++i){
        scanf("%d%d",&x[i],&y[i]);
        int N=0,xx=x[i];
        while (xx>1){
            int bak=f[xx];
            a[N]=pr[bak];
            cnt[N]=0;
            while (xx>1 && f[xx]==bak){
                xx/=pr[bak];
                ++cnt[N];
            }
            ++N;
        }
        ans=0;
        dfs(N-1,1,i-y[i],i-1);
        printf("%d\n",ans);
    }
    
    /*printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
    printf("%d\n",total);*/
    
    return 0;
}