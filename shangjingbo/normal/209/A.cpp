#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define PB push_back
#define MP make_pair

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

struct Tpoint
{
    double x,y;
    Tpoint(){}
    Tpoint(double a,double b){x=a;y=b;}
    inline double norm(){return sqrt(sqr(x)+sqr(y));}
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){return Tpoint(a.x+b.x,a.y+b.y);}
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){return Tpoint(a.x-b.x,a.y-b.y);}
inline Tpoint operator *(const Tpoint &a,const double &b){return Tpoint(a.x*b,a.y*b);}
inline Tpoint operator /(const Tpoint &a,const double &b){return Tpoint(a.x/b,a.y/b);}
inline double dot(const Tpoint &a,const Tpoint &b){return a.x*b.x+a.y*b.y;}
inline double det(const Tpoint &a,const Tpoint &b){return a.x*b.y-a.y*b.x;}
//==============================================================================================

const int base  =   1000000007;

int f[1000005];

int main()
{
    int n;
    scanf("%d",&n);
    int sum[3];
    sum[0]=sum[1]=sum[2]=1;
    for (int i=0;i<n;++i){
        f[i]=sum[i%2]%base;
        //s=(s+f[i])%base;
        sum[(i+1)%2]=(sum[(i+1)%2]+f[i])%base;
    }
    int s=0;
    for (int i=0;i<n;++i)
        s=(s+f[i])%base;
    printf("%d\n",s%base);
    return 0;
    
    return 0;
}