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

const int base  =   1000000007;
map<int,int> Cnt;

inline bool isLucky(int x)
{
    while (x>0){
        int y=x%10;
        if (y!=4 && y!=7) return false;
        x/=10;
    }
    return true;
}

inline void Plus(int &a,int b)
{
    a+=b;
    if (a>=base) a-=base;
}

inline int calc(int x,int t,int base)
{
    if (t==0) return 1%base;
    int y=calc(x,t>>1,base);
    y=(LL)y*y%base;
    if (t&1){
        y=(LL)y*x%base;
    }
    return y;
}

int n,k,f[100005];

int main()
{
    scanf("%d%d",&n,&k);
    int un=0;
    for (int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        if (isLucky(x)){
            ++Cnt[x];
        }else ++un;
    }
    
    memset(f,0,sizeof(f));
    f[0]=1;
    int CC=0;
    for (map<int,int>::iterator it=Cnt.begin();it!=Cnt.end();++it){
        int x=it->second;
        ++CC;
        for (int i=CC;i>=1;--i)
            Plus(f[i],(LL)f[i-1]*x%base);
    }
    
    int ans=0;
    int c=1;
    for (int i=0;i<=k;++i){
        Plus(ans,(LL)f[k-i]*c%base);
        c=(LL)c*(un-i)%base;
        c=(LL)c*calc(i+1,base-2,base)%base;
    }
    
    cout << ans << endl;
    
    
    
    return 0;
}