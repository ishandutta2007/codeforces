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
#define maxn 100005

int n,a[maxn],b[maxn];
map<int,set<int> > Pos;
vector< pair<int,int> > ans;

inline bool isLucky(int x)
{
    while (x>0){
        int t=x%10;
        if (t!=4 && t!=7) return false;
        x/=10;
    }
    return true;
}

inline void swap(int sp,int i)
{
    if (sp==i) return;
    ans.PB(MP(sp,i));
    int x;
    if (a[sp]!=b[sp]){
        Pos[a[sp]].erase(sp);
        x=Pos[a[sp]].size();
        x=*Pos[a[sp]].begin();
    }
    if (a[i]!=b[i])
        Pos[a[i]].erase(i);
    int t=a[sp];
    a[sp]=a[i];
    a[i]=t;
    if (a[sp]!=b[sp]) Pos[a[sp]].insert(sp);
    if (a[i]!=b[i]) Pos[a[i]].insert(i);
    x=Pos[a[i]].size();
    x=*Pos[a[i]].begin();
}

int main()
{
    scanf("%d",&n);
    //n=100000;
    int sp=-1;
    for (int i=0;i<n;++i){
        scanf("%d",&a[i]);
//      a[i]=rand()%10000+1;
        if (isLucky(a[i])) sp=i;
        b[i]=a[i];
    }
    //a[0]=7;b[0]=7;
    sort(b,b+n);
    for (int i=0;i<n;++i) if (a[i]!=b[i]) Pos[a[i]].insert(i);
    ans.clear();
    for (int i=0;i<n;++i) if (b[i]!=a[i]){
        if (sp==-1){
            puts("-1");
            return 0;
        }
        swap(sp,i);sp=i;
        if (Pos[b[i]].size()){
            int t=*Pos[b[i]].begin();
            swap(sp,t);sp=t;
        }
    }
    
    for (int i=0;i<n;++i) if (a[i]!=b[i]){
        swap(sp,i);sp=i;
        if (Pos[b[i]].size()){
            int t=*Pos[b[i]].begin();
            swap(sp,t);sp=t;
        }
    }
    
    for (int i=0;i<n;++i)if (a[i]!=b[i]){
        printf("Error at %d: %d = %d\n",i,a[i],b[i]);
    }
    if (ans.size()>2*n){
        puts("Too many operations!");
        while (1);
    }
    
    printf("%d\n",(int)ans.size());
    for (int i=0;i<ans.size();++i) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
    
    return 0;
}