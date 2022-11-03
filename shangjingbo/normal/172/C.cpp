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

const int maxn  =   1000005;

struct node
{
    int x,t,id;
};

inline bool cmpx(const node &a,const node &b)
{
    return a.x<b.x;
}

int n,m,ans[maxn];
vector<node> a;

int main()
{
    scanf("%d%d",&n,&m);
    int start=0;
    for (int i=0;i<n;++i){
        node cur;
        scanf("%d%d",&cur.t,&cur.x);
        cur.id=i;
        a.PB(cur);
        if (a.size()==m || i+1==n){
            int s=max(start,a.back().t),x=0;
            sort(a.begin(),a.end(),cmpx);
            for (int j=0;j<a.size();){
                int k=j+1;
                while (k<a.size() && a[k].x==a[j].x) ++k;
                int cnt=k-j;
                s+=a[j].x-x;
                x=a[j].x;
                while (j<k){
                    ans[a[j].id]=s;
                    ++j;
                }
                s+=1+cnt/2;
            }
            start=s+x;
            a.clear();
//printf("%d\n",start);
        }
    }
    
    for (int i=0;i<n;++i) printf("%d ",ans[i]);
    
    return 0;
}