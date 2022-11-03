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

inline LL C(LL n,LL m)
{
    if (m<0 || m>n) return 0;
    LL res=1;
    for (int i=0;i<m;++i){
        res=res*(n-i)%base;
        res=res*powmod(i+1,base-2,base)%base;
    }
    return res;
}

int a[100];
LL ans[100];

inline void dfs(int step,int cnt)
{
    if (step<0){
        Plus(ans[cnt],1);
        return;
    }
    for (int dig=0;dig<a[step];++dig){
        int cur=cnt;
        if (dig==4 || dig==7){
            ++cur;
        }
        for (int remain=0;remain<=step;++remain){
            LL coef=C(step,remain)*powmod(2,remain,base)%base*powmod(8,step-remain,base)%base;
            Plus(ans[cur+remain],coef);
        }
//printf("%d %d %I64d\n",step,dig,ans[1]);
    }
    dfs(step-1,cnt+(a[step]==4 || a[step]==7));
}

LL sum;

inline void test(int step,int s,LL mul)
{
    if (s>=10) return;
    if (step==6){
        for (int x=s+1;x<=10;++x){
            Plus(sum,mul*ans[x]%base);
        }
        return;
    }
    for (int i=0;i<=10;++i){
        LL t=mul*ans[i]%base;
        --ans[i];
        test(step+1,s+i,t);
        ++ans[i];
    }
}

int main()
{
    int m=44,len=0;
    scanf("%d",&m);
    
    while (m>0){
        a[len++]=m%10;
        m/=10;
    }
    dfs(len-1,0);
    ans[0]--;
    
    sum=0;
    test(0,0,1);
    
    cout << sum << endl;
    
    return 0;
}