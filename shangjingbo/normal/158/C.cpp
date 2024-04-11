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
#include <sstream>
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

string s[1000000];
char op[100],tmp[1000];

int main()
{
    int T,n=0;
    s[n++]="";
    
    for (scanf("%d",&T);T--;){
        scanf("%s",op);
        if (op[0]=='p'){
            for (int i=0;i<n;++i){
                printf("%s/",s[i].c_str());
            }
            puts("");
        }else{
            scanf("%s",tmp);
            int len=strlen(tmp);
            if (tmp[0]=='/'){
                n=0;
                s[n++]="";
                for (int i=0;i<len;++i){
                    tmp[i]=tmp[i+1];
                }
                --len;
            }
            {
                for (int i=0;i<len;++i) if (tmp[i]=='/') tmp[i]=' ';
                stringstream in(tmp);
                string token;
                while (in >> token){
                    if (token=="..") n=max(1,n-1);
                    else{
                        s[n++]=token;
                    }
                }
            }
        }
    }
    
    return 0;
}