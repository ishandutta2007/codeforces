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

string s="UDLR";

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

inline void add(vector<LL> &a,LL x)
{
    a.PB(x);
}

inline void process(vector<LL> &a,vector< pair<LL,LL> > &inter)
{
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    
    for (int i=0;i<a.size();++i){
        inter.PB(MP(a[i],a[i]));
        if (i+1<a.size() && a[i]+1<=a[i+1]-1){
            inter.PB(MP(a[i]+1,a[i+1]-1));
        }
    }
}


const LL inf    =   1000000000000000LL;

vector< vector<int> > mark;

inline int getIndex(vector< pair<LL,LL> > &inter,LL x)
{
    return (upper_bound(inter.begin(),inter.end(),MP(x,inf+1))-inter.begin())-1;
}

inline void flood(int x,int y)
{
    if (x<0 || x>=mark.size() || y<0 || y>=mark[x].size() || mark[x][y]!=0) return;
    mark[x][y]=1;
    for (int k=0;k<4;++k){
        flood(x+dx[k],y+dy[k]);
    }
}


const int maxn  =   1005;

struct node
{
    int sx,sy,tx,ty;
}edge[maxn];

int main()
{
    vector<LL> bakx,baky;
    int n;
    scanf("%d",&n);
    LL x=0,y=0;
    add(bakx,inf);
    add(bakx,-inf);
    add(baky,-inf);
    add(baky,inf);
    
    for (int i=0;i<n;++i){
        char dir[10];
        int d;
        scanf("%s%d",dir,&d);
        int k=s.find(dir[0]);
        edge[i].sx=x;
        edge[i].sy=y;
        x+=dx[k]*d;
        y+=dy[k]*d;
        edge[i].tx=x;
        edge[i].ty=y;
    }
    
    for (int i=0;i<n;++i){
        add(bakx,edge[i].sx);add(bakx,edge[i].tx);
        add(baky,edge[i].sy);add(baky,edge[i].ty);
    }
    
    vector< pair<LL,LL> > interx,intery;
    process(bakx,interx);
    process(baky,intery);
    
    mark.resize(interx.size());
    for (int i=0;i<interx.size();++i){
        mark[i].resize(intery.size());
        for (int j=0;j<intery.size();++j){
            mark[i][j]=0;
        }
    }
    
    for (int i=0;i<n;++i){
        int x1=getIndex(interx,edge[i].sx),x2=getIndex(interx,edge[i].tx);
        int y1=getIndex(intery,edge[i].sy),y2=getIndex(intery,edge[i].ty);
        if (x1>x2) swap(x1,x2);
        if (y1>y2) swap(y1,y2);
        for (int x=x1;x<=x2;++x){
            for (int y=y1;y<=y2;++y){
                mark[x][y]=-1;
            }
        }
    }
    /*{
        for (int i=0;i<mark.size();++i){
            for (int j=0;j<mark[i].size();++j){
                printf("%d ",mark[i][j]);
            }
            puts("");
        }
    }*/
    flood(0,0);
    
    LL ans=0;
    for (int i=0;i<interx.size();++i){
        LL lx=interx[i].second-interx[i].first+1;
        for (int j=0;j<intery.size();++j){
            if (mark[i][j]==1) continue;
//printf("%I64d %I64d %I64d %I64d\n",interx[i].first,interx[i].second,intery[j].first,intery[j].second);
            LL ly=intery[j].second-intery[j].first+1;
            ans+=lx*ly;
        }
    }
    cout << ans << endl;
    return 0;
}