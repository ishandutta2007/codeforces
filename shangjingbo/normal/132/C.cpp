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

const int d[2]  =   {1,-1};

const int zero  =   101;

bool f[105][55][205][2];
char s[1000];

int main()
{
    scanf("%s",s);
    int n=strlen(s),m;
    scanf("%d",&m);
    memset(f,false,sizeof(f));
    f[0][0][0+zero][0]=true;
    for (int i=0;i<n;++i){
        for (int j=0;j<=m;++j){
            for (int k=-100;k<=100;++k)
                for (int face=0;face<2;++face)
                if (f[i][j][k+zero][face]){
                    if (s[i]=='T'){
                        f[i+1][j][k+zero][face^1]=true;
                        f[i+1][j+1][k+d[face]+zero][face]=true;
                    }else if (s[i]=='F'){
                        f[i+1][j+1][k+zero][face^1]=true;
                        f[i+1][j][k+d[face]+zero][face]=true;
                    }
                }
        }
    }
    
    int ans=0;
    for (int j=0;j<=m;++j){
        if ((m-j)&1) continue;
        for (int k=-100;k<=100;++k)
            for (int face=0;face<2;++face)
            if (f[n][j][k+zero][face]){
                ans=max(ans,abs(k));
            }
    }
    
    printf("%d\n",ans);
    
    return 0;
}