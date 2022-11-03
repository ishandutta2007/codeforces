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

const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
vector<char> track;
map<pair<int,PII> ,int> hash;
char s[100][100];
int n,m,step;

inline pair<int,PII> next(const pair<int,PII> &cur)
{
    int x=cur.first/m,y=cur.first%m;
    int dp=cur.second.first;
    int cp=(dp+cur.second.second+4)&3;
    while (1){
        int tx=x+dx[dp],ty=y+dy[dp];
        if (tx>=0 && ty>=0 && tx<n && ty<m && s[tx][ty]==s[x][y]){
            x=tx;y=ty;
        }else break;
    }
    while (1){
        int tx=x+dx[cp],ty=y+dy[cp];
        if (tx>=0 && ty>=0 && tx<n && ty<m && s[tx][ty]==s[x][y]){
            x=tx;y=ty;
        }else break;
    }
    int tx=x+dx[dp],ty=y+dy[dp];
    if (tx>=0 && ty>=0 && tx<n && ty<m && s[tx][ty]>'0'){
        return MP(tx*m+ty, cur.second);
    }
    cp=cur.second.second;
    if (cp==-1) cp=1;
    else{
        dp=(dp+1)&3;
        cp=-1;
    }
    return MP(cur.first,MP(dp,cp));
}

int main()
{
    scanf("%d%d",&n,&step);
    for (int i=0;i<n;++i) scanf("%s",s[i]);
    m=strlen(s[0]);
    
    pair<int,PII> cur=MP( 0, MP(1, -1) );
    
    track.clear();
    hash.clear();
    int st=0,len=0;
    while (1){
        //printf("%d %d %d\n",cur.first,cur.second.first,cur.second.second);
        if (hash.count(cur)){
            st=hash[cur];
            len=track.size()-st;
            break;
        }
        hash[cur]=track.size();
        track.PB(s[cur.first/m][cur.first%m]);
        cur=next(cur);
    }
    if (step<st) printf("%c\n",track[step]);
    else printf("%c\n",track[st+(step-st)%len]);
    
    return 0;
}