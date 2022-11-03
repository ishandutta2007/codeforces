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

const int maxn  =   1005;
const int base  =   1000000007;

long long C[maxn][maxn],pw2[maxn];
int n,m;
bool light[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    memset(light,false,sizeof(light));
    for (int i=0;i<m;++i){
        int x;
        scanf("%d",&x);
        light[x]=true;
    }
    for (int i=0;i<=n;++i){
        C[i][0]=1;
        for (int j=1;j<=i;++j){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%base;
        }
    }
    pw2[0]=1;
    for (int i=1;i<=n;++i){
        pw2[i]=pw2[i-1]*2LL%base;
    }
    int ans=1,all=0;
    for (int i=1;i<=n;++i){
        if (!light[i]){
            int j=i;
            while (j<=n && !light[j]) ++j;
            
            int len=j-i,cnt=0;
            if (light[j]) ++cnt;
            if (light[i-1]) ++cnt;
            
            long long ways;
            if (cnt==1){
                ways=1;
            }else{
                ways=pw2[len-1];
            }
            ans=ans*ways%base*C[all+len][len]%base;
            all+=len;
            i=j-1;
        }
    }
    
    printf("%d\n",ans);
    return 0;
}