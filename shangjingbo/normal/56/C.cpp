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
#define maxn 10005

map<string,int> bak[maxn];
char s[maxn];
int N,Ans=0;

inline void Make(int num,int l,int r)
{
    int i=l;
    string now="";
    while (i<=r && s[i]>='A' && s[i]<='Z')
    {
        now+=s[i];
        ++i;
    }
    bak[num].clear();
    ++bak[num][now];
    if (s[i]=='.') return;
    
    int last,sum=0;
    for (int j=i+1;j<r;++j)
    {
        if (s[j]>='A' && s[j]<='Z' && !(s[j-1]>='A' && s[j-1]<='Z'))
        {
            if (!sum) last=j;
            ++sum;
        }else if (s[j]=='.')
        {
            --sum;
            if (sum==0)
            {
                int xx=++N;
                Make(xx,last,j);
                if (bak[xx].count(now)) Ans+=bak[xx][now];
                map<string,int>::iterator it=bak[xx].begin();
                for (;it!=bak[xx].end();++it)
                    bak[num][it->first]+=it->second;
            }
        }
    }
}

int main()
{
    scanf("%s",s);
    
    Ans=N=0;
    Make(0,0,strlen(s)-1);
    
    printf("%d\n",Ans);
    
    return 0;
}