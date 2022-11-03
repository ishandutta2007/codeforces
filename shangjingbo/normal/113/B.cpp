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

const ULL magic =   37;
const LL magic2 =   97;
const LL base   =   1000000007;

#define maxn 2005

ULL pw[maxn],h[maxn];
LL pw2[maxn],hh[maxn];
char s[maxn],l[maxn],r[maxn];
vector< pair<ULL,LL> > ans;

inline pair<ULL,LL> getValue(int l,int r)
{
    return MP( h[r+1]-h[l]*pw[r-l+1], (hh[r+1]-(hh[l]*pw2[r-l+1])%base+base)%base );
}

inline bool equal(int l,int r,ULL h1,LL h2)
{
    return getValue(l,r)==MP(h1,h2);
}

int main()
{
    scanf("%s%s%s",s,l,r);
    int l1=strlen(l),l2=strlen(r),n=strlen(s);
    pw[0]=pw2[0]=1;
    for (int i=1;i<=n;++i){
        pw[i]=pw[i-1]*magic;
        pw2[i]=pw2[i-1]*magic2%base;
    }
    ULL h1=0,h2=0;
    LL hh1=0,hh2=0;
    for (int i=0;l[i];++i){
        h1=h1*magic+l[i]-'a'+1;
        hh1=(hh1*magic2+l[i]-'a'+1)%base;
    }
    for (int i=0;r[i];++i){
        h2=h2*magic+r[i]-'a'+1;
        hh2=(hh2*magic2+r[i]-'a'+1)%base;
    }
    
    for (int i=0;i<n;++i){
        h[i+1]=h[i]*magic+s[i]-'a'+1;
        hh[i+1]=(hh[i]*magic2+s[i]-'a'+1)%base;
    }
    
    int len=max(l1,l2);
    ans.clear();
    for (int st=0;st<n;++st){
        for (int ed=st+len-1;ed<n;++ed){
            int l=st,r=l+l1-1;
            if (equal(l,r,h1,hh1)){
                r=ed,l=ed-l2+1;
                if (equal(l,r,h2,hh2)){
                    ans.PB(getValue(st,ed));
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    printf("%d\n",(int)ans.size());
    
    return 0;
}