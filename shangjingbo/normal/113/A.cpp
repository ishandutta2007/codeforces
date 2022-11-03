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

#define maxlen 100005
#define maxn 50005

char s[maxlen];
string word[maxn];

inline bool check(string s,string t)
{
    if (s.size()<t.size()) return false;
    for (int i=1;i<=t.size();++i)
    if (s[s.size()-i]!=t[t.size()-i]) return false;
    return true;
}

inline int gender(string word)
{
    if (check(word,"lios")) return 0;
    if (check(word,"liala")) return 1;
    
    if (check(word,"etr")) return 0;
    if (check(word,"etra")) return 1;
    
    if (check(word,"initis")) return 0;
    if (check(word,"inites")) return 1;
    
    return -1;
}

inline int type(string word)
{
    if (check(word,"lios")) return 0;
    if (check(word,"liala")) return 0;
    
    if (check(word,"etr")) return 1;
    if (check(word,"etra")) return 1;
    
    if (check(word,"initis")) return 2;
    if (check(word,"inites")) return 2;
    
    return -1;
}

inline bool check(int n)
{
    for (int i=0;i<n;++i) if (gender(word[i])!=gender(word[0]) || gender(word[i])==-1) return false;
    
    if (n==1) return true;
    int i=0;
    while (i<n && type(word[i])==0) ++i;
    
    if (i==n) return false;

    if (type(word[i])==1) ++i;
    else return false;
    
    while (i<n && type(word[i])==2) ++i;
    return i==n;
}

int main()
{
    gets(s);
    stringstream in(s);
    int n=0;
    while (in >> word[n]) ++n;
    
    if (check(n)) puts("YES");
    else puts("NO");
    
    return 0;
}