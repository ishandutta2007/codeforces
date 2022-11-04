#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
using namespace std;

#define MP make_pair
#define PB push_back

#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<string> VS;

const double pi =   acos(-1.0);
const double eps    =   1e-8;

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

const int maxn  =   100005;

VI ans;
pair<PII,int> a[maxn];
int n,m,next[maxn];

inline int Find(int x)
{
    if (x==next[x]) return x;
    return next[x]=Find(next[x]);
}

inline bool cmp(const pair<PII,int> &a,const pair<PII,int> &b)
{
    return a.first.first+a.first.second<b.first.first+b.first.second
        || a.first.first+a.first.second==b.first.first+b.first.second && a.first.first<b.first.first;
}

inline bool comp(const pair<PII,int> &a,const pair<PII,int> &b)
{
    return a.first.second<b.first.second;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;++i){
        int r,c;
        scanf("%d%d",&r,&c);
        int left=n+1-c,right=r;
        a[i]=MP(MP(left,right),i+1);
    }
    
    sort(a,a+m,comp);
    
    for (int i=1;i<=n+1;++i)
        next[i]=i;
    
    for (int i=0;i<m;++i){
        int pos=Find(a[i].first.first);
        if (pos<=a[i].first.second){
            ans.push_back(a[i].second);
            next[pos]=pos+1;
        }
    }
    
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();++i)
        printf("%d ",ans[i]);
    puts("");
    
    return 0;
}