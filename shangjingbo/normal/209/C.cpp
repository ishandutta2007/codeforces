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

const int maxn  =   1000005;

int d[maxn],father[maxn];
bool hasOdd[maxn];

inline int Find(int x)
{
    if (x==father[x]) return x;
    return father[x]=Find(father[x]);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i){
        father[i]=i;
        d[i]=0;
    }
    for (int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        ++d[a];
        ++d[b];
        father[Find(a)]=Find(b);
    }
    memset(hasOdd,false,sizeof(hasOdd));
    int cnt=0;
    for (int i=0;i<n;++i){
        if (d[i]&1){
            hasOdd[Find(i)]=true;
            ++cnt;
        }
    }
    
    int c1=0,c2=0;
    for (int i=0;i<n;++i)
    if (Find(i)==i && (d[i]>0 || Find(0)==i)){
        if (!hasOdd[i]) ++c1;
        else c2=1;
    }
    
    int ans=cnt/2;
    
    if (c1+c2>=2){
        ans+=c1;
    }
    
    printf("%d\n",ans);
    
    return 0;
}