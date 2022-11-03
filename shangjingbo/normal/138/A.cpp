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

bool vis[1000];
int n,k;
char s[1000000];
string key[1000];

int main()
{
    vis['a']=true;
    vis['e']=true;
    vis['i']=true;
    vis['o']=true;
    vis['u']=true;
    
    scanf("%d%d",&n,&k);
    bool aaaa=true,aabb=true,abab=true,abba=true;
    for (int i=0;i<n;++i){
        for (int j=0;j<4;++j){
            scanf("%s",s);
            int n=strlen(s);
            int bak=n,cnt=k;
            while (n && cnt){
                if (vis[s[n-1]]) --cnt;
                --n;
            }
            key[j]="";
            if (cnt==0){
                while (n<bak){
                    key[j]+=s[n];
                    ++n;
                }
            }else{
                aaaa=aabb=abab=abba=false;
            }
        }

        aaaa=aaaa && key[0]==key[1] && key[0]==key[2] && key[0]==key[3];
        aabb=aabb && key[0]==key[1] && key[3]==key[2];
        abab=abab && key[0]==key[2] && key[3]==key[1];
        abba=abba && key[0]==key[3] && key[1]==key[2];
    }
    
    if (aaaa) puts("aaaa");
    else if (abab) puts("abab");
    else if (abba) puts("abba");
    else if (aabb) puts("aabb");
    else puts("NO");
    
    return 0;
}