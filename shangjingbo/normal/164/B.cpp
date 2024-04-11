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

const int maxn  =   2000005;

deque<long long> q;
int la,lb,a[maxn],b[maxn],pos[maxn];

int main()
{
    scanf("%d%d",&la,&lb);
    for (int i=0;i<la;++i){
        scanf("%d",&a[i]);
        a[i+la]=a[i];
    }
    
    memset(pos,-1,sizeof(pos));
    for (int i=0;i<lb;++i){
        scanf("%d",&b[i]);
        pos[b[i]]=i;
    }
    
    q.clear();
    int ans=0;
    for (int i=0,j=0;i<la;++i){
        if (j<i){
            j=i;
            q.clear();
        }
        while (j<i+la){
            if (pos[a[j]]==-1) break;
            
            long long p=pos[a[j]];
            if (q.size()){
                p+=lb*(q.front()/lb);
                if (p<q.front()) p+=lb;
            }
            if (q.empty() || q.back()<p){
                q.push_back(p);
            }else break;
            ++j;
        }
        
        //printf("%d %d\n",i,j);
        
        ans=max(ans,(int)q.size());
        
        if (q.size()){
            q.pop_front();
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}