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

#define k second
#define c first

const int maxn  =   1000;

PII a[maxn];
int n,t;
long long p[maxn];

int main()
{
    cin >> n;
    for (int i=0;i<n;++i){
        int k,c;
        cin >> k >> c;
        a[i].first=c;
        a[i].second=k;
    }
    sort(a,a+n);
    
    cin >> t;
    for (int i=1;i<=t;++i)
        cin >> p[i];
    
    long long f=1;
    long long ans=0,s=0;
    for (int i=0;i<n;++i){
        while (f<=t && s+a[i].k>p[f]){
            long long cnt=p[f]-s;
            a[i].k-=cnt;
            s+=cnt;
            ans+=cnt*(a[i].c)*f;
            ++f;
        }
        long long cnt=a[i].k;
        a[i].k-=cnt;
        s+=cnt;
        ans+=cnt*(a[i].c)*f;
        if (f<=t && s==p[f]) ++f;
    }
    
    cout << ans << endl;
    
    return 0;
}