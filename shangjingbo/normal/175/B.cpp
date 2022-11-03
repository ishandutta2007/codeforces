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

const double eps    =   1e-8;

int main()
{
    int n;
    map<string,int> f;
    cin >> n;
    for (int i=0;i<n;++i){
        string name;
        int s;
        cin >> name >> s;
        if (f.count(name)) f[name]=max(f[name],s);
        else f[name]=s;
    }
    cout << f.size() << endl;
    for (map<string,int>::iterator it=f.begin();it!=f.end();++it){
        int st=it->second;
        int worseThan=0,notWorseThan=0;
        for (map<string,int>::iterator it2=f.begin();it2!=f.end();++it2){
            if (st<it2->second) ++worseThan;
            if (st>=it2->second) ++notWorseThan;
        }
        cout << it->first << " ";
        string res="";
        if (notWorseThan>=f.size()*0.99-eps){
            res="pro";
        }else if (notWorseThan>=f.size()*0.9-eps){
            res="hardcore";
        }else if (notWorseThan>=f.size()*0.8-eps){
            res="average";
        }else if (notWorseThan>=f.size()*0.5-eps){
            res="random";
        }else res="noob";
        
        cout << res << endl;
    }
    
    return 0;
}