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

const LL base   =   1000000007;

inline void Plus(LL &a,LL b)
{
    a+=b;
    if (a>=base) a-=base;
}

inline LL powmod(LL x,LL t,LL base)
{
    if (t==0) return 1%base;
    LL y=powmod(x,t/2,base);
    y=y*y%base;
    if (t&1LL==1){
        y=y*x%base;
    }
    return y;
}

const int maxn  =   100005;

vector<int> divs[maxn];
int n,a[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int maxi=a[n-1];
    for (int i=1;i<=maxi;++i){
        for (int j=i;j<=maxi;j+=i){
            divs[j].push_back(i);
        }
    }
    LL ans=0;
    for (int lcm=1;lcm<=maxi;++lcm){
        LL mul=1;
        divs[lcm].push_back(maxi+1);
        for (int i=1;i<divs[lcm].size();++i){
            int cnt=lower_bound(a,a+n,divs[lcm][i])-lower_bound(a,a+n,divs[lcm][i-1]);
            mul=mul*powmod(i,cnt,base)%base;
        }
        Plus(ans,mul);
//printf("+ %I64d\n",mul);      
        divs[lcm].pop_back();
        divs[lcm].back()=maxi+1;
        mul=base-1;
        int all=n;
        for (int i=1;i<divs[lcm].size();++i){
            int cnt=lower_bound(a,a+n,divs[lcm][i])-lower_bound(a,a+n,divs[lcm][i-1]);
//printf("%d %d %d\n",i,cnt,divs[lcm][i]);
            all-=cnt;
            mul=mul*powmod(i,cnt,base)%base;
        }
        if (all==0){
            Plus(ans,mul);
//printf("- %I64d\n",mul);
        }else{
            //printf("all = %d\n",all);
        }
//printf("%d %I64d\n",lcm,ans);
    }
    cout << ans << endl;
    return 0;
}