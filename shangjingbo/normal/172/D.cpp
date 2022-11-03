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

const int maxn  =   10000005;

int f[maxn];

int main()
{
    //freopen("input.txt","r",stdin);
    
    int a,n;
    scanf("%d%d",&a,&n);
    int limit=a+n-1;
    memset(f,0,sizeof(f));
    for (int i=2;i<=limit;++i)if (!f[i]){
        f[i]=i;
        if (i<=limit/i)
        for (int j=i*i;j<=limit;j+=i){
            if (!f[j]) f[j]=i;
        }
    }
    
    long long ans=0;
    for (int i=a;i<a+n;++i){
        int x=i,cur=1;
        while (x>1){
            int bak=f[x];
            int cnt=0;
            while (f[x]==bak){
                x/=bak;
                cnt^=1;
            }
            if (cnt) cur*=bak;
        }
        ans+=cur;
    }
    
    cout << ans << endl;
    
    //printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
    
    return 0;
}