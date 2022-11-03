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

char s[1000005];
int ans[1000005];

int main()
{
    scanf("%s",s+1);
    s[0]='0';
    int n=strlen(s+1);
    memset(ans,0,sizeof(ans));
    for (int i=n;i>=1;--i){
        int j=i;
        while (s[j]=='1') --j;
        if (i-j>1){
            ans[i]=-1;
            for (int k=j+1;k<=i;++k) s[k]='0';
            s[j]='1';
        }
    }
    for (int i=0;i<=n;++i)
    if (ans[i]!=-1 && s[i]=='1') ans[i]=1;
    
    int m=0;
    for (int i=0;i<=n;++i) m+=abs(ans[i]);
    printf("%d\n",m);
    for (int i=0;i<=n;++i)if (ans[i]){
        if (ans[i]>0) printf("+");
        else printf("-");
        printf("2^%d\n",n-i);
    }
    return 0;
}