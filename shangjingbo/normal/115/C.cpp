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

const int base  =   1000003;
#define maxn 500005

string s[maxn];
char a[maxn];
char buffer[maxn];
int f[2][2];

inline void Plus(int &a,int b)
{
    a+=b;
    if (a>=base) a-=base;
}

inline int solve(int n)
{
    int now=0,old=1;
    memset(f,0,sizeof(f));
    f[0][0]=f[0][1]=1;
    for (int i=0;i<n;++i){
        now=1-now;
        old=1-old;
        memset(f[now],0,sizeof(f[now]));
        if (a[i]!='R'){
            Plus(f[now][0],f[old][1]);
        }
        if (a[i]!='L'){
            Plus(f[now][1],f[old][0]);
        }
    }
    int res=(f[now][0]+f[now][1]);
    if (res>=base) res-=base;
    return res;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i){
        scanf("%s",buffer);
        s[i]=buffer;
    }
    
    int ans=1;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j)
        if (s[i][j]=='1' || s[i][j]=='2') a[j]='L';
        else if (s[i][j]=='3' || s[i][j]=='4') a[j]='R';
        else a[j]='.';
        ans=(LL)ans*solve(m)%base;
    }
    
    for (int j=0;j<m;++j){
        for (int i=0;i<n;++i)
        if (s[i][j]=='1' || s[i][j]=='4') a[i]='L';
        else if (s[i][j]=='3' || s[i][j]=='2') a[i]='R';
        else a[i]='.';
        ans=(LL)ans*solve(n)%base;
    }
    
    printf("%d\n",ans);
    
    return 0;
}