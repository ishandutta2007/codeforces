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

int n,m;
char s[100][100];
int mem[2][45][45][45][45];

inline int calc(int ls,int rs,int lm,int rm,int odd)
{
    if (ls>rs || lm>rm) return 0;
    int &res=mem[odd][ls+1][rs+1][lm+21][rm+21];
    if (res!=-1) return res;
    vector<int> a;
    res=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<m && i+j<=rs;++j){
            if (((i+j)&1)==odd){
                if (i+j>=ls && i+j<=rs && i-j>=lm && i-j<=rm){
                    if (s[i][j]=='R'){
                        a.push_back( calc( ls,rs,lm,i-j-1,odd )^calc(ls,rs,i-j+1,rm,odd) );
                    }else if (s[i][j]=='L'){
                        a.push_back( calc( i+j+1,rs,lm,rm,odd )^calc(ls,i+j-1,lm,rm,odd) );
                    }else if (s[i][j]=='X'){
                        a.push_back( calc(i+j+1,rs,lm,i-j-1,odd)^calc(i+j+1,rs,i-j+1,rm,odd)
                                    ^calc(ls,i+j-1,lm,i-j-1,odd)^calc(ls,i+j-1,i-j+1,rm,odd) );
                    }
                }
            }
        }
    }
    sort(a.begin(),a.end());
    a.erase( unique(a.begin(),a.end()) , a.end() );
    while (res<a.size() && a[res]==res) ++res;
    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i){
        scanf("%s",s[i]);
    }
    memset(mem,-1,sizeof(mem));
    int s=calc(0,(n-1)+(m-1),0-(m-1),(n-1)-0,0)^calc(0,(n-1)+(m-1),0-(m-1),(n-1)-0,1);
    if (s==0) puts("LOSE");
    else puts("WIN");
    
    //printf("%lf\n",(double)clock()/CLOCKS_PER_SEC);
    
    return 0;
}