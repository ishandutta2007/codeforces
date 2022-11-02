// TwT514 {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

#define N 1010
int n,m,a[N][N];
void input() {
    RII(n,m);
    REP1(i,1,n) REP1(j,1,m) RI(a[i][j]);
}

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int deg[N][N],sx,sy;
VI cand;
void build() {
    REP1(i,1,n) REP1(j,1,m) REP(k,4) deg[i][j]+=a[i+dx[k]][j+dy[k]];
    REP1(i,1,n) REP1(j,1,m) if ( a[i][j] && deg[i][j]%2==1 ) sx=i,sy=j;
    if ( !sx ) {
        REP1(i,1,n) REP1(j,1,m) if ( a[i][j] ) {
            sx=i;
            sy=j;
            i=j=n+1;
        }
    }
    REP(k,4) if ( a[sx+dx[k]][sy+dy[k]] ) {
        int l=0;
        while ( a[sx+l*dx[k]][sy+l*dy[k]] ) l++;
        for ( int i=2; i<l; i++ ) if ( (l-1)%i==0 ) cand.PB(i);
        break;
    }
}

int cov[N][N],vis[N][N],ucs;
bool all( int x1, int y1, int x2, int y2 ) {
    int _dx=(x1<x2)-(x1>x2);
    int _dy=(y1<y2)-(y1>y2);
    while ( x1!=x2 || y1!=y2 ) {
        if ( !a[x1][y1] ) return 0;
        x1+=_dx;
        y1+=_dy;
    }
    return a[x1][y1];
}
bool set_cov( int x1, int y1, int x2, int y2 ) {
    bool xd=1;
    int _dx=(x1<x2)-(x1>x2);
    int _dy=(y1<y2)-(y1>y2);
    while ( x1!=x2 || y1!=y2 ) {
        xd&=(cov[x1][y1]==ucs);
        cov[x1][y1]=ucs;
        x1+=_dx;
        y1+=_dy;
    }
    xd&=(cov[x1][y1]==ucs);
    cov[x1][y1]=ucs;
    return !xd;
}
bool out( int x, int y ) { return x<1 || x>n || y<1 || y>m; }
void dfs( int x, int y, int l ) {
    vis[x][y]=ucs;
    REP(i,4) {
        int nx=x+l*dx[i];
        int ny=y+l*dy[i];
        if ( out(nx,ny) || !all(x,y,nx,ny) || !set_cov(x,y,nx,ny) ) continue;
        dfs(nx,ny,l);
    }
}
bool check( int l ) {
    ucs++;
    dfs(sx,sy,l);
    REP1(i,1,n) REP1(j,1,m) if ( a[i][j] && cov[i][j]!=ucs ) return 0;
    int odd=0;
    REP1(i,1,n) REP1(j,1,m) if ( vis[i][j]==ucs ) {
        int dg=0;
        REP(k,4) {
            int x=i+l*dx[k];
            int y=j+l*dy[k];
            if ( out(x,y) || !all(i,j,x,y) || vis[x][y]!=ucs ) continue;
            dg++;
        }
        if ( dg%2==1 ) odd++;
    }
    if ( odd!=0 && odd!=2 ) return 0;
    return 1;
}

void solve() {
    VI sol;
    FOR(it,cand) if ( check(*it) ) sol.PB(*it);
    if ( sol.empty() ) puts("-1");
    else REP(i,SZ(sol)) printf("%d%c",sol[i],i+1==SZ(sol)?'\n':' ');
}

int main() {
    input();
    build();
    solve();
    return 0;
}