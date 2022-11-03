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

const int limit =   100000;

int f[limit+5],occur[limit+10];
bool mark[limit+10];
int n,m;

inline bool insert(int x)
{
    int bak=x;
    while (x>1){
        int y=f[x];
        if (occur[y]!=-1){
            printf("Conflict with %d\n",occur[y]);
            return false;
        }
        x/=y;
    }
    x=bak;
    while (x>1){
        int y=f[x];
        occur[y]=bak;
        x/=y;
    }
    mark[bak]=true;
    return true;
}

inline void remove(int x)
{
    mark[x]=false;
    while (x>1){
        int y=f[x];
        occur[y]=-1;
        x/=y;
    }
}

int main()
{
    memset(f,-1,sizeof(f));
    memset(mark,false,sizeof(mark));
    memset(occur,-1,sizeof(occur));
    for (int i=2;i<=limit;++i)if (f[i]==-1){
        f[i]=i;
        if (i<=limit/i)
        for (int j=i*i;j<=limit;j+=i)
        if (f[j]==-1) f[j]=i;
    }
    
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;++i){
        char op[5];
        int x;
        scanf("%s%d",op,&x);
        
        if (op[0]=='+'){
            if (mark[x]){
                puts("Already on");
            }else{
                if (insert(x)){
                    puts("Success");
                }
            }
        }else{
            if (!mark[x]){
                puts("Already off");
            }else{
                remove(x);
                puts("Success");
            }
        }
    }
    
    return 0;
}