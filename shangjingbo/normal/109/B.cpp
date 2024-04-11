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

int q[10000];

inline double P(int l,int r,int ll,int rr)
{
    int a=max(l,ll),b=min(r,rr);
    int len=max(b-a+1,0);
    return (double)len/(r-l+1);
}

int main()
{
    int head=0,tail=0;
    q[tail++]=0;
    for (;head<tail;++head){
        int u=q[head];
        if (10LL*u+4<=1000000000) q[tail++]=10*u+4;
        if (10LL*u+7<=1000000000) q[tail++]=10*u+7;
    }
    sort(q,q+tail);
    q[tail]=1000000001;
        
    int pl,pr,vl,vr,k;
    scanf("%d%d%d%d%d",&pl,&pr,&vl,&vr,&k);
    double ans=0;
    for (int i=1;i+k<=tail;++i){
        int j=i+k;
        int leftL=q[i-1]+1,leftR=q[i];
        int rightL=q[j-1],rightR=q[j]-1;
        ans+=P(pl,pr,leftL,leftR)*P(vl,vr,rightL,rightR);
        ans+=P(vl,vr,leftL,leftR)*P(pl,pr,rightL,rightR);
        if (k==1){
            ans-=P(vl,vr,q[i],q[i])*P(pl,pr,q[i],q[i]);
        }
    }
    printf("%.10f\n",ans);
    
    return 0;
}