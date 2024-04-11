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

set<string> hash;

int per[3][4]=
{
    {0,1,2,3},
    {0,4,2,5},
    {1,4,3,5}
};

inline void rotate(string &s,int p[])
{
    string t=s;
    for (int i=0;i<4;++i)
        s[p[i]]=t[p[(i+1)%4]];
}

int main()
{
    char s[100];
    scanf("%s",s);
    sort(s,s+6);
    do
    {
        string t=s;
        string best=t;
        for (int i=0;i<4;++i)
        {
            for (int j=0;j<4;++j)
            {
                for (int k=0;k<4;++k)
                {
                    if (t<best) best=t;
                    rotate(t,per[2]);
                }
                rotate(t,per[1]);
            }
            rotate(t,per[0]);
        }
        hash.insert(best);
    }while (next_permutation(s,s+6));
    
    printf("%d\n",(int)hash.size());
    
    return 0;
}