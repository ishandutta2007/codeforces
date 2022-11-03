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

int frac[1000005],f[1005];

inline int calc(int x,int t)
{
    if (!t) return 1;
    int y=calc(x,t>>1);
    y=(LL)y*y%base;
    if (t&1) y=(LL)y*x%base;
    return y;
}

inline void Plus(int &a,int b)
{
    a+=b;
    if (a>=base) a-=base;
}

inline int C(int a,int b)
{
    if (b<0 || b>a) return 0;
    int res=frac[a];
    int div1=calc(frac[b],base-2);
    int div2=calc(frac[a-b],base-2);
    res=(LL)res*div1%base;
    res=(LL)res*div2%base;
    return res;
}

int main()
{
    frac[0]=1;
    for (int i=1;i<=1000000;++i) frac[i]=(LL)frac[i-1]*i%base;
    int n,m,color;
    scanf("%d%d%d",&n,&m,&color);
    if (m==1){
        printf("%d\n",calc(color,n));
    }else{
        for (int i=1;i<=n;++i){
            f[i]=0;
            for (int j=0;j<i;++j){
                int mul1=C(i,j);
                int mul2=calc(i-j,n);
                mul1=(LL)mul1*mul2%base;
                if (j&1) mul1=(base-mul1)%base;
                Plus(f[i],mul1);
            }
        }
        
        int ans=0;
        for (int k=(m==2)?0:1;k<=color && k<=n;++k){
            int mul=C(color,k);
            mul=(LL)mul*calc(k,n*(m-2))%base;
            int sum=0;
            for (int del=(k==0)?1:0;k+2*del<=color && k+del<=n;++del){
                int c1=C(color-k,del);
                int c2=C(color-k-del,del);
                int i=k+del;
                c1=(LL)c1*c2%base;
                c1=(LL)c1*f[i]%base;
                c1=(LL)c1*f[i]%base;
                Plus(sum,c1);
            }
            mul=(LL)mul*sum%base;
            Plus(ans,mul);
        }
        printf("%d\n",ans);
    }
    
    return 0;
}