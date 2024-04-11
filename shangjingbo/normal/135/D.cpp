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

const int maxn  =   1005;
const int dx[]  =   {0,1,0,-1,1,1,-1,-1};
const int dy[]  =   {1,0,-1,0,1,-1,1,-1};

bool out;
char s[maxn][maxn];
int n,m,mark[maxn][maxn],stamp;
vector< pair<int,int> > cycle;
vector< pair<int,int> > next[maxn][maxn];

inline void flood(int x,int y)
{
    s[x][y]='2';
    for (int k=0;k<8;++k){
        int tx=x+dx[k],ty=y+dy[k];
        if (tx>=0 && ty>=0 && tx<n && ty<m){
            if (s[tx][ty]=='0') flood(tx,ty);
        }else{
            out=true;
        }
    }
    
    for (int k=0;k<8;++k){
        int tx=x+dx[k],ty=y+dy[k];
        if (tx>=0 && ty>=0 && tx<n && ty<m){
            if (s[tx][ty]=='1'){
                if (mark[tx][ty]!=stamp){
                    mark[tx][ty]=stamp;
                    cycle.PB(MP(tx,ty));
                }
            }
        }
    }
}

inline bool check()
{
    if (!cycle.size()) return false;
    
//printf("%d\n",(int)cycle.size());
    
    for (int i=0;i<cycle.size();++i){
        int x=cycle[i].first,y=cycle[i].second;
        next[x][y].clear();
        for (int k=0;k<4;++k){
            int tx=x+dx[k],ty=y+dy[k];
            if (tx>=0 && ty>=0 && tx<n && ty<m){
                if (s[tx][ty]=='1' && mark[tx][ty]==stamp){
                    next[x][y].PB(MP(tx,ty));
                }
            }
        }
        if (next[x][y].size()!=2) return false;
    }
    
    int x=cycle[0].first,y=cycle[0].second,fx=-1,fy=-1,cnt=0;
    do{
        ++cnt;
        for (int i=0;i<next[x][y].size();++i)
        if (next[x][y][i]!=MP(fx,fy)){
            fx=x;fy=y;
            PII cur=next[x][y][i];
            x=cur.first;
            y=cur.second;
            break;
        }
    }while (x!=cycle[0].first || y!=cycle[0].second);
    
    return cnt==cycle.size();
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i){
        scanf("%s",s[i]);
    }
    
    memset(mark,-1,sizeof(mark));
    stamp=0;
    int ans=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j){
            if (s[i][j]=='0'){
                ++stamp;
                out=false;
                cycle.clear();
                flood(i,j);
                
                if (!out && check()){
                    ans=max(ans,(int)cycle.size());
                }
            }
        }
    for (int i=0;i+1<n;++i)
        for (int j=0;j+1<m;++j)
        if (s[i][j]=='1' && s[i+1][j]=='1' && s[i][j+1]=='1' && s[i+1][j+1]=='1')
            ans=max(ans,4);
    printf("%d\n",ans);
    
    return 0;
}