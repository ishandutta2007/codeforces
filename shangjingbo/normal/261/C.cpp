#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
using namespace std;

#define PB push_back
#define MP make_pair

#define FOR(it,a) for (__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

inline int sign(double x)
{
    if (x<-eps) return -1;
    return x>eps;
}

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double x,double y):x(x),y(y){}
    inline double norm(){return sqrt(x*x+y*y);}
    inline void rotate(double ang)
    {
        double co=cos(ang),si=sin(ang);
        double tx=x,ty=y;
        x=tx*co-ty*si;
        y=tx*si+ty*co;
    }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){return Tpoint(a.x+b.x,a.y+b.y);}
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){return Tpoint(a.x-b.x,a.y-b.y);}
inline Tpoint operator *(const Tpoint &a,const double &b){return Tpoint(a.x*b,a.y*b);}
inline Tpoint operator /(const Tpoint &a,const double &b){return Tpoint(a.x/b,a.y/b);}
inline double det(const Tpoint &a,const Tpoint &b){return a.x*b.y-a.y*b.x;}
inline double dot(const Tpoint &a,const Tpoint &b){return a.x*b.x+a.y*b.y;}
//================================

LL ans=0,C[50][50];
int a[100],len;

inline void dfs(int step,int need)
{
    if (need<0) return;
    if (step<0){
        ans+=need==0;
        return;
    }
    if (a[step]==1){
        ans+=C[step][need];
    }
    dfs(step-1,need-(a[step]==1));
}

int main()
{
    /*int m=30;
    int a[m+2][m+2];
    memset(a,0,sizeof(a));
    a[1][m+1]=1;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=m+1;++j){
            if (j>1) a[i+1][j-1]^=a[i][j];
            if (j<=m) a[i+1][j+1]^=a[i][j];
        }
    }
    for (int i=1;i<=m+1;++i){
        int s=0;
        for (int j=1;j<=m+1;++j){
            s+=a[i][j];
        }
        if (s!=1<<__builtin_popcount())
        printf("%d,",s);
    }*/
    for (int i=0;i<50;++i){
        C[i][0]=1;
        for (int j=1;j<=i;++j){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
    
    LL n,t;
    cin >> n >> t;
    int cnt=0;
    while (t%2==0){
        ++cnt;
        t/=2;
    }
    if (t>1){
        puts("0");
        return 0;
    }
    len=0;
    ++n;
    while (n>0){
        a[len++]=n%2;
        n/=2;
    }
    ans=0;
    dfs(len-1,cnt+1);
    if (cnt==0){
        --ans;
    }
    cout << ans << endl;
    
    return 0;
}