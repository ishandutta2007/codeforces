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
    int x,y;
    Tpoint(){}
    Tpoint(int _x,int _y){x=_x;y=_y;}
    inline void read(){scanf("%d%d",&x,&y);}
    inline void show(){printf("%d %d\n",x,y);}
    inline int norm(){ return sqr(x)+sqr(y); }
};

inline Tpoint operator +(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x+b.x,a.y+b.y); }
inline Tpoint operator -(const Tpoint &a,const Tpoint &b){ return Tpoint(a.x-b.x,a.y-b.y); }
inline int det(const Tpoint &a,const Tpoint &b){ return a.x*b.y-a.y*b.x; }
inline int dot(const Tpoint &a,const Tpoint &b){ return a.x*b.x+a.y*b.y; }
//=============================================================================================

Tpoint a[100];
int id[100];

inline bool checkRec(int l,int r)
{
    Tpoint s[10];
    for (int i=l;i<=r;++i) s[i-l]=a[id[i]];
    for (int i=4;i<8;++i) s[i]=s[i-4];
    
    for (int i=0;i<4;++i)
    if (dot(s[i]-s[i+1],s[i+2]-s[i+1])) return false;
    
    int sum=0;
    for (int i=0;i<4;++i) sum+=det(s[i+1],s[i]);
    
    if (sum==0) return false;
    
    return true;
}

inline bool checkSquare(int l,int r)
{
    if (!checkRec(l,r)) return false;
    Tpoint s[5];
    for (int i=l;i<=r;++i) s[i-l]=a[id[i]];
    s[4]=s[0];
    
    for (int i=0;i<4;++i){
        Tpoint d=s[i+1]-s[i];
        if (d.norm()!=(s[1]-s[0]).norm()) return false;
    }
    
    return true;
}

int main()
{
    for (int i=0;i<8;++i){
        a[i].read();
        id[i]=i;
    }
    
    do{
        if (checkSquare(0,3) && checkRec(4,7)){
            puts("YES");
            for (int i=0;i<4;++i) printf("%d ",id[i]+1);
            puts("");
            for (int i=4;i<8;++i) printf("%d ",id[i]+1);
            puts("");
            return 0;
        }
    }while (next_permutation(id,id+8));
    
    puts("NO");
    
    return 0;
}