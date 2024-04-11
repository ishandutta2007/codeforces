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

const int maxn  =   100005;

int f[maxn],k,n,next[maxn][30];
char s[maxn];
bool forbid[30][30];

inline void Update(int &x,int y)
{
    if (x==-1 || x<y) x=y;
}

int main()
{
    scanf("%s",s);
    n=strlen(s);
    scanf("%d",&k);
    memset(forbid,false,sizeof(forbid));
    for (int i=0;i<k;++i){
        char op[5];
        scanf("%s",op);
        int a=op[0]-'a',b=op[1]-'a';
        forbid[a][b]=forbid[b][a]=true;
    }
    
    memset(next,-1,sizeof(next));
    for (int i=n-1;i>=0;--i){
        memcpy(next[i],next[i+1],sizeof(next[i]));
        next[i][s[i]-'a']=i;
    }
    
    memset(f,-1,sizeof(f));
    for (int i=0;i<n;++i){
        f[i]=max(f[i],1);
        for (int j=0;j<26;++j)if (!forbid[s[i]-'a'][j] && next[i+1][j]!=-1){
            Update(f[next[i+1][j]],f[i]+1);
        }
    }
    
    int ans=-1;
    for (int i=0;i<=n;++i)if (f[i]!=-1) Update(ans,f[i]);
    
    printf("%d\n",n-ans);
    
    return 0;
}